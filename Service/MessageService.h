#ifndef MessageService_h
#define MessageService_h
#include"MessageDTO.h"
#include<vector>
using namespace std;
public class MessageService{
	public bool Add(MessageDTO messageDTO);
	public bool Del(MessageDTO messageDTO);
	public int GetMessageList(vector<MessageDTO>& messageList, int id);
};	
#endif