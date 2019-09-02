#include "socket.h"

int CreateGroup(int* usr_id){
    char buf[MAX_BUF + 1];
    char s_usr_id[MAX_BUF + 1];
    int n = sizeof(usr_id)/sizeof(*usr_id);
    bzero(buf, MAX_BUF + 1);
    for(int i = 0; i < n; i++){
        sprintf(s_usr_id, " %d" , usr_id);
        strcat(buf, s_usr_id);
        strcat(buf, " ");
    }
    if(send(fd, buf, strlen(buf), 0) <= 0)
        return 0;
    
    // 接收 群id
    int len = recv(fd, buf, MAX_BUF, 0);
    if(len <= 0)
        return 0;
    
    int group_id = atoi(buf);
    return group_id;
}