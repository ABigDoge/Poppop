#include "socket.h"

int CreateGroup(const struct GroupChat data){

    if (send(fd, "createGroupChat", MAX_BUF, 0) <= 0)
		return 0;
    // 发数据
    if (send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		  return 0;

    return 1;
}