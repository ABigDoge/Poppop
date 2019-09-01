#ifndef GroupService_h
#define GroupService_h
#include"DTO.h"
#include<vector>
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
using namespace std;
namespace mysql = sqlpp::mysql;

//提供关于好友分组的服务
//注意区分group:好友列表里给好友的分组 groupchat:群聊
class GroupService{
	public:
		//添加好友分组
		bool Add(GroupDTO groupDTO, mysql::connection db);
		//编辑分组，比如改名
		bool Edit(GroupDTO groupDTO, mysql::connection db);
		//受限删除分组
		bool Del(GroupDTO groupDTO, mysql::connection db);
		//得到某个用户的好友分组列表，即他给好友设了哪些分组，返回结果数
		int GetGroupList(vector<GroupDTO>& groupList, int userid, mysql::connection db);
		//得到某个用户的某个好友分组列表的所有成员,返回结果数,GroupSearchDTO中Owner_ID为用户ID,ID为分组ID
		int GetGroupMemberList(vector<UserDTO>&memberList,GroupSearchDTO obj,
									 mysql::connection db);
};	
#endif