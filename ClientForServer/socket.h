#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

extern const int MAX_LISTEN; // 最大监听数
extern const int SERVER_PORT; // 端口
extern const char SERVER_IPV4[]; // ip地址
extern const int MAX_BUF; // 缓冲区大小
extern int fd; // socked通道

extern void Connect(); // 建立连接
// extern int Login(); // 登陆
extern int SendMessege(const char* msg); // 发送信息函数，返回成功与否
extern void SendFile(const char* catalog); // 发送文件
// extern void RecvMessge(char* msg); // 接收消息
extern void Close(); // 关闭连接

#endif
