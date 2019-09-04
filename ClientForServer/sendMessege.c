#include "socket.h"

<<<<<<< HEAD
int SendMessege(struct MessagePrivate* a)
=======
int SendMessegePrivate(struct MessagePrivate a)
>>>>>>> b2045496e3e159bcc2806c1bbac4ca530612cdfa
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
