#ifndef UserService_h
#define UserService_h
#include"DTO.h"
#include<vector>
#include<iostream>
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
using namespace std;
namespace mysql = sqlpp::mysql;
//关于用户的服务
class UserService{
	public:
		//添加新用户
		static bool Add(UserDTO userDTO,mysql::connection db);
		//修改用户信息
		static bool Edit(UserDTO userDTO,mysql::connection db);
		//删除用户，数据库中并不删除，只是做一个标记不再显示
		static bool Del(int id,mysql::connection db);
		//按id查找用户
		static UserDTO SelectedByID(int id, mysql::connection db);
		//获取用户列表，比如提供一个词，找到名字里带这个词的所有用户，返回结果数
		static int GetUserList(vector<UserDTO>& userList, UserSearchDTO dto,mysql::connection db);
		//client_fd是该用户现在上线用的IP地址，count是他待接受的消息数
		// bool PutUserOnline(int id, int client_fd,int* count);
		// //下线
		// bool PutUserOffline(int ID);
};
#endif
