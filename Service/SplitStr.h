#ifndef SPLITSTR_H
#define SPLITSTR_H
#include <string>
#include <vector>
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
namespace mysql=sqlpp::mysql;
std::vector<std::string> split(std::string str,std::string pattern)
{
  std::string::size_type pos;
  std::vector<std::string> result;
  str+=pattern;//扩展字符串以方便操作
  int size=str.size();
 
  for(int i=0; i<size; i++)
  {
    pos=str.find(pattern,i);
    if(pos<size)
    {
      std::string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+pattern.size()-1;
    }
  }
  return result;
}

// class DBContextFactory{
// public:
//     static mysql::connection& Instance(){
//       auto config=std::make_shared<mysql::connection_config>();
//       config->password="mypassword";
//       config->user="root";
//       config->debug=true;
//       config->database="PoppopDatabase";
//       static mysql::connection db(config);
//       return db;
//     }
// };



#endif