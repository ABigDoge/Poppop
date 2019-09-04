#include "socket.h"

int SendMessegePublic(struct MessagePublic* a)
{
    // 发命令
	if(send(fd, "sendgm",MAX_BUF, 0) <= 0)
		return 0;
    
	// 发消息
	if (send(fd, (char*)& a, sizeof(a), 0) <= 0)
		return 0;
    else
    	return 1;
}
