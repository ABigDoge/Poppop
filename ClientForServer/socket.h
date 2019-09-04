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
#include"string.h"
#include "StructForSocket.h"

extern const int SERVER_PORT; // 端口
extern const char SERVER_IPV4[]; // ip地址
extern const int MAX_BUF; // 缓冲区大小
extern int fd; // socked通道

// 建立连接
void Connect();

// 注册，参数为用户名与密码，返回值为用户id
extern int Register(const struct User data);

// 登陆,参数为用户id与密码，返回值为0登陆失败，1为登陆成功
extern int Login(const struct Login data);

// 发送信息函数，返回值0为失败，1为成功
extern int SendMessegePrivate(const struct MessagePrivate* data);

// 发送信息函数，返回值0为失败，1为成功
extern int SendMessegePublic(const struct MessagePublic* data);

// 发送文件，参数为文件所在目录，返回值0为失败，1为成功
extern int SendFile(const char* catalog);

// 接收群聊消息，返回所接受消息
extern int RecvPublicMessege(struct MessagePublic* data);

// 接收消息，返回所接受消息
extern int RecvMessege(struct MessagePrivate* data);

// 接收文件，参数为文件保存目录,格式为"/../../"，返回值0为失败，1为成功
extern int RecvFile(const char* catalog);

// 建群，参数为所有用户的数组，返回值是否创建成功
extern int CreateGroup(const struct GroupChat data);

// 申请好友，参数为为我的id和被申请好友id,返回值0为失败，1为成功
extern int ApplyForFriend(const struct Friend data);

// 同意好友与否
// extern int ReplyFriend();

// 请求好友列表信息
extern int FriendList(const struct Login data, struct User friends[], int *n);

// 被加好友
extern struct User ReplyFriend();

// 接收命令
extern int RecvNotice();

// 接收被拉群聊的信息
extern struct GroupChat RecvGroup();

// 关闭连接
extern int Close();

#endif
