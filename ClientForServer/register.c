#include "socket.h"

int Register(const char* usrname, const char* password){
    char buf[MAX_BUF + 1];
    
  	// 发用户名
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, usrname);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发密码
    bzero(buf, MAX_BUF + 1);
	strcpy(buf, password);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;
    
	// 接收是否匹配
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    if(len <= 0)
        return 0;

    int id = (int)atof(buf);    
    return id;
}
