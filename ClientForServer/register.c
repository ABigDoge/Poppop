#include "socket.h"

int Register(const struct User data){

	if (send(fd, "register", MAX_BUF, 0) <= 0)
		return 0;
	
  	// 发用户名
	if (send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;

	// 接收是否匹配
	char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
	if(len <= 0)
        return 0;
	
	struct Notice notice;
    memcpy(&notice, buf, len);

    return notice.flag;
}