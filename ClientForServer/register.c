#include "socket.h"

//存储用户个人信息；注册和修改用户信息，查看好友信息时使用
struct User 
{
	int ID;
	char Name[40];
	char Sex[5];
	char ImagePath[50];
	char Department_Name[20];
	char PassWord[30];
	char Motto[200];
	unsigned int IP_Addr;
	int Oneline_State;
};

int Register(const char* username, const char* password)
{
    char buf[MAX_BUF + 1];
    
  	// 发命令
	bzero(buf, MAX_BUF + 1);
	memcpy(buf, "createuser", 30);
	if (send(fd, buf, strlen(buf) + 1, 0) <= 0)
		return 0;

	// 获取发送消息 
	struct User a;
	memset((char*)& test, 0, sizeof(test));
	memcpy(a.Name, username, strlen(username) + 1);
	memcpy(a.PassWord, password, strlen(password) + 1);
	if(send(fd, (char*)& a, sizeof(a), 0) <= 0)
		return 0;
    
	// 接收ID
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    if(len <= 0)
        return 0;
    int id = atoi(buf);
    return id;
}