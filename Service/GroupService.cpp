#include <iostream>
#include "GroupService.h"
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
#include "DBContextFactory.h"
using namespace std;
namespace mysql=sqlpp::mysql;

bool GroupService::Add(GroupDTO &groupDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=_Group{};
    db(insert_into(tab).set(
        tab.GroupName = groupDTO.Name,
        tab.OwnerID = groupDTO.Owner_ID,
        tab.IsDelete = 0
     ));
    auto result = db(select(max(tab.ID)).from(tab).unconditionally());
    const auto& row = result.front();
    groupDTO.ID = row.max;
    return true;
}

bool GroupService::Edit(GroupDTO groupDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=_Group{};
    db(update(tab).set(
        tab.GroupName = groupDTO.Name,
        tab.OwnerID = groupDTO.Owner_ID,
        tab.IsDelete = 0
     ).where(tab.ID==groupDTO.ID and tab.IsDelete==0));
}

bool GroupService::Del(GroupDTO groupDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=_Group{};
    db(update(tab).set(tab.IsDelete=1).where(tab.ID==groupDTO.ID));
}

int GroupService::GetGroupList(vector<GroupDTO>& groupList, int userid)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=_Group{};
    for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.OwnerID==userid and tab.IsDelete==0)))
    {
        GroupDTO groupDTO;
        groupDTO.ID = row.ID;
        groupDTO.Name = row.GroupName;
        groupDTO.Owner_ID = row.OwnerID;
        groupList.push_back(groupDTO);
    }
    return groupList.size();
}

int GroupService::GetGroupMemberList(vector<UserDTO>&memberList,GroupSearchDTO obj)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=Friend{};
    if(obj.ID!=0)
    {
        for (const auto& row:db(select(tab.ThatID).from(tab).where(tab.GroupID==obj.ID and tab.IsDelete==0)))
        {
            memberList.push_back(UserService::SelectedByID(row.ThatID));
        }
    }
    return memberList.size();
}