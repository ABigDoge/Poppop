#ifndef FriendService_h
#define FriendService_h
#include"FriendDTO.h"
#include"FriendDTO.h"
using namespace std;

//提供关于好友管理的服务
class FriendService{
	public:
		bool Add(FriendDTO friendDTO);		//添加好友
		bool Del(FriendDTO friendDTO);		//删除好友
    	bool Edit(FriendDTO friendDTO);		//编辑好友信息（分组）
    	//获取好友列表，id即为被查询用户的id，返回结果数
		int GetFriendList(vector<FriendDTO>& friendList, int id);
};	
#endif