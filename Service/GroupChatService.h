#ifndef GroupChatService_h
#define GroupChatService_h
#include<vector>
#include"GroupChatDTO.h"
using namespace std;
class GroupChatService{
	public:
		bool Add(GroupChatDTO groupChatDTO);
		bool Edit(GroupChatDTO groupChatDTO);
		GroupChatDTO SelectedByID(int id);
		int GetGroupChatList(vector<GroupChatDTO>& groupChatList,GroupChatSearchDTO dto);
	
};
#endif
