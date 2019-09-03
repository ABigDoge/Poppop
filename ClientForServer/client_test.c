#include"socket.h"

// extern void Connect();
// extern int login(int id, const char* password);
// extern void Close();
// extern int Register(const struct User data);

int Register(const struct User data){

	if (send(fd, "register", MAX_BUF, 0) <= 0)
		return 0;
	
  	// 发用户名
	if (send(fd, (char*)&data, MAX_BUF, 0) <= 0)
		return 0;

	// 接收是否匹配
	char buf[MAX_BUF + 1];
	int len = recv(fd, buf, MAX_BUF, 0);
	if(len <= 0)
        return 0;
	
	struct User new_data;
    memcpy(&new_data, buf, len);

    return new_data.ID;
}
const int MAX_LISTEN = 5; // 最大监听数
const int SERVER_PORT = 8088; // 端口
const char SERVER_IPV4[] = "127.0.0.1"; // ip地址
const int MAX_BUF = 1024; // 缓冲区大小

int fd = -1; // socked通道

void ErrorHandling(char* message){
    perror(message);
    exit(EXIT_FAILURE);
}

void Connect(){ 
    struct sockaddr_in client_addr;

    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(SERVER_PORT);

    if(inet_aton(SERVER_IPV4, (struct in_addr*) &client_addr.sin_addr.s_addr) == 0)
        ErrorHandling("ip error");

    // 采用TCP协议
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ErrorHandling("Socekt error");
    puts("socket created");

    // 连接
    if(connect(fd, (struct sockaddr*) &client_addr, sizeof(client_addr))==-1)
        ErrorHandling("Connect error");
    puts("server connected");
}
void Close(){
    close(fd);
}


int main(){
    Connect();
  //  char st[20]="thisisatest";
    struct User user;
    strcpy(user.Name, "tina");
    strcpy(user.PassWord, "pop");
    user.Oneline_State = 1;
    strcpy(user.Motto, "wowowo");
    strcpy(user.Department_Name, "IT");
    strcpy(user.ImagePath, "1");
    int newid = Register(user);
    if(newid!=0){
        printf("OK\n");
        Close();
        return 1;
    
    }
    else{
            Close();
            printf("wsm");
    }
}