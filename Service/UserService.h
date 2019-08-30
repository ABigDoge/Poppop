#ifndef UserService_h
#define UserService_h
#include"UserDTO.h"
#include<vector>
using namespace std;
public class UserService{
	public:
		bool Add(UserDTO userDTO);
		bool Edit(UserDTO userDTO);
		bool Del(UserDTO userDTO);
		UserDTO SelectedByID(int id);
		int GetUserList(vector<UserDTO>& userList, UserSearchDTO obj);
};	
#endif
