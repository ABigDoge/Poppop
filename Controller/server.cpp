#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <map>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>

using namespace std;

#define SERVER_PORT 8088 // 端口
#define MAX_LISTEN 5 // 最大监听数
#define MAX_BUF 1024 // 缓冲区大小

class CMD
{
public:
	char name[10];
	int (*fun)(int, int, char**);
};

class LoginDTO
{
public:
    int Type;
    int ID;
    char PassWord[12];
    LoginDTO()
    {
        Type = 0;
        ID = 0;
        memset(PassWord, 0, sizeof(PassWord));
    }
};

int SelectByID(int ID, char* ret)
{
	char temp[12] = "456";
	strcpy(ret, temp);
	return 1;
}

int SendCM(int ID, time_T time)
{
	//put in online pool
}

//return succeed?
int Login(int client_fd, int argc, char* argv[])
{
	LoginDTO temp = LoginDTO();
	temp.Type = atoi(argv[1]);
	temp.ID = atoi(argv[2]);
	strcpy(temp.PassWord, argv[3]);
	printf("in fun argv1 = %d, argv2 = %d, argv3 = %s\n", temp.Type, temp.ID, temp.PassWord);
	if(temp.Type == 0)
	{
		// AddUser(temp);
	}
	else if(temp.Type == 1)
	{
		char ret[12] = { 0 };
		SelectByID(temp.ID, ret);
		if(strcmp(temp.PassWord, ret) == 0)
		{
			send(client_fd, "1", 2 * sizeof(char), 0);
			printf("OK\n");
			SendCM(temp.ID, time());
		}
		else
		{
			send(client_fd, "0", 2 * sizeof(char), 0);
			printf("ERROR\n");
		}
	}
	else
	{
		return -1;
	}
	return 1;
}

//receiver member divide by '$'
int Send(int client_fd, int argc, char* argv[])
{
	
	return 1;
}

CMD cmdlist[] =
{
	{"login",	Login},		//l
	{"send",	Send},		//发送消息
	// {"sendfile",Sendfile},	//发送文件
	// {"getfile",	Getfile},	//获取文件
	// {"list",	List},		//获取表单
	// {"show",	Show},		//详细信息
	// {"help",	Help},		//获取帮助
	// {"exit",	Exit},		//退出页面
	// {"quit",	Quit},		//下线指令
	// {"clear",	Clear},		//清空页面
	// {"remove",	Remove}		//撤回消息
};

//解析并处理命令
int ExecCmd(int client_fd, char *cmd)
{
	char* argv[10] = { NULL };
	int argc = 0;
	int i = 0;

	if (strlen(cmd) == 0)
		return 0;

	char msg[1024];
	strcpy(msg, cmd);

	/*以字符' '对命令进行切割 */
	while ((argv[argc] = strtok((argc == 0 ? cmd : NULL), " ")) != NULL)
	{
		// printf("argv[%d] = %s\n", argc, argv[argc]);
		argc++;
	}

	/* 查找命令 */
	for (i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++)
	{
		if (strcmp(cmdlist[i].name, argv[0]) == 0)
		{
			/* 执行命令*/
			cmdlist[i].fun(client_fd, argc, argv);
			return 0;
		}
	}
	return -1;
}

//map<int, sockaddr_in> FD_IP;

struct pthread_data
{
	struct sockaddr_in client_addr;
	int my_fd;
};

void ErrorHandling(char* message); // 错误处理函数
void* ServerForClient(void* arg);

// 主函数
int main(int argc, char* argv[])
{
	int sockfd, new_fd;
	socklen_t len = sizeof(struct sockaddr);
	struct sockaddr_in sever_addr, client_addr;
	struct pthread_data pdata;

	bzero(&sever_addr, sizeof(sever_addr));
	sever_addr.sin_family = AF_INET;
	sever_addr.sin_port = htons(SERVER_PORT);
	sever_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// 采用TCP协议
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		ErrorHandling("socket error");

	// 绑定
	if (bind(sockfd, (struct sockaddr*) & sever_addr, sizeof(struct sockaddr)) == -1)
		ErrorHandling("bind error");

	// 监听
	if (listen(sockfd, MAX_LISTEN) == -1)
		ErrorHandling("listen error");

	// 服务器开启服务
	puts("service open");
	while (1)
	{
		if ((new_fd = accept(sockfd, (struct sockaddr*) & client_addr, &len)) == -1)
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
		pthread_create(pt, NULL, ServerForClient, (void*)& pdata);
		//FD_IP.insert(pair<int, sockaddr_in>(new_fd, client_addr));
	}

	// 关闭服务器
	close(new_fd);
	close(sockfd);
	return 0;
}

void ErrorHandling(char* message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void* ServerForClient(void* arg)
{
	struct pthread_data* pdata = (struct pthread_data*)arg;
	int client_fd = pdata->my_fd;
	socklen_t len;
	char buf[MAX_BUF + 1];
	while (1)
	{
		bzero(buf, MAX_BUF + 1);
		len = recv(client_fd, buf, MAX_BUF, 0);
		if (strcmp(buf, "quit") == 0)
			break;
		if (len > 0)
		{
			ExecCmd(client_fd, buf);
		}
		// send(client_fd, buf, len, 0);
	}
}
