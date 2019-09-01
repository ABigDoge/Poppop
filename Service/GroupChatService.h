#ifndef GroupChatService_h
#define GroupChatService_h
#include<vector>
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include"DTO.h"
using namespace std;
namespace mysql = sqlpp::mysql;

//提供关于群聊的服务
class GroupChatService{
	public:
		//建立群组,True表示操作成功
		static bool Add(GroupChatDTO groupChatDTO, mysql::connection db);
		//编辑群组信息
		static bool Edit(GroupChatDTO groupChatDTO, mysql::connection db);
		//解散群组，数据库中并不删除，只是做一个标记不再显示
		static bool Del(int ID, mysql::connection db);
		//通过群号查询群组
		GroupChatDTO SelectedByID(int id, mysql::connection db);
		//通过名字、ID查询群组，返回结果数
		static int GetGroupChatList(vector<GroupChatDTO>& groupChatList,
							GroupChatSearchDTO dto, mysql::connection db);
		//查询某个群组中的成员
		static int GetGroupMember(vector<UserDTO>& userlist, int id, mysql::connection db);
		//判断成员是否在群组中,True表示在
		static bool UserInGroupChat(int userId, int id, mysql::connection db);
};
#endif
