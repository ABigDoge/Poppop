#include "socket.h"

extern const int MAX_BUF;

int SendMessege(const char* msg){
    char buf[MAX_BUF + 1];

    // 发命令
    bzero(buf, MAX_BUF + 1);
    strcpy(buf, "send");
    if(send(fd, buf, strlen(buf), 0) <= 0)
        return 0;
    
    // 发消息
    bzero(buf, MAX_BUF + 1);
    strcpy(buf, msg);
    if(send(fd, buf, strlen(buf), 0) > 0)
        return 0;
    
    return 1;
}
