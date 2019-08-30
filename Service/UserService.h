#ifndef UserService_h
#define UserService_h
#include"UserDTO.h"
#include<vector>
using namespace std;

//关于用户的服务
class UserService{
	public:
		//添加新用户
		bool Add(UserDTO userDTO);
		//修改用户信息
		bool Edit(UserDTO userDTO);
		//删除用户
		bool Del(UserDTO userDTO);
		//按id查找用户
		UserDTO SelectedByID(int id);
		//获取用户列表，比如提供一个词，找到名字里带这个词的所有用户
		int GetUserList(vector<UserDTO>& userList, UserSearchDTO obj);
};	
#endif
