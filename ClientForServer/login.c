#include "socket.h"

extern int Login(const struct Login data){

    if (send(fd, "login", MAX_BUF, 0) <= 0)
		return 0;

    // 发数据
    if(send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;

	char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
	if(len <= 0)
        return 0;
	
	struct Notice new_data;
    memcpy(&new_data, buf, len);

    return new_data.flag;
}