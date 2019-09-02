#include <iostream>
#include "FriendService.h"
#include "FriendDTO.h"
#include "UserDTO.h"
#include "DBContextFactory.h"
#include "UserService.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "MyTable.h"
namespace mysql=sqlpp::mysql;
bool FriendService::Add(FriendDTO friendDTO){//添加好友
    const auto tab=Friend{};
    mysql::connection &db=DBContextFactory::Instance();
    auto result=db(select(all_of(tab)).from(tab).where(tab.ThisID==friendDTO.That_ID&&tab.ThatID==friendDTO.This_ID));
    if(!result.empty())
        return false;
    db(insert_into(tab).set(
        tab.ThisID=friendDTO.This_ID,
        tab.ThatID=friendDTO.That_ID,
        tab.GroupID=friendDTO.Group_ID,
        tab.IsDelete=0
    ));
    return true;
}
bool FriendService::Del(FriendDTO friendDTO){	//删除好友
    const auto tab=Friend{};
    mysql::connection &db=DBContextFactory::Instance();
    db(update(tab).set(tab.IsDelete=1).where(((tab.ThisID==friendDTO.This_ID&&tab.ThatID==friendDTO.That_ID)||
                    (tab.ThisID==friendDTO.That_ID&&tab.ThatID==friendDTO.This_ID))&&tab.IsDelete==0));
    return true;
}
bool FriendService::Edit(FriendDTO friendDTO){//编辑好友信息（分组）
    const auto tab=Friend{};
    mysql::connection &db=DBContextFactory::Instance();
    auto result=db(select(all_of(tab)).from(tab).where(tab.ThisID==friendDTO.This_ID&&tab.ThatID==friendDTO.That_ID));

    if(!result.empty()){
        db(update(tab).set(tab.GroupID=friendDTO.Group_ID).where(tab.ThisID==friendDTO.This_ID&&tab.ThatID==friendDTO.That_ID));
        return true;
    }
    else{
        return false;
    }
}

bool FriendService::IsFriend(int id1, int id2)
{
    const auto tab=Friend{};
    mysql::connection &db=DBContextFactory::Instance();
    auto result=db(select(all_of(tab)).from(tab).where(tab.ThisID==id1&&tab.ThatID==id2&&tab.IsDelete==0));
    if(!result.empty())
        return true;
    return false;
}

bool FriendService::GetFriendList(vector<UserDTO> &friendlist, int id)
{
    const auto tab=Friend{};
    mysql::connection &db=DBContextFactory::Instance();
//    auto result=db(select(all_of(tab)).from(tab).where(tab.ThisID==id and tab.IsDelete==0));
    if(id!=0)
    {
        for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.ThisID==id and tab.IsDelete==0)))
        {
            friendlist.push_back(UserService::SelectedByID(row.ThatID));
        }
        return true;
    }
    return false;
}