#include "socket.h"
#include "StructForSocket.h"

int SendMessegePublic(MessagePublic a)
{
    char buf[MAX_BUF + 1];

    // ������
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "sendgm", 30);
	if(send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;
    
	// ����Ϣ
	if (send(fd, (char*)& a, strlen(a) + 1, 0) <= 0)
		return 0;
    
    return 1;
}