#ifndef GroupChatDTO_H
#define GroupChatDTO_H

//储存群聊信息
class GroupChatDTO{  
public:
	int ID;            //群聊id
	String Name;        //群聊名称
	String Member_ID_List;//成员id，用逗号隔开
	String Image;       //群聊头像
};

#endif