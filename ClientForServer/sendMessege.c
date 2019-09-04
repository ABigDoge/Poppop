#include "socket.h"

int SendMessege(struct MessagePrivate* a)
{
    char buf[MAX_BUF + 1];

    // 发命令
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "sendgm", 30);
	if(send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;
    
	// 发消息
	if (send(fd, (char*)& a, sizejanof(a), 0) <= 0)
		return 0;
    
    return 1;
}
