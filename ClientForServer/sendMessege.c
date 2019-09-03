#include "socket.h"

struct MessagePrivate 
{
	int Sender_ID;   //消息发送者
	int Recver_ID;   //消息发送者
	char Context[200];
	//以下为服务端发送消息给客户端时填写的数据
	char Time[20];
};

int SendMessege(int this_id, int that_id, const char* msg){
    char buf[MAX_BUF + 1];

    // 发命令
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "send", 30);
	if(send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;
    
    // 获取发送消息
	struct MessagePrivate a;
	memset((char*)& test, 0, sizeof(test));
	a.Sender_ID = this_id; 
	a.Recver_ID = that_id;
	memcpy(a.Context, msg, strlen(msg) + 1);
	a.Time = "";
    
	// 发消息
	if (send(fd, (char*)& a, sizeof(a), 0) <= 0)
		return 0;
    
    return 1;
}