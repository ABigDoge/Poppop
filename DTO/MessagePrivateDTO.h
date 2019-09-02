#ifndef MessagePrivateDTO_H
#define MessagePrivateDTO_H
#include <string>
using namespace std;
//存储聊天记录信息
class MessagePrivateDTO{    
public:
	int Sender_ID;   //消息发送者
	int Recver_ID;   //消息发送者
	string Context;     //消息内容
	int Type;       //消息类型
	string Time;  //发送时间
//	int Group_ID;    //发送的消息所属群组
};

#endif
