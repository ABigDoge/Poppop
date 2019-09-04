#include "socket.h"

struct GroupChat RecvGroup(){
    
    char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
    struct GroupChat new_data;
    memcpy(&new_data, buf, len);

    return new_data;
}
