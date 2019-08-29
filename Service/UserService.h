#ifndef UserService_h
#define UserService_h
#include<DTO/UserDTO>
#include<vector>
using namespace std;
public class UserService{
	public bool Add(UserDTO userDTO);
	public bool Edit(UserDTO userDTO);
	public bool Del(UserDTO userDTO);
	public UserDTO SelectedByID(int id);
	public int GetUserList(vector<UserDTO>& userList, UserSearchDTO obj);
};	
#endif
