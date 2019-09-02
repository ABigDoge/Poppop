#ifndef MessagePrivateService_h
#define MessagePrivateService_h
#include"MessagePrivateDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include<vector>
using namespace std;
namespace mysql=sqlpp::mysql;
//关于聊天消息的服务
class MessagePrivateService{
	public:
		//增添消息
		static bool Add(MessagePrivateDTO messagePrivateDTO);
		//删除消息（撤回？）
		static bool Del(MessagePrivateDTO messagePrivateDTO);
		//获取该群组里的消息列表，其中id是group的id，返回结果数
		static int GetMessagePrivateList(vector<MessagePrivateDTO>& messageList, 
				int sender_id, int recv_id);
};	
#endif