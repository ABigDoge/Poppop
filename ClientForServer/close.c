#include "socket.h"

int Close(){
    if(send(fd, "quit", MAX_BUF, 0) <= 0)
		return 0;
    close(fd);
    return 1;
}
