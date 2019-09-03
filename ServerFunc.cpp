#include"ServerFunc.h"
/**************************************************/
/*名称：int Login(int client_fd)
 /*描述：用户登录
 /*作成日期： 2019-8-30
 /*参数：
 参数1：用户线程号、int、输入
 /*返回值：执行状态、int、1成功 0失败
 /*作者：kk
 /***************************************************/
bool Login(int client_fd)
{
    LoginDTO ret;
    char buf[MAX_BUF + 1];
    char *argv[10] = {NULL};
    int argc = 0;
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);

    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
    {
        argc++;
    }
    ret.ID = atoi(argv[1]);
    ret.PassWord = argv[2];
    UserDTO get_from_DB;
    get_from_DB = UserService::SelectedByID(ret.ID);
    if (get_from_DB.Online_State == 1)
    {
        printf("Already online\n");
    }
    if (ret.PassWord.compare(get_from_DB.PassWord) == 0)
    {
        send(client_fd, "1", 2 * sizeof(char), 0);
        UserService::PutUserOnline(ret.ID, client_fd);
        // vector<MessageDTO> vec;
        // AskForMsgUnseen(client_fd, vec);
    }
    else
    {
        send(client_fd, "0", 2 * sizeof(char), 0);
    }
    return true;
}

/**************************************************/
/*名称：bool Quit(int client_fd)
 /*描述：用户下线
 /*作成日期： 2019-8-30
 /*参数：
     参数1：用户线程号、int、输入
 /*返回值：执行状态、int、-1退出
 /*作者：kk
 /***************************************************/
bool Quit(int client_fd)
{
    char buf[MAX_BUF + 1];
    char *argv[10] = {NULL};
    int argc = 0;
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
    {
        argc++;
    }
    UserService::PutUserOffline(atoi(argv[0]));
    return true;
}

/**************************************************/
/*名称：bool Apply(int client_fd)
/*描述：添加好友
/*作成日期： 2019-8-30
/*参数：
    参数1：用户线程号、int、输入
/*返回值：执行状态、int、1成功
/*作者：kk
/***************************************************/
bool Apply(int client_fd)
{
    MessagePrivateDTO ret;
    char buf[MAX_BUF + 1];
    char *argv[10] = {NULL};
    int argc = 0;
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
    {
        argc++;
    }
    UserDTO userThis;
    UserDTO userThat;
    userThis = UserService::SelectedByID(atoi(argv[0]));
    userThat = UserService::SelectedByID(atoi(argv[1]));
    if(FriendService::IsFriend(userThis.ID,userThat.ID)){
        // string str="fail";
        // send(userThat.IP_Addr, str, sizeof(str) * sizeof(char), 0);
        return true;
    }
    string rbuf = "";
    string str1 = "apply";
    string str2 = argv[0];
    rbuf = str1 + " " + str2 + " " + argv[2];
    //
    char *str = const_cast<char *>(rbuf.c_str());
    if (userThat.Online_State == 1)
    {
        printf("online\n");
        send(userThat.IP_Addr, str, sizeof(str) * sizeof(char), 0);
    }
    else
    {
        MessagePrivateDTO msg;
        msg.Context = rbuf;
        msg.Time = "";
        msg.Sender_ID = userThis.ID;
        msg.Recver_ID = userThat.ID;
        MessagePrivateService::Add(msg);
        printf("offline\n");
        send(userThat.IP_Addr, str, sizeof(str) * sizeof(char), 0);
    }
}

/**************************************************/
/*名称：bool Reply(int client_fd)
/*描述：添加好友
/*作成日期： 2019-8-30
/*参数：
    参数1：用户线程号、int、输入
/*返回值：执行状态、int、1成功
/*作者：kk
/***************************************************/
/***************************************************/
/*与数据库的对接
/*wlj
/*2019-9-2
/**************************************************/
bool Reply(int client_fd)
{
    char buf[MAX_BUF + 1];
    char *argv[10] = {NULL};
    int argc = 0;
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
    {
        argc++;
    }
    UserDTO userThis;
    UserDTO userThat;
    userThis = UserService::SelectedByID(atoi(argv[0]));
    userThat = UserService::SelectedByID(atoi(argv[1]));
    MessagePrivateDTO msg;
    if (argv[2] == 0)
    {
        msg.Context = "对不起，你是个好人,但我连朋友也不想和你做！";
    }
    else
    {
        msg.Context = "我们已经是好友了，一起来聊天吧！";
        FriendDTO friendDTO;
        friendDTO.This_ID=userThis.ID;
        friendDTO.That_ID=userThat.ID;
        FriendService::Add(friendDTO);
        friendDTO.This_ID = userThat.ID;
        friendDTO.That_ID = userThis.ID;
        FriendService::Add(friendDTO);
    }
    //printf("To User : %d %d\n", ret.Recver_ID, userThat.IP_Addr);
    string rbuf = "";
    string str1 = "reply";
    string str2 = argv[0];
    rbuf = str1 + str2 + argv[2];
    if (userThat.Online_State == 1)
    {
        send(userThat.IP_Addr, rbuf.c_str(), 2 * sizeof(rbuf.c_str()), 0);
    }
    else
    {
        msg.Context = rbuf;
        msg.Time = "";
        msg.Sender_ID = userThis.ID;
        msg.Recver_ID = userThat.ID;
        MessagePrivateService::Add(msg);
    }
}

/**************************************************/
/*名称：bool CreateUser(int client_fd)
/描述：用户注册
/*2019-9-2
/wlj
/**************************************************/
struct User{
    int ID;
    char PassWord[20];
};

bool CreateUser(int client_fd)
{
    char buf[MAX_BUF + 1];
    char *argv[10] = {NULL};
    int argc = 0;
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    // while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
    // {
    //     argc++;
    // }
    User b;
    memcpy(&b, buf, len);
    UserDTO userDTO;
    userDTO.Name=to_string(b.ID);
    userDTO.PassWord=b.PassWord;
    //stderr<<atoi(b.ID)<<endl;
    //stderr<<b.PassWord<<endl;
    // userDTO.Name = argv[0];
    // userDTO.Sex = argv[1];
    // userDTO.PassWord = argv[2];
    // userDTO.Msg_to_recv = 0;
    // userDTO.Department_Name = argv[3];
    // userDTO.Motto = argv[4];
    // userDTO.IP_Addr = client_fd;
    UserService::Add(userDTO);
}


bool Create(int client_fd)
 {
 	socklen_t len;
    string str = "";
    char buf[MAX_BUF + 1];
    char* argv[10] = { NULL };
 	int argc = 0;
 	len = recv(client_fd, buf, MAX_BUF, 0);
 	//群聊id list<>
 	if (strlen(buf) == 0)
 		return 0;

    GroupChatDTO ret;
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
 		argc++;
 	}
    ret.Member_ID_List = str;
    ret.Image_Path = "";
    cout << str;
    cout << endl;
    return GroupChatService::Add(ret);
 }
