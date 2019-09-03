#include "socket.h"
#include "StructForSocket.h"

int ApplyForFriend(int this_id, int that_id, int group_id)
{
	char buf[MAX_BUF + 1];
	
	// 发命令
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "apply", 30);
	if (send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;

	// 获取发送消息  
	struct Friend a;
	memset((char*)& test, 0, sizeof(test));
	a.This_ID = this_id;
	a.That_ID = that_id;
	a.Group_ID = group_id;

	// 发消息
	if (send(fd, (char*)& a, sizeof(a), 0) <= 0)
		return 0;

	return 1;
}