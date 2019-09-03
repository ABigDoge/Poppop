#include"ServerFunc.h"

using namespace std;
int usercount = 0;
CMD cmdlist[] =
    {
        {"login", Login},   //用户登录
        //{"send", Send},     //发送消息
        {"createGroupChat", CreateGroupChat}, //创建群聊
        {"register", Register},
        // {"sendfile", Sendfile}, //发送文件
        // {"getfile", Getfile}, //获取文件
        {"list",List}, //获取好友列表（已排序）
        // {"show", Show}, //聊天记录
        // {"help", Help}, //获取帮助
        // {"exit", Exit}, //退出页面
        {"quit", Quit}, //下线指令
        // {"find", Find}, //列表中查找好友
        // {"search", Search}, //网络中查找好友
        {"apply", Apply}, //申请好友
        // {"clear", Clear}, //清空页面
        // {"remove", Remove}, //撤回消息
        //{"hello", Hello}};
    };
//解析并处理命令

int ExecCmd(int client_fd, char *cmd)
{
    char *argv[20] = {NULL};
    int argc = 0;
    int i = 0;

    if (strlen(cmd) == 0)
        return 0;

    char msg[MAX_BUF + 1];
    strcpy(msg, cmd);

    // /*以字符' '对命令进行切割 */
    // while ((argv[argc] = strtok((argc == 0 ? cmd : NULL), " ")) != NULL)
    // {
    //     printf("argv[%d] = %s\n", argc, argv[argc]);
    //     argc++;
    // }
    printf(msg);
    /* 查找命令 */
    for (i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++)
    {
        if (strcmp(cmdlist[i].name, msg) == 0)
        {
            /* 执行命令*/
            cmdlist[i].fun(client_fd);
            return 1;
        }
    }
    printf("cmd not find\n");
    return 0;
}

 // 错误处理函数
void ErrorHandling(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

void *ServerForClient(void *arg)
{
    struct pthread_data *pdata = (struct pthread_data *)arg;
    int client_fd = pdata->my_fd;
    socklen_t len;
    char buf[MAX_BUF + 1];
    while (1)
    {
        bzero(buf, MAX_BUF + 1);
        len = recv(client_fd, buf, MAX_BUF, 0);
        if (len > 0)
        {
            if (ExecCmd(client_fd, buf) == -1)
                break;
            else if (ExecCmd(client_fd, buf) == 0)
                printf("ERROR\n");
            else
                printf("OK1\n");
        }
    }
}


// 主函数
int main(int argc, char *argv[])
{
    int sockfd, new_fd;

    mysql::global_library_init();
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
