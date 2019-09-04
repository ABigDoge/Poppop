#include "socket.h"

int SendMessegePrivate(struct MessagePrivate *data){

    if (send(fd, "send", MAX_BUF, 0) <= 0)
		  return 0;

    // 发数据
    if (send(fd, (char*)&data,sizeof(data), 0) <= 0)
		  return 0;

}