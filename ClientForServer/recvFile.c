#include "socket.h"

int RecvFile(const char* catalog){
    char buf[MAX_BUF + 1];
    char file_name[MAX_BUF+1];

    // 获取文件名
    bzero(buf, MAX_BUF + 1);
    int len = recv(fd, buf, MAX_BUF, 0);
    strcpy(file_name, buf);
    bzero(buf, MAX_BUF + 1);

    // 打开文件
    FILE* fp = fopen(file_name, "wb+");

    // 接收文件
    while((len = recv(fd, buf, MAX_BUF, 0)) > 0){
        if(fwrite(buf, 1, len, fp) < 0){
            // 失败
            fclose(fp);
            return 0;
        }
        bzero(buf, MAX_BUF + 1);
    }

    fclose(fp);
    return 1;
}
