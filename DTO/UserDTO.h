#ifndef UserDTO_H
#define UserDTO_H

//存储用户个人信息
class UserDTO{   
public:
	 int ID;		//用户id
	 string Name;    //用户姓名
	 int PassWord;   //密码
	 string Sex;     //性别
	 string Image;   //头像
	 string DepartmentName;  //所在部门
	 string Motto;   //个性签名
	 unsigned int IPAddr;		//ip地址
	 int OnlineState;	//在线状态
};
