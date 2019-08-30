#ifndef GroupChatService_h
#define GroupChatService_h
#include<vector>
#include"GroupChatDTO.h"
using namespace std;

//提供关于群聊的服务
class GroupChatService{
	public:
		//建立群组
		bool Add(GroupChatDTO groupChatDTO);
		//编辑群组信息
		bool Edit(GroupChatDTO groupChatDTO);
		//通过群号查询群组
		GroupChatDTO SelectedByID(int id);
		//通过名字查询群组，返回结果数
		int GetGroupChatList(vector<GroupChatDTO>& groupChatList,GroupChatSearchDTO dto);
		//查询某个群组中的成员
		int GetGroupMember(vector<UserDTO>& userlist, GroupChatDTO groupchatdto);
		//判断成员是否在群组中
		bool UserInGroupChat(UserDTO userdto, GroupChatDTO groupchatdto);
};
#endif
