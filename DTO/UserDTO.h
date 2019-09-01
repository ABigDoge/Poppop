#ifndef UserDTO_H
#define UserDTO_H
#include<string>
//存储用户个人信息
class UserDTO{   
public:
	 int ID;		//用户id
	 string Name;    //用户姓名
	 string PassWord;   //密码
	 string Sex;     //性别
	 string Image;   //头像
	 string Department_Name;  //所在部门
	 string Motto;   //个性签名
	 unsigned int IP_Addr;		//ip地址
	 int Online_State;	//在线状态
	 int Msg_to_recv;     //待接收信息数量
	//UserDTO(){}
};
#endif
