#include "socket.h"

int SendFile(const char* s){
    int len;
    char buf[MAX_BUF + 1];
    char catalog[MAX_BUF + 1];

    // 复制目录
    strcpy(catalog, s);

    // 打开文件
    FILE* fp = fopen(catalog, "rb");
    if(fp == NULL)
        return 0;

    // 获取文件名
    char* filename = catalog + strlen(catalog);
    while(filename != catalog && *(filename-1) != '/')
        filename--;
    bzero(buf, MAX_BUF + 1);
    strcpy(buf, filename);

    // 发送文件名
    send(fd, buf, MAX_BUF, 0);

    // 发送文件
    bzero(buf, MAX_BUF + 1);
    while((len = fread(buf, 1, MAX_BUF, fp)) > 0){
        printf("%d\n",len);
        if(send(fd, buf, len, 0)<0){
            puts("send flie error");
            fclose(fp);
            return 0;
        }
        bzero(buf, MAX_BUF + 1);
    }

    fclose(fp);
    return 1;
}
