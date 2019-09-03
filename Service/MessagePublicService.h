#ifndef MessagePublicService_h
#define MessagePublicService_h
#include"MessagePublicDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include<vector>
using namespace std;
namespace mysql=sqlpp::mysql;
//关于聊天消息的服务
class MessagePublicService{
	public:
		//增添消息
		static bool Add(MessagePublicDTO messagePublicDTO);
		//删除消息（撤回？）
		static bool Del(MessagePublicDTO messagePublicDTO);
		//获取该群组里的消息列表，其中id是group的id，返回结果数
		static int GetMessagePublicList(vector<MessagePublicDTO>& messageList, 
				int group_id);
};	
#endif