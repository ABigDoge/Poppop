#ifndef GroupService_h
#define GroupService_h
#include"GroupDTO.h"
#include<vector>
using namespace std;
class UserService{
	public:
		bool Add(GroupDTO groupDTO);
		bool Edit(GroupDTO groupDTO);
		bool Del(GroupDTO groupDTO);
		int GetGroupList(vector<GroupDTO>& groupList, UserDTO obj);
};	
#endif