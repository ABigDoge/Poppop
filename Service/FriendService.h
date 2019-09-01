#ifndef FriendService_h
#define FriendService_h
#include"FriendDTO.h"
#include<vector>
using namespace std;
//提供关于好友管理的服务
class FriendService{
	public:
		bool Add(FriendDTO friendDTO,mysql::connection db);		//添加好友
		bool Del(FriendDTO friendDTO,mysql::connection db);		//删除好友
    	bool Edit(FriendDTO friendDTO,mysql::connection db);		//编辑好友信息（分组）
};	
#endif