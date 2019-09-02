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
#include "ServerFunc.h"
using namespace std;
#define SERVER_PORT 8088 // 端口
#define MAX_LISTEN 5     // 最大监听数

int usercount = 0;

// 主函数
int main(int argc, char *argv[])
{
    int sockfd, new_fd;
    socklen_t len = sizeof(struct sockaddr);
    struct sockaddr_in sever_addr, client_addr;
    struct pthread_data pdata;

    bzero(&sever_addr, sizeof(sever_addr));
    sever_addr.sin_family = AF_INET;
    sever_addr.sin_port = htons(SERVER_PORT);
    sever_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 创建套接字，采用TCP协议
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ErrorHandling((char *)"socket error");

    // 绑定
    if (bind(sockfd, (struct sockaddr *)&sever_addr, sizeof(struct sockaddr)) == -1)
        ErrorHandling((char *)"bind error");

    // 监听
    if (listen(sockfd, MAX_LISTEN) == -1)
        ErrorHandling((char *)"listen error");

    // 服务器开启服务
    puts("service open");
    while (1)
    {
        // 接受连接请求
        if ((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &len)) == -1)
        {
            perror("accept error!");
            continue;
        }
        else
            puts("new client connected...");

        // 创建新线程
        pthread_t *pt = (pthread_t *)malloc(sizeof(pthread_t));
        pdata.client_addr = client_addr;
        pdata.my_fd = new_fd;
        pthread_create(pt, NULL, ServerForClient, (void *)&pdata);
    }

    // 关闭服务器
    close(new_fd);
    close(sockfd);
    return 0;
}
