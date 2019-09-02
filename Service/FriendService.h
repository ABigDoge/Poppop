#ifndef FriendService_h
#define FriendService_h
#include"FriendDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include<vector>
using namespace std;
namespace mysql=sqlpp::mysql;
//提供关于好友管理的服务
class FriendService{
	public:
		static bool Add(FriendDTO friendDTO);		//添加好友
		static bool Del(FriendDTO friendDTO);		//删除好友
    	static bool Edit(FriendDTO friendDTO);		//编辑好友信息（分组）
		static bool IsFriend(int id1, int id2);		//判断两个人是否是好友
};	
#endif