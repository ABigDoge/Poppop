#include <iostream>
#include "GroupChatService.h"
#include "UserService.h"
#include "DTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include"MyTable.h"
#include"SplitStr.h"
using namespace std;
namespace mysql=sqlpp::mysql;

bool GroupChatService::Add(GroupChatDTO groupChatDTO, mysql::connection db)
{
	const auto tab=GroupChat{};
    db(insert_into(tab).set(
        tab.GroupChatName = groupChatDTO.Name,
        tab.ImagePath = groupChatDTO.Image_Path,
        tab.MemberIDList = groupChatDTO.Member_ID_List,
        tab.IsDelete = 0
     ));
}

bool GroupChatService::Edit(GroupChatDTO groupChatDTO, mysql::connection db)
{
    const auto tab=GroupChat{};
    db(update(tab).set(
        tab.GroupChatName = groupChatDTO.Name,
        tab.ImagePath = groupChatDTO.Image_Path,
        tab.MemberIDList = groupChatDTO.Member_ID_List
    ).where(tab.ID==groupChatDTO.ID ));
}

bool Del(int ID, mysql::connection db)
{
    const auto tab=GroupChat{};
    db(update(tab).set(tab.IsDelete=1).where(tab.ID==ID));
}

GroupChatDTO GroupChatService::SelectedByID(int id, mysql::connection db)
{
    const auto tab=GroupChat{};
    auto result=db(select(all_of(tab)).from(tab).where(tab.ID==id));
    GroupChatDTO groupchatDTO = new GroupChatDTO();
    if(!result.empty){
        const auto& row = result.front();
        groupchatDTO.ID = row.ID;
        groupchatDTO.Name = row.GroupChatName;
        groupchatDTO.Image_Path = row.ImagePath;
        groupchatDTO.Member_ID_List = row.MemberIDList;
    }
    return groupchatDTO;
}

int GroupChatService::GetGroupMember(vector<UserDTO>& userlist, int id, mysql::connection db)
{
    const auto tab=GroupChat{};
    auto result=db(select(all_of(tab)).from(tab).where(tab.ID==id));
    if(!result.empty){
        const auto& row = result.front();
        vector<string> memberidlist = split(row.MemberIDList, ",");
        for(int i = 0; i < memberidlist.size(); i++)
        {
            userlist.push_back(UserService::SelectedByID(atoi(memberidlist[i].c_str()), db));
        }
    }
    
    return userlist.size();
}

bool UserInGroupChat(int userId, int id, mysql::connection db)
{
    const auto tab=GroupChat{};
    auto result=db(select(all_of(tab)).from(tab).where(tab.ID==id));
    string userIdStr = to_string(userId);
    if(!result.empty){
        const auto& row = result.front();
        vector<string> memberidlist = split(row.MemberIDList, ",");
        for(int i = 0; i < memberidlist.size(); i++)
        {
            if(userIdStr == memberidlist[i])
                return true;
        }
        return false;
    }
}