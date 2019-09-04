#include "socket.h"

int SendMessegePrivate(struct MessagePrivate a)
{
    char buf[MAX_BUF + 1];

    // 发命令
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "send", 30);
	if(send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;
    
	// 发消息
	if (send(fd, (char*)& a, sizeof(a), 0) <= 0)
		return 0;
    
    return 1;
}
