#include "Connect.h"

void ErrorHandling(char* message){
    perror(message);
    exit(EXIT_FAILURE);
}

int Connect(){ 
    int sockfd;
    struct sockaddr_in client_addr;

    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(SERVER_PORT);

    if(inet_aton(SERVER_IPV4, (struct in_addr*) &client_addr.sin_addr.s_addr) == 0)
        ErrorHandling("ip error");

    // 采用TCP协议
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ErrorHandling("Socekt error");
    puts("socket created");

    // 连接
    if(connect(sockfd, (struct sockaddr*) &client_addr, sizeof(client_addr))==-1)
        ErrorHandling("Connect error");
    puts("server connected");

    return sockfd;
    // close(sockfd);
    // 关闭连接
}
