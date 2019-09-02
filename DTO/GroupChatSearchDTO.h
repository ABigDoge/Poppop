#ifndef GroupChatSearchDTO_H
#define GroupChatSearchDTO_H
#include"DTO.h"
#include<string>
using namespace std;
class GroupChatSearchDTO:public SearchDTO{
    int Member_ID;
    string Member_Name;
};  //查找群组

#endif