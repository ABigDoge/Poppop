#ifndef FriendDTO_H
#define FriendDTO_H

//储存好友关系信息
class FriendDTO{
public:
	int UserOneID;		//该用户id
	int UserTwoID;		//好友id
	int GroupOneID;		//好友在该用户的好友列表中所属的分组号
};

#endif
