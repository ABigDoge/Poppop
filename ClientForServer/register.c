#include "socket.h"

int Register(const struct User data){

	if (send(fd, "register", MAX_BUF, 0) <= 0)
		return 0;
	
  	// 发送
	if (send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;

	// 接收
	char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
	if(len <= 0)
        return 0;
	
	struct User new_data;
    memcpy(&new_data, buf, len);

    return new_data.ID;
}