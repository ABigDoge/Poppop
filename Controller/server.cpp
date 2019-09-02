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
#include "DTO.h"

using namespace std;

#define SERVER_PORT 8088 // 端口
#define MAX_LISTEN 5 // 最大监听数
#define MAX_BUF 1024 // 缓冲区大小

int User[10][2] = { 0 };//临时数据库
int usercount = 0;

struct pthread_data
{
    struct sockaddr_in client_addr;
    int my_fd;
};

void ErrorHandling(char* message); // 错误处理函数
void* ServerForClient(void *arg);

 /**************************************************/
 /*名称：int Create(int client_fd)
 /*描述：创建群聊
 /*作成日期： 2019-8-30
 /*参数：
     参数1：用户线程号、int、输入
 /*返回值：执行状态、int、1成功 0失败
 /*作者：kk
 /***************************************************/
 int Add(GroupChatDTO ret)
 {
     return 1;
 }

 int Create(int client_fd)
 {
 	socklen_t len;
    string str = "";
    GroupChatDTO ret;
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
 	int argc = 0;
 	len = recv(client_fd, buf, MAX_BUF, 0);
 	//群聊id list<>
 	if (strlen(buf) == 0)
 		return 0;

 	/*以字符' '对命令进行切割 */
 	while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
 	{
         if(argc != 0)
         {
             str += argv[argc];
             str += ",";
         }
         else
         {
             ret.Name = argv[argc];
         }
         //ret.ID++
         ret.Member_ID_List = str;
         ret.Image_Path = "";
 		argc++;
 	}
     cout << str;
     cout << endl;
     return Add(ret);
 }

 /**************************************************/
 /*名称：int Add(int client_fd)
 /*描述：用户注册
 /*作成日期： 2019-8-30
 /*参数：
     参数1：用户线程号、int、输入
 /*返回值：执行状态、int、1成功 0失败
 /*作者：kk
 /***************************************************/
 int Add(UserDTO user)
 {
     printf("Add succeed\n");
     return 1;
 }

 /**************************************************/
 /*名称：int Login(int client_fd)
 /*描述：用户登录
 /*作成日期： 2019-8-30
 /*参数：
 参数1：用户线程号、int、输入
 /*返回值：执行状态、int、1成功 0失败
 /*作者：kk
 /***************************************************/
UserDTO SelectedByID(int ID)
{
	UserDTO User;
    User.ID = 0;
    User.Name = "";
    User.PassWord = "123";
    User.Sex = "";
    User.Image = "";
    User.Department_Name = "";
    User.Motto = "";
    User.IP_Addr = 0;
    User.Online_State = 0;
	return User;
}

 int PutUserOnline(int ID, int client_fd)
 {
     return 1;
 }

 int AskForMsgUnseen(int user_ID, vector<MessageDTO> &vec)
 {
     return 1;
 }

 int Login(int client_fd)
 {
 	LoginDTO ret;
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
 	int argc = 0;
    socklen_t len;
 	len = recv(client_fd, buf, MAX_BUF, 0);

     while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
 	{
 		argc++;
 	}
 	ret.Type = atoi(argv[0]);
 	ret.ID = atoi(argv[1]);
 	ret.PassWord = argv[2];
 	if(ret.Type == 0)
 	{
         UserDTO User;
         User.ID = 0;
         User.PassWord = "123";
         User.Online_State = 1;
         Add(User);
         PutUserOnline(ret.ID, client_fd);
 	}
 	else if(ret.Type == 1)
 	{
         UserDTO get_from_DB;
 		get_from_DB = SelectedByID(ret.ID);
         if(get_from_DB.Online_State == 1)
         {
             printf("Already online\n");
         }
 		if(ret.PassWord.compare(get_from_DB.PassWord) == 0)
 		{
 			send(client_fd, "1", 2 * sizeof(char), 0);
 			PutUserOnline(ret.ID, client_fd);
             vector<MessageDTO> vec;
             AskForMsgUnseen(client_fd, vec);
 		}
 		else
 		{
 			send(client_fd, "0", 2 * sizeof(char), 0);
 		}
 	}
 	else
 	{
 		return 0;
 	}
 	return 1;
 }

 /**************************************************/
 /*名称：int Quit(int client_fd)
 /*描述：用户登录
 /*作成日期： 2019-8-30
 /*参数：
     参数1：用户线程号、int、输入
 /*返回值：执行状态、int、-1退出
 /*作者：kk
 /***************************************************/
 int PutUserOffline(int ID)
 {

 }

 int Quit(int client_fd)
 {
 	while(PutUserOffline(client_fd) == 0)
         ;
 	return -1;
 }

