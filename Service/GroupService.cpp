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
using namespace std;
namespace mysql=sqlpp::mysql;

bool GroupService::Add(GroupDTO groupDTO, mysql::connection db)
{
    const auto tab=_Group{};
    db(insert_into(tab).set(
        tab.GroupName = groupDTO.Name,
        tab.OwnerID = groupDTO.Owner_ID,
        tab.IsDelete = 0
     ));
}

bool GroupService::Edit(GroupDTO groupDTO, mysql::connection db)
{
    const auto tab=_Group{};
    db(update(tab).set(
        tab.GroupName = groupDTO.Name,
        tab.OwnerID = groupDTO.Owner_ID,
        tab.IsDelete = 0
     ).where(tab.ID==groupDTO.ID));
}

bool GroupService::Del(GroupDTO groupDTO, mysql::connection db)
{
    const auto tab=_Group{};
    db(update(tab).set(tab.IsDelete=1).where(tab.ID==groupDTO.ID));
}

int GroupService::GetGroupList(vector<GroupDTO>& groupList, int userid, mysql::connection db)
{

}

int GroupService::GetGroupMemberList(vector<UserDTO>&memberList,GroupSearchDTO obj,
									 mysql::connection db)
{
    
}