#include "definition.h"

const int MAX_LISTEN = 5; // 最大监听数
const int SERVER_PORT = 8088; // 端口
const char SERVER_IPV4[] = "127.0.0.1"; // ip地址
const int MAX_BUF = 1024; // 缓冲区大小

int fd = -1; // socked通道