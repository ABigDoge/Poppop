#ifndef FriendDTO_H
#define FriendDTO_H

//储存好友关系信息
class FriendDTO{
public:
	int This_ID;		//该用户id
	int That_ID;		//好友id
	int Group_ID;		//好友在该用户的好友列表中所属的分组号
};

#endif
