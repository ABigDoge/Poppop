#include "socket.h"

int RecvNotice(){
    char buf[MAX_BUF + 1];
    bzero(buf, MAX_BUF);
	int len = recv(fd, buf, MAX_BUF, 0);
    struct Notice new_data;
    memcpy(&new_data, buf, len);
    return new_data.flag;
}
