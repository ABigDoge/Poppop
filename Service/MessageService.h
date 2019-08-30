#ifndef MessageService_h
#define MessageService_h
#include"MessageDTO.h"
#include<vector>
using namespace std;
class MessageService{
	public:
		bool Add(MessageDTO messageDTO);
		bool Del(MessageDTO messageDTO);
		int GetMessageList(vector<MessageDTO>& messageList, int id);
};	
#endif