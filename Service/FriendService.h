#ifndef FriendService_h
#define FriendService_h
#include<DTO/FriendDTO.h>
#include<vector>
using namespace std;
public class FriendService{
	public bool Add(FriendDTO friendDTO);
	public bool Del(FriendDTO friendDTO);
    public bool Edit(FriendDTO frindDTO);
	public int GetFriendList(vector<FriendDTO>& friendList, int id);
};	
#endif