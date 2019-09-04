#ifndef DBCONTEXTFACTORY_H
#define DBCONTEXTFACTORY_H
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
namespace mysql=sqlpp::mysql;

class DBContextFactory{
public:
    static mysql::connection& Instance(){
      auto config=std::make_shared<mysql::connection_config>();
      config->password="mypassword";
      config->user="root";
      config->debug=true;
      config->database="PoppopDatabase";
      static mysql::connection db(config);
      return db;
    }
};

#endif