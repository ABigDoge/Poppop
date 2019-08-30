#ifndef MessageService_h
#define MessageService_h
#include"MessageDTO.h"
#include<vector>
using namespace std;

//关于聊天消息的服务
class MessageService{
	public:
		//增添消息
		bool Add(MessageDTO messageDTO);
		//删除消息（撤回？）
		bool Del(MessageDTO messageDTO);
		//获取该群组里的消息列表，其中id是group的id，返回结果数
		int GetMessageList(vector<MessageDTO>& messageList, int id);
};	
#endif