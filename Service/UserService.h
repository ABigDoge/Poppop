#ifndef UserService_h
#define UserService_h
#include"UserDTO.h"
#include"UserSearchDTO.h"
#include<vector>
#include<iostream>
using namespace std;

//关于用户的服务
class UserService{
	public:
		//添加新用户
		bool Add(UserDTO userDTO);
		//修改用户信息
		bool Edit(UserDTO userDTO);
		//删除用户，数据库中并不删除，只是做一个标记不再显示
		bool Del(UserDTO userDTO);
		//按id查找用户
		UserDTO SelectedByID(int id);
		//获取用户列表，比如提供一个词，找到名字里带这个词的所有用户，返回结果数
		int GetUserList(vector<UserDTO>& userList, UserSearchDTO dto);
		//client_fd是该用户现在上线用的IP地址，count是他待接受的消息数
		bool PutUserOnline(int id, int client_fd,int* count);
		//下线
		bool PutUserOffline(int ID);
};
#endif
