#include "socket.h"

// 被加好友返回对方信息
struct User ReplyFriend(){
    char buf[MAX_BUF + 1];
    bzero(buf, MAX_BUF);
	int len = recv(fd, buf, MAX_BUF, 0);
    struct User new_data;
    memcpy(&new_data, buf, len);
    return new_data;
}
