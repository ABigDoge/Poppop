#ifndef GroupDTO_H
#define GroupDTO_H
#include<string>
using namespace std;
//好友列表分组信息
class GroupDTO{  
public:
	int ID;         //该分组id
	string Name;    //该分组名称
	int Owner_ID;    //该分组的拥有者用户id
};

#endif
