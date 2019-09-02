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
#include "DTO.h"
#include "Service.h"
using namespace std;
struct pthread_data
{
    struct sockaddr_in client_addr;
    int my_fd;
};

bool CreateUser(int client_fd);
bool Create(int client_fd);
bool Reply(int client_fd);
bool Apply(int client_fd);
bool Quit(int client_fd);
bool Login(int client_fd);
void ErrorHandling(char *message); // 错误处理函数
void *ServerForClient(void *arg);
#endif