#ifndef MessageDTO_H
#define MessageDTO_H

//存储聊天记录信息
class MessageDTO{    
public:
	int Sender_ID;   //消息发送者
	String Context;     //消息内容
	int Type;       //消息类型
	DateTime Time;  //发送时间
	int Group_ID;    //发送的消息所属群组
};

#endif