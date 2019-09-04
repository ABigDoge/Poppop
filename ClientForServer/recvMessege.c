#include "socket.h"

int RecvMessege(struct MessagePrivate* a)
{
    char* const buf = (char*)malloc((MAX_BUF + 1) * sizeof(char));
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
<<<<<<< HEAD
	if (len <= 0)
		return 0;
	memcpy(&a, buf, len);
	return 1;
}
=======
    if (len <= 0)
	return 0;
    memcpy(a, buf, len);
    return 1;
}
>>>>>>> b2045496e3e159bcc2806c1bbac4ca530612cdfa
