#include "socket.h"

int ApplyForFriend(int my_id, int fri_id){
    char buf[MAX_BUF + 1];
    char s_id[MAX_BUF + 1];
    bzero(buf, MAX_BUF + 1);

    sprintf(s_id, " %d" , my_id);
    strcat(buf, s_id);

    sprintf(s_id, " %d" , fri_id);
    strcat(buf, s_id);

    if(send(fd, buf, strlen(buf), 0) <= 0)
        return 0;

    return 1;
}