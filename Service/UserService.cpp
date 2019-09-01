#include <iostream>
#include "UserService.h"
#include "DTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "DBContextFactory.h"
#include"MyTable.h"
namespace mysql=sqlpp::mysql;
bool UserService::Add(UserDTO userDTO){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    db(insert_into(tab).set(
        tab.UserName=userDTO.Name,
        tab.PassWord=userDTO.PassWord,
        tab.Sex=userDTO.Sex,
        tab.Motto=userDTO.Motto,
        tab.ImagePath=userDTO.Image,
        tab.DepartmentName=userDTO.Department_Name,
        tab.IsDelete=0));
    return true;
}
bool UserService::Edit(UserDTO userDTO){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    db(update(tab).set(tab.UserName=userDTO.Name,
    tab.PassWord=userDTO.PassWord,tab.Sex=userDTO.Sex,
    tab.Motto=userDTO.Motto,
    tab.DepartmentName=userDTO.Department_Name,
    tab.ImagePath=userDTO.Image).where(tab.ID==userDTO.ID));
}

bool UserService::Del(int id){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    db(update(tab).set(tab.IsDelete=1).where(tab.ID==id));
}

UserDTO UserService::SelectedByID(int id){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    auto result=db(select(all_of(tab)).from(tab).where(tab.ID==id));
    UserDTO userDTO;
    if(!result.empty()){
        const auto& row = result.front();
        userDTO.ID=row.ID;
        userDTO.Name=row.UserName;
        userDTO.PassWord=row.PassWord;
        userDTO.Sex=row.Sex;
        userDTO.Image=row.ImagePath;
        userDTO.Department_Name=row.DepartmentName;
        userDTO.Motto=row.Motto;
    }
    return userDTO;
}

int UserService::GetUserList(vector<UserDTO>& userList, UserSearchDTO dto){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    if(dto.ID!=0){
        for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.ID==dto.ID)))
        {
            UserDTO userDTO;
            userDTO.ID=row.ID;
            userDTO.Name=row.UserName;
            userDTO.PassWord=row.PassWord;
            userDTO.Sex=row.Sex;
            userDTO.Image=row.ImagePath;
            userDTO.Department_Name=row.DepartmentName;
            userDTO.Motto=row.Motto;
            userList.push_back(userDTO);
        }
    }
    return userList.size();
}

bool UserService::PutUserOnline(int id, int client_fd,int* count){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    db(update(tab).set(tab.IsOnline=1,tab.IPAddr=client_fd).where(tab.ID==id));
}
		
//下线
bool UserService::PutUserOffline(int ID){
    const auto tab=User{};
    mysql::connection &db=DBContextFactory::Instance();
    db(update(tab).set(tab.IsOnline=0).where(tab.ID==ID));
}
