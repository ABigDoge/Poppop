#ifndef MessageService_h
#define MessageService_h
#include"MessageDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include<vector>
using namespace std;
namespace mysql=sqlpp::mysql;
//关于聊天消息的服务
class MessageService{
	public:
		//增添消息
		static bool Add(MessageDTO messageDTO);
		//删除消息（撤回？）
		static bool Del(MessageDTO messageDTO);
		//获取该群组里的消息列表，其中id是group的id，返回结果数
		static int GetMessageList(vector<MessageDTO>& messageList, int id);
};	
#endif