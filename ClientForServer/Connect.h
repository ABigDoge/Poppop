#ifndef CONNECT_H
#define CONNECT_H

#include <string.h> 
#include <errno.h> 
#include <sys/socket.h> 
#include <resolv.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h>

const int SERVER_PORT = 8088; // 端口
const char SERVER_IPV4[] = "255.255.255.0"; // ip地址

int Connect(); // 连接函数返回sockfd

#endif
