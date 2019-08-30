#ifndef GroupService_h
#define GroupService_h
#include"GroupDTO.h"
#include<vector>
using namespace std;

//提供关于好友分组的服务
//注意区分group:好友列表里给好友的分组 groupchat:群聊
class GroupService{
	public:
		//添加好友分组
		bool Add(GroupDTO groupDTO);
		//编辑分组，比如改名
		bool Edit(GroupDTO groupDTO);
		//删除分组
		bool Del(GroupDTO groupDTO);
		//得到某个用户的好友分组列表，即他给好友设了哪些分组
		int GetGroupList(vector<GroupDTO>& groupList, UserDTO obj);
};	
#endif