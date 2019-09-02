#include "socket.h"

#define ID_MAX 10

int Login(int id, const char* password){
    char buf[MAX_BUF + 1];
    char s_id[ID_MAX + 1];
    
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
    
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    if(strcmp(buf, "succeed") == 0)
        return 1;
    
    return 0;
}
