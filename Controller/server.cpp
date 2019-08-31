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

using namespace std;

#define SERVER_PORT 8088 // 端口
#define MAX_LISTEN 5 // 最大监听数
#define MAX_BUF 1024 // 缓冲区大小

struct pthread_data
{
    struct sockaddr_in client_addr;
    int my_fd;
};

void ErrorHandling(char* message); // 错误处理函数
void* ServerForClient(void *arg);

class GroupChatDTO{  //群聊
public:
	int ID;             //群聊id
	string Name;        //群聊名称
	string MemberIDList;//成员id
	string Image;       //群聊头像
};

class LoginDTO
{
public:
    int Type;
    int ID;
    string PassWord;
};

class UserDTO
{   //用户
public:
	 int ID;
	 string Name;    //用户姓名
	 string PassWord;   //密码
	 string Sex;     //性别
	 string Image;   //头像
	 string DepartmentName;  //所在部门
	 string Motto;   //个性签名
	 unsigned int IPAddr;		//ip地址
	 int OnlineState;	//在线状态
};

class MessageDTO{    
public:
	int SenderID;   //消息发送者
    int RecverID;   //消息发送者
	string Context;     //消息内容
	int Type;       //消息类型
	string Time;  //发送时间
	int GroupID;    //发送的消息所属群组
};


class FriendDTO//change please
{
public:
	int UserOneID;
	int UserTwoID;
	int GroupOneID;
};


class ApplyDTO
{
public:
	 int ID;
     int friendID;
     int groupID;
     string comments;
	 string time;
};

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
        ret.MemberIDList = str;
        ret.Image = "";
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
    User.DepartmentName = "";
    User.Motto = "";
    User.IPAddr = 0;
    User.OnlineState = 0;
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
        User.OnlineState = 1;
        Add(User);
        PutUserOnline(ret.ID, client_fd);
	}
	else if(ret.Type == 1)
	{
        UserDTO get_from_DB;
		get_from_DB = SelectedByID(ret.ID);
        if(get_from_DB.OnlineState == 1)
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
	ApplyDTO ret;
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
	int argc = 0;
    socklen_t len;
	len = recv(client_fd, buf, MAX_BUF, 0);

    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
	{
		argc++;
	}
	ret.ID = atoi(argv[0]);
	ret.friendID = atoi(argv[1]);
    ret.groupID = atoi(argv[2]);
	ret.comments = argv[3];
    ret.time = "";
    vector<FriendDTO> get_from_DB;
    GetFriendList(get_from_DB, ret.ID);
    for(int i = 0; i < get_from_DB.size(); i++)
    {
        if(get_from_DB[i].UserTwoID == ret.friendID)
            return 0;
    }
    UserDTO UserThis;
    UserDTO UserThat;
    UserThis = SelectedByID(ret.ID);
    UserThat = SelectedByID(ret.friendID);
    string rbuf = "";
    string str1 = "apply";
    string str2 = argv[0];
    rbuf = str1 + str2 + ret.comments;
    if(UserThat.OnlineState == 1)
        send(UserThat.IPAddr, rbuf.c_str(), sizeof(rbuf.c_str()), 0);
    else
    {
        MessageDTO msg;
        msg.Context = rbuf;
        msg.Time = "";
        msg.SenderID = UserThis.ID;
        msg.RecverID = UserThat.ID;
        PutMsgInDB(msg);
    }   
}

class CMD
{
public:
	char name[10];
	int (*fun)(int);
};

CMD cmdlist[] =
{
	{"login", Login}, //用户登录
	// {"send", Send}, //发送消息
    {"create", Create}, //创建群聊
	// {"sendfile", Sendfile}, //发送文件
	// {"getfile", Getfile}, //获取文件
	// {"list"， List}, //获取好友列表（已排序）
	// {"show", Show}, //聊天记录
	// {"help", Help}, //获取帮助
	// {"exit", Exit}, //退出页面
	{"quit", Quit}, //下线指令
    // {"find", Find}, //列表中查找好友
    // {"search", Search}, //网络中查找好友
    {"apply", Apply}, //申请好友
    // {"reply", Reply}, //验证好友
	// {"clear", Clear}, //清空页面
	// {"remove", Remove} //撤回消息
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

    // 采用TCP协议
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ErrorHandling("socket error");
    
    // 绑定
    if(bind(sockfd, (struct sockaddr*)&sever_addr, sizeof(struct sockaddr)) == -1)
        ErrorHandling("bind error");

    // 监听
    if(listen(sockfd, MAX_LISTEN) == -1)
        ErrorHandling("listen error");
    
    // 服务器开启服务
    puts("service open");
    while(1)
    {
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
                printf("OK\n");       
		}
    }
}