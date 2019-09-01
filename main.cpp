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

#include "DBContextFactory.h"
#include "Poppop.h"
#include "string"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>

#include <cassert>
#include <iostream>
#include <vector>

SQLPP_ALIAS_PROVIDER(left)
SQLPP_ALIAS_PROVIDER(right)

namespace mysql = sqlpp::mysql;
int main()
{
  try
  {
    mysql::connection db(config);
  }
  catch (const sqlpp::exception& e)
  {
    std::cerr << "For testing, you'll need to create a database sqlpp_mysql for user root (no password)" << std::endl;
    std::cerr << e.what() << std::endl;
    return 1;
  }
  try
  {
    mysql::connection db(config);
    const auto tab = User{};
    db(insert_into(tab).set(tab.UserName="wlj"));
    db(insert_into(tab).set(tab.UserName="lsy"));
    db(insert_into(tab).set(tab.UserName="hhh"));
    db(update(tab).set(tab.DepartmentName="BITCS").where(tab.UserName.in(sqlpp::value_list(std::vector<std::string>{"wlj","123"}))));
    db(remove_from(tab).where(tab.UserName=="hhh"));

    for (const auto& row : db(select(all_of(tab)).from(tab).unconditionally()))
    {
      std::cerr << __LINE__ << " row.Name: " << row.UserName << "DeptName"<<row.DepartmentName<<std::endl;
    }



  // }
  try{
    mysql::global_library_init();
    const auto tab = User{};
    db(insert_into(tab).set(tab.UserName="nmdwsm"));
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }
}
