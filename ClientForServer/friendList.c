#include "socket.h"

int FriendList(const struct Login data, struct User friends[], int *n){
    if(send(fd, "list", MAX_BUF, 0) <= 0)
		return 0;
    
    if(send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;
    
    char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
	if(len <= 0)
        return 0;

    struct Notice new_data;
    memcpy(&new_data, buf, len);
    *n = new_data.flag;
    for(int i=0;i<*n;i++){
        int len = recv(fd, buf, MAX_BUF, 0);
	    if(len <= 0)
            return 0;
        memcpy(friends+i, buf, len);
    }

    return 1;
}