#ifndef GroupChatDTO_H
#define GroupChatDTO_H
#include<string>
using namespace std;
//储存群聊信息
class GroupChatDTO{  
public:
	int ID;            //群聊id
	string Name;        //群聊名称
	string Member_ID_List;//成员id，用逗号隔开
	string Image_Path;       //群聊头像
public:
	GroupChatDTO()
	{
	}
};

#endif