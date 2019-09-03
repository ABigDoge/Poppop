#include"ServerFunc.h"
#include"StructForSocket.h"
#include"string"
using namespace std;

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
    char buf[MAX_BUF + 1];
    socklen_t len;
    len=recv(client_fd, buf, MAX_BUF, 0);
    struct Login rec;
    memcpy(&rec, buf,len);
    UserDTO get_from_DB;
    get_from_DB = UserService::SelectedByID(rec.ID);
    if (get_from_DB.Online_State == 1)
    {
        printf("Already online\n");
        //返回成功
    }
    string str=rec.PassWord;
    if (str.compare(get_from_DB.PassWord) == 0)
    {
        UserService::PutUserOnline(rec.ID, client_fd);
    }
    else
    {
        //返回成功
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
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    struct Login rec;
    memcpy(&rec, buf,len);
    UserService::PutUserOffline(rec.ID);
    //返回成功
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
    char buf[MAX_BUF + 1];
    socklen_t len;
    len = recv(client_fd, buf, MAX_BUF, 0);
    struct Friend rec;
    memcpy(&rec, buf, len);
    FriendDTO friendDTO;
    friendDTO.This_ID = rec.This_ID;
    friendDTO.That_ID = rec.That_ID;
    friendDTO.Group_ID = rec.Group_ID;
    FriendService::Add(friendDTO);
    friendDTO.This_ID = rec.That_ID;
    friendDTO.That_ID = rec.This_ID;
    FriendService::Add(friendDTO);
    return true;
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
// bool Reply(int client_fd)
// {
//     char buf[MAX_BUF + 1];
//     char *argv[10] = {NULL};
//     int argc = 0;
//     socklen_t len;
//     len = recv(client_fd, buf, MAX_BUF, 0);
//     while ((argv[argc] = strtok((argc == 0 ? buf : NULL), " ")) != NULL)
//     {
//         argc++;
//     }
//     UserDTO userThis;
//     UserDTO userThat;
//     userThis = UserService::SelectedByID(atoi(argv[0]));
//     userThat = UserService::SelectedByID(atoi(argv[1]));
//     MessagePrivateDTO msg;
//     if (argv[2] == 0)
//     {
//         msg.Context = "对不起，你是个好人,但我连朋友也不想和你做！";
//     }
//     else
//     {
//         msg.Context = "我们已经是好友了，一起来聊天吧！";
//         FriendDTO friendDTO;
//         friendDTO.This_ID=userThis.ID;
//         friendDTO.That_ID=userThat.ID;
//         FriendService::Add(friendDTO);
//         friendDTO.This_ID = userThat.ID;
//         friendDTO.That_ID = userThis.ID;
//         FriendService::Add(friendDTO);
//     }
//     //printf("To User : %d %d\n", ret.Recver_ID, userThat.IP_Addr);
//     string rbuf = "";
//     string str1 = "reply";
//     string str2 = argv[0];
//     rbuf = str1 + str2 + argv[2];
//     if (userThat.Online_State == 1)
//     {
//         send(userThat.IP_Addr, rbuf.c_str(), 2 * sizeof(rbuf.c_str()), 0);
//     }
//     else
//     {
//         msg.Context = rbuf;
//         msg.Time = "";
//         msg.Sender_ID = userThis.ID;
//         msg.Recver_ID = userThat.ID;
//         MessagePrivateService::Add(msg);
//     }
// }

/**************************************************/
/*名称：bool Register(int client_fd)
/描述：用户注册
/*2019-9-2
/wlj
/**************************************************/
bool Register(int client_fd)
{
    char buf[MAX_BUF + 1];
    socklen_t len;
    len=recv(client_fd, buf, MAX_BUF, 0);
    User rec;
    memcpy(&rec, buf, len);
    UserDTO userDTO;
    userDTO.Name=rec.Name;
    userDTO.Department_Name=rec.Department_Name;
    userDTO.Motto=rec.Motto;
    userDTO.Sex=rec.Sex;
    userDTO.Image=rec.ImagePath;
    userDTO.PassWord=rec.PassWord;
    userDTO.IP_Addr=client_fd;
    UserService::Add(userDTO);
    rec.ID=userDTO.ID;
    if(send(client_fd,(char*)&rec,sizeof(rec),0)<=0){
        return false;
    }
    else
    {
        return true;
    }
}

/**************************************************/
/*名称：bool CreateGroupChat(int client_fd)
/描述：创建群聊
/*2019-9-３
/wlj
/**************************************************/
bool CreateGroupChat(int client_fd)
{
 	socklen_t len;
    char buf[MAX_BUF + 1];
 	len = recv(client_fd, buf, MAX_BUF, 0);
    GroupChat rec;
    memcpy(&rec, buf,len);
    rec.Member_ID_List;
    GroupChatDTO groupChatDTO;
    groupChatDTO.Name=rec.Name;
    groupChatDTO.Image_Path=rec.Image_Path;
    groupChatDTO.Member_ID_List=rec.Member_ID_List;
    GroupChatService::Add(groupChatDTO);
    rec.ID=groupChatDTO.ID;
    vector<UserDTO> userList;
    int count=GroupChatService::GetGroupMember(userList,groupChatDTO.ID);
    for(int i=0;i<count;i++){
        send(userList[i].IP_Addr,(char*)&rec,sizeof(rec),0);
    }
    return true;
}


/**************************************************/
/*名称：bool CreateGroupChat(int client_fd)
/描述：返回好友列表
/*2019-9-３
/wlj
/**************************************************/
bool List(int client_fd){
    socklen_t len;
    char buf[MAX_BUF + 1];
 	len = recv(client_fd, buf, MAX_BUF, 0);
    struct Login rec;
    memcpy(&rec, buf,len);
    vector<UserDTO> userList;
    int count=FriendService::GetFriendList(userList,rec.ID);
    for(int i=0;i<count;i++){
        User user;
        user.ID=userList[i].ID;
        strcpy(user.Name, userList[i].Name.c_str());
        strcpy(user.Department_Name, userList[i].Department_Name.c_str());
        strcpy(user.Sex, userList[i].Sex.c_str());
        strcpy(user.Motto, userList[i].Motto.c_str());
        send(client_fd,(char*)&user,sizeof(user),0);
    }
    return true;
}
