#include "socket.h"

char* const RecvMessege(){
    char* const buf = (char*)malloc((MAX_BUF + 1) * sizeof(char));
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    return buf;
}