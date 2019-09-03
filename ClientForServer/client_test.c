#include"socket.h"
extern void Connect();
extern int login(int id, const char* password);
extern void Close();
int main(){
    Connect();
    char st[20]="thisisatest";
    if(login(1222,st)){
        printf("hhhhh");
        Close();
        return 1;
    
    }
    else{
            Close();
            printf("wsm");
    }
}