/**************************************************/
/*名称：int Apply(int client_fd)
/*描述：添加好友
/*作成日期： 2019-8-30
/*参数：
    参数1：用户线程号、int、输入
/*返回值：执行状态、int、1成功
/*作者：kk
/***************************************************/
int GetFriendList(vector<FriendDTO>& friendList, int id)
{
    return 1;
}

int PutMsgInDB(MessageDTO msg)
{
    return 1;
}

int Apply(int client_fd)
{
	MessageDTO ret;
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
	int argc = 0;
    socklen_t len;
	len = recv(client_fd, buf, MAX_BUF, 0);

    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
	{
		argc++;
	}
    ret.Type = -1;//额外消息类型
	ret.Sender_ID = atoi(argv[0]);
	ret.Recver_ID = atoi(argv[1]);
    ret.Group_ID = atoi(argv[2]);
	ret.Context = argv[3];
    ret.Time = "";
    vector<FriendDTO> get_from_DB;
    GetFriendList(get_from_DB, ret.Sender_ID);
    // for(int i = 0; i < get_from_DB.size(); i++)
    // {
    //     if(get_from_DB[i].UserTwoID == ret.RecverID)
    //         return 0;
    // }
    UserDTO UserThis;
    UserDTO UserThat;
    UserThis = SelectedByID(ret.Sender_ID);
    UserThat = SelectedByID(ret.Recver_ID);
    string rbuf = "";
    string str1 = "apply";
    string str2 = argv[0];
    rbuf = str1 + " " + str2 + " " + ret.Context;
    for(int i = 0; i < 10; i++)
        if(User[i][0] == ret.Recver_ID)
            UserThat.IP_Addr = User[i][1];
    printf("To User : %d %d\n", ret.Recver_ID, UserThat.IP_Addr);
    char *str = const_cast<char*>(rbuf.c_str());
    if(UserThat.Online_State == 1)
    {
        printf("online\n");
        send(UserThat.IP_Addr, str, sizeof(str) * sizeof(char), 0);
    }   
    else
    {
        MessageDTO msg;
        msg.Context = rbuf;
        msg.Time = "";
        msg.Sender_ID = UserThis.ID;
        msg.Recver_ID = UserThat.ID;
        PutMsgInDB(msg);
        printf("offline\n");
        send(UserThat.IP_Addr, str, sizeof(str) * sizeof(char), 0);
    }   
}

/**************************************************/
/*名称：int Reply(int client_fd)
/*描述：添加好友
/*作成日期： 2019-8-30
/*参数：
    参数1：用户线程号、int、输入
/*返回值：执行状态、int、1成功
/*作者：kk
/***************************************************/
int Reply(int client_fd)
{
	MessageDTO ret;
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
	int argc = 0;
    socklen_t len;
	len = recv(client_fd, buf, MAX_BUF, 0);

    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
	{
		argc++;
	}
	ret.Sender_ID = atoi(argv[0]);
	ret.Recver_ID = atoi(argv[1]);
    ret.Group_ID = atoi(argv[2]);
    if(argv[3] == 0)
        ret.Context = "对不起，你是个好人,但我连朋友也不想和你做！";
    else
	    ret.Context = "我们已经是好友了，一起来聊天吧！";
    ret.Time = "";
    UserDTO UserThis;
    UserDTO UserThat;
    UserThis = SelectedByID(ret.Sender_ID);
    UserThat = SelectedByID(ret.Recver_ID);
    for(int i = 0; i < 10; i++)
        if(User[i][0] == ret.Recver_ID)
            UserThat.IP_Addr = User[i][1];
    printf("To User : %d %d\n", ret.Recver_ID, UserThat.IP_Addr);
    string rbuf = "";
    string str1 = "reply";
    string str2 = argv[0];
    rbuf = str1 + str2 + ret.Context;
    if(UserThat.Online_State == 1)
    {
        send(UserThat.IP_Addr, rbuf.c_str(), 2 * sizeof(rbuf.c_str()), 0);
    }

    else
    {
        send(UserThat.IP_Addr, str1.c_str(), 2 * sizeof(str1.c_str()), 0);
        MessageDTO msg;
        msg.Context = rbuf;
        msg.Time = "";
        msg.Sender_ID = UserThis.ID;
        msg.Recver_ID = UserThat.ID;
        PutMsgInDB(msg);   
    }   
}

int Hello(int client_fd)
{
    socklen_t len;
    char buf[MAX_BUF + 1];
	len = recv(client_fd, buf, MAX_BUF, 0);
    User[usercount][0] = atoi(buf);
    User[usercount][1] = client_fd;
    printf("ID:%d FD:%d\n", User[usercount][0], User[usercount][1]);
    usercount++;
}

class CMD
{
public:
	char name[10];
	int (*fun)(int);
};

CMD cmdlist[] =
{
	// {"login", Login}, //用户登录
	// {"send", Send}, //发送消息
    // {"create", Create}, //创建群聊
	// {"sendfile", Sendfile}, //发送文件
	// {"getfile", Getfile}, //获取文件
	// {"list"， List}, //获取好友列表（已排序）
	// {"show", Show}, //聊天记录
	// {"help", Help}, //获取帮助
	// {"exit", Exit}, //退出页面
	// {"quit", Quit}, //下线指令
    // {"find", Find}, //列表中查找好友
    // {"search", Search}, //网络中查找好友
    {"apply", Apply}, //申请好友
    {"reply", Reply}, //验证好友
	// {"clear", Clear}, //清空页面
	// {"remove", Remove}, //撤回消息
    {"hello", Hello}
};

//解析并处理命令
int ExecCmd(int client_fd, char *cmd)
{
	char* argv[10] = { NULL };
	int argc = 0;
	int i = 0;

	if (strlen(cmd) == 0)
		return 0;

	char msg[MAX_BUF + 1];
	strcpy(msg, cmd);

	/*以字符' '对命令进行切割 */
	while ((argv[argc] = strtok((argc == 0 ? cmd : NULL), " ")) != NULL)
	{
	    printf("argv[%d] = %s\n", argc, argv[argc]);
		argc++;
	}

	/* 查找命令 */
	for (i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++)
	{
		if (strcmp(cmdlist[i].name, argv[0]) == 0)
		{
			/* 执行命令*/
			cmdlist[i].fun(client_fd);
			return 1;
		}
	}
    printf("cmd not find\n");
	return 0;
}

// 主函数
int main(int argc, char *argv[])
{
    int sockfd, new_fd;
    socklen_t len = sizeof(struct sockaddr);
    struct sockaddr_in sever_addr, client_addr;
    struct pthread_data pdata;

    bzero(&sever_addr, sizeof(sever_addr) );
    sever_addr.sin_family = AF_INET;
    sever_addr.sin_port = htons(SERVER_PORT);
    sever_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 创建套接字，采用TCP协议
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ErrorHandling((char*)"socket error");
    
    // 绑定
    if(bind(sockfd, (struct sockaddr*)&sever_addr, sizeof(struct sockaddr)) == -1)
        ErrorHandling((char*)"bind error");

    // 监听
    if(listen(sockfd, MAX_LISTEN) == -1)
        ErrorHandling((char*)"listen error");
    
    // 服务器开启服务
    puts("service open");
    while(1)
    {
        // 接受连接请求
        if((new_fd = accept(sockfd, (struct sockaddr*)&client_addr, &len)) == -1)
        {
            perror("accept error!");
            continue;
        }
        else
            puts("new client connected...");

        // 创建新线程
        pthread_t* pt = (pthread_t*)malloc(sizeof(pthread_t));
        pdata.client_addr = client_addr;
        pdata.my_fd = new_fd;
        pthread_create(pt, NULL, ServerForClient, (void *)&pdata);
    }

    // 关闭服务器
    close(new_fd);
    close(sockfd);
    return 0;
}

// 错误处理函数
void ErrorHandling(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

void* ServerForClient(void *arg)
{
    struct pthread_data* pdata = (struct pthread_data*)arg;
    int client_fd = pdata->my_fd;
    socklen_t len;
    char buf[MAX_BUF + 1];
    while(1)
    {
        bzero(buf, MAX_BUF + 1);
        len = recv(client_fd, buf, MAX_BUF, 0);
        if(len > 0)
        {
			if(ExecCmd(client_fd, buf) == -1)
                break;
            else if(ExecCmd(client_fd, buf) == 0)
                printf("ERROR\n");
            else
                printf("OK1\n");
		}
    }
}