#include "socket.h"
#include "StructForSocket.h"

int RecvMessege(MessagePrivate* a)
{
    char* const buf = (char*)malloc((MAX_BUF + 1) * sizeof(char));
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    if (len <= 0)
	return 0;
    memcpy(a, buf, len);
    return 1;
}
