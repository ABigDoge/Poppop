#include "socket.h"

int SendMessegePrivate(const struct MessagePrivate data){

    if (send(fd, "send", MAX_BUF, 0) <= 0)
		return 0;

    // 发数据
    if (send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;

}