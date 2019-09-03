#ifndef StructForSocket_h
#define StructForSocket_h
/*****************/
/*20190903 wlj 用于Socket传输定义的结构体
/*Notice:
/*务必注意char[]:一个中文两个字节，最后还有一个\0,请勿越界
/*****************/
//存储用户个人信息；注册和修改用户信息，查看好友信息时使用
struct User{
    int ID;
    char Name[40];
    char Sex[5];
    char ImagePath[50];
    char Department_Name[20];
    char Motto[200];
    char PassWord[30]; 
    unsigned int IP_Addr;
    int Oneline_State;
};
//登录退出时发送的结构体
struct Login{
    int ID;
    char PassWord[30];
};
//申请添加好友发送的结构体;申请修改好友分组时的结构体
struct Friend{
    int This_ID;
    int That_ID;
    int Group_ID;
};
//私聊收发文字消息
struct MessagePrivate{
    int Sender_ID;   //消息发送者
	int Recver_ID;   //消息发送者
    char Context[200];
    //以下为服务端发送消息给客户端时填写的数据
    char Time[20];
};
//群聊收发文字消息
struct MessagePublic{
    int Sender_ID;
    int Group_ID;
    char Context[200];
    //以下为服务端发送消息给客户端时填写的数据
    char Time[20];  
    char Sender_Name[40];  
};
//存储群聊信息；创建和修改群聊信息，查看群聊信息时使用
struct GroupChat{
    int ID;
    char Name[40];
    char Member_ID_List[200];//务必注意：前端在创建群聊时,Member必须是好友列表里的
    char Image_Path[50];
};

struct Notice{
    int flag;
    char Context[200];
};
#endif