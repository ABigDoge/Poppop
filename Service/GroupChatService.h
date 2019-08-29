#ifndef GroupChatService_h
#define GroupChatService_h
#include<vector>
#include<DTO/GroupChatDTO.h>
using namespace std;
public class GroupChatService{
	public bool Add(GroupChatDTO groupChatDTO);
	public bool Edit(GroupChatDTO groupChatDTO);
	public GroupChatDTO SelectedByID(int id);
	public int GetGroupChatList(vector<GroupChatDTO>& groupChatList,GroupChatSearchDTO dto);
	
};
#endif
