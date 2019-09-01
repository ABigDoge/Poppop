#include <iostream>
#include "FriendService.h"
#include "FriendDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "MyTable.h"
namespace mysql=sqlpp::mysql;
bool FriendService::Add(FriendDTO friendDTO,mysql::connection db){//添加好友
    const auto tab=Friend{};
    auto result=db(select(all_of(tab)).from(tab).where(tab.UserOneID==friendDTO.That_ID&&tab.UserTwoID==friendDTO.This_ID));
    if(!result.empty)
        return false;
    try{
        db(insert_into(tab).set(
            tab.GroupOneID=friendDTO.This_ID;
            tab.GroupTwoID=friendDTO.That_ID;
            tab.GroupOneID=friendDTO.Group_ID;
        ));
        return true;
    }
    catch(exception& e){
        return false;
    }
}
bool FriendService::Del(FriendDTO friendDTO,mysql::connection db){	//删除好友
    const auto tab=Friend{};
    try{
        db(update(tab).set(tab.IsDelete=1).where((tab.UserOneID==friendDTO.This_ID&&tab.UserTwoID==friendDTO.That_ID)||(tab.UserOneID==friendDTO.That_ID&&tab.UserTwoID==friendDTO.This_ID));
        return true;
    }
    catch(exception& e){
        return false;
    }
}
bool FriendService::Edit(FriendDTO friendDTO,mysql::connection db){//编辑好友信息（分组）
    const auto tab=Friend{};
    auto result=db(select(all_of(tab)).from(tab).where(tab.UserOneID==friendDTO.This_ID&&tab.UserTwoID==friendDTO.That_ID));
    if(!result.empty){
        const auto& row = result.front();
        db(update(tab).set(tab.GroupOneID=friendDTO.Group_ID));
        return true;
    }
    else{
        return false;
    }
}