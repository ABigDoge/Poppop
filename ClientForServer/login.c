#include "socket.h"

int Login(int id, const char* password){
    char buf[MAX_BUF + 1];
    char s_id[MAX_BUF + 1];
    
  	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "login");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

    // 获取发送消息
    sprintf(s_id, "%d" , id);
    bzero(buf, MAX_BUF + 1);
    strcpy(buf, s_id);
    strcat(buf, " ");
    strcat(buf, password);

	// 发消息
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;
    
	// 接收是否匹配
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    if(strcmp(buf, "1") == 0)
        return 1;
    
    return 0;
}