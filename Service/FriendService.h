#ifndef FriendService_h
#define FriendService_h
#include"FriendDTO.h"
#include"FriendDTO.h"
using namespace std;
class FriendService{
	public:
		bool Add(FriendDTO friendDTO);
		bool Del(FriendDTO friendDTO);
    	bool Edit(FriendDTO frindDTO);
		int GetFriendList(vector<FriendDTO>& friendList, int id);
};	
#endif