#ifndef ServerFunc_h
#define ServerFunc_h
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <cassert>
#include "DTO.h"
#include "Service.h"
#include "StructForSocket.h"
#define SERVER_PORT 8088 // 端口
#define MAX_LISTEN 5 // 最大监听数
#define MAX_BUF 1024 // 缓冲区大小
using namespace std;
struct pthread_data
{
    struct sockaddr_in client_addr;
    int my_fd;
};

bool Login(int client_fd);
bool CreateGroupChat(int client_fd);
bool Register(int client_fd);
bool Quit(int client_fd);
bool Apply(int client_fd);
bool List(int client_fd);
class CMD
{
public:
    char name[20];
    bool (*fun)(int);
};
#endif