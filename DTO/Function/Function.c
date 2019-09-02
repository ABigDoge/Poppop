/**************************************************/
/*名称：打开软件
/*描述：
/*作成日期： 
/*参数：
        void
/*返回值：登录状态， int， 1成功，需跳转
                           0失败，需继续输入
/*作者：
/***************************************************/
int PowerOn()
{
	int sockfd, len;
	struct sockaddr_in dest;
	char buffer[MAXBUF + 1];
	if (argc != 3)
	{
		printf(" error format,it must be:\n\t\t%s IP port\n", argv[0]);
		return 0;
	}


	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket");
		return 0;
	}
	printf("socket created\n");
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(atoi(argv[2]));
	if (inet_aton(argv[1], (struct in_addr*) & dest.sin_addr.s_addr) == 0)
	{
		perror(argv[1]);
		return 0;
	}

	if (connect(sockfd, (struct sockaddr*) & dest, sizeof(dest)) == -1)
	{
		perror("Connect ");
		return 0;
	}
	printf("server connected\n");
	return 1;
}

/**************************************************/
/*名称：用户登录
/*描述：
/*作成日期：
/*参数：
		参数1：内容，char*，输入，
/*返回值：登录状态， int， 1成功，需跳转
						   0失败，需继续输入
/*作者：
/***************************************************/
int Login(const char* msg)
{
	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "login");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发消息
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*名称：发送消息
/*描述：
/*作成日期：
/*参数：
		参数1：内容，char*，输入，
/*返回值：登录状态， int， 1成功，需跳转
						   0失败，需继续输入
/*作者：
/***************************************************/
int Send(const char* msg) 
{
	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "send");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发消息
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*名称：创建群聊
/*描述：
/*作成日期：
/*参数：
		参数1：内容，char*，输入，
/*返回值：登录状态， int， 1成功，需跳转
						   0失败，需继续输入
/*作者：
/***************************************************/
int Create(const char* msg)
{
	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "create");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发消息
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*名称：添加好友
/*描述：
/*作成日期：
/*参数：
		参数1：内容，char*，输入，
/*返回值：登录状态， int， 1成功，需跳转
						   0失败，需继续输入
/*作者：
/***************************************************/
int Apply(const char* msg)
{
	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "apply");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发消息
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*名称：接受好友
/*描述：
/*作成日期：
/*参数：
		参数1：内容，char*，输入，
/*返回值：登录状态， int， 1成功，需跳转
						   0失败，需继续输入
/*作者：
/***************************************************/
int Reply(const char* msg)
{
	// 发命令
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "reply");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// 发消息
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}