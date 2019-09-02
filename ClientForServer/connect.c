#include "socket.h"

const int MAX_LISTEN = 5; // 最大监听数
const int SERVER_PORT = 8088; // 端口
const char SERVER_IPV4[] = "127.0.0.1"; // ip地址
const int MAX_BUF = 1024; // 缓冲区大小

int fd = -1; // socked通道

void ErrorHandling(char* message){
    perror(message);
    exit(EXIT_FAILURE);
}

void Connect(){ 
    struct sockaddr_in client_addr;

    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(SERVER_PORT);

    if(inet_aton(SERVER_IPV4, (struct in_addr*) &client_addr.sin_addr.s_addr) == 0)
        ErrorHandling("ip error");

    // 采用TCP协议
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ErrorHandling("Socekt error");
    puts("socket created");

    // 连接
    if(connect(fd, (struct sockaddr*) &client_addr, sizeof(client_addr))==-1)
        ErrorHandling("Connect error");
    puts("server connected");
}