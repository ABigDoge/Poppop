#include "socket.h"

extern int fd;

void Close(){
    close(fd);
}