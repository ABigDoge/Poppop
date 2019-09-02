/*
 * Copyright (c) 2013 - 2016, Roland Bock
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Service.h"
#include "DTO.h"
//#include"SplitStr.h"
#include "DBContextFactory.h"
#include "string"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

SQLPP_ALIAS_PROVIDER(left)
SQLPP_ALIAS_PROVIDER(right)

namespace mysql = sqlpp::mysql;
int main()
{
  try{
    mysql::global_library_init();
    //以下为部分功能测试
    //UserService::Add 测试成功
    UserDTO userDTO;
    userDTO.Name="wlj";
    userDTO.PassWord="hhh";
    UserService::Add(userDTO); 
    int newid1, newid2;
    newid1 = userDTO.ID;
    cout << "newid1:  " << userDTO.ID << endl;

    UserDTO userDTO2;
    userDTO2.Name="hsx";
    userDTO2.PassWord="www";
    UserService::Add(userDTO2); 
    newid2 = userDTO2.ID;
    cout << "newid2:  " << userDTO2.ID << endl;

    //UserService::Edit 测试成功
    userDTO.Name = "lsy";
    UserService::Edit(userDTO);

    //UserService::GetUserList 测试成功
    vector<UserDTO> user_vec;
    UserSearchDTO user_searchDTO;
    user_searchDTO.ID = newid1;
    int usernum;
    usernum = UserService::GetUserList(user_vec, user_searchDTO);
    for(int i = 0; i < usernum; i++)
    {
      cout << "ID: " << user_vec[i].ID << "  name: "<< user_vec[i].Name 
        << "   password: " << user_vec[i].PassWord << endl;
    }
    
    //UserService::SelectedByID 测试成功
    userDTO = UserService::SelectedByID(newid1);
    for(int i = 0; i < usernum; i++)
    {
      cout << "ID: " << userDTO.ID << "  name: "<< userDTO.Name 
        << "   password: " << userDTO.PassWord << endl;
    }

    //GroupService::Add 成功
    GroupDTO groupDTO;
    groupDTO.Name = "默认分组";
    groupDTO.Owner_ID = newid1;
    GroupService::Add(groupDTO);
    cout << "new groupid: " << groupDTO.ID << endl;
    int groupid = groupDTO.ID;

    //FriendService::Add 成功
    FriendDTO friendDTO;
    friendDTO.This_ID = newid1;
    friendDTO.That_ID = newid2;
    friendDTO.Group_ID = groupid;
    FriendService::Add(friendDTO);
    cout << friendDTO.That_ID << " is a friend of " << friendDTO.This_ID << " in group " 
        << friendDTO.Group_ID << endl;

  }
  catch (const sqlpp::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  
}
