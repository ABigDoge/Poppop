#ifdef ServerFunc_h
#define ServerFunc_h
bool CreateUser(int client_fd);
bool Create(int client_fd);
bool Reply(int client_fd);
bool Apply(int client_fd);
bool Quit(int client_fd);
bool Login(int client_fd);
void ErrorHandling(char *message); // 错误处理函数
void *ServerForClient(void *arg);
#endif