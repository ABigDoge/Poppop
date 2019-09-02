/**************************************************/
/*���ƣ������
/*������
/*�������ڣ� 
/*������
        void
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
                           0ʧ�ܣ����������
/*���ߣ�
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
/*���ƣ��û���¼
/*������
/*�������ڣ�
/*������
		����1�����ݣ�char*�����룬
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
						   0ʧ�ܣ����������
/*���ߣ�
/***************************************************/
int Login(const char* msg)
{
	// ������
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "login");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// ����Ϣ
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*���ƣ�������Ϣ
/*������
/*�������ڣ�
/*������
		����1�����ݣ�char*�����룬
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
						   0ʧ�ܣ����������
/*���ߣ�
/***************************************************/
int Send(const char* msg) 
{
	// ������
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "send");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// ����Ϣ
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*���ƣ�����Ⱥ��
/*������
/*�������ڣ�
/*������
		����1�����ݣ�char*�����룬
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
						   0ʧ�ܣ����������
/*���ߣ�
/***************************************************/
int Create(const char* msg)
{
	// ������
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "create");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// ����Ϣ
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*���ƣ���Ӻ���
/*������
/*�������ڣ�
/*������
		����1�����ݣ�char*�����룬
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
						   0ʧ�ܣ����������
/*���ߣ�
/***************************************************/
int Apply(const char* msg)
{
	// ������
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "apply");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// ����Ϣ
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}

/**************************************************/
/*���ƣ����ܺ���
/*������
/*�������ڣ�
/*������
		����1�����ݣ�char*�����룬
/*����ֵ����¼״̬�� int�� 1�ɹ�������ת
						   0ʧ�ܣ����������
/*���ߣ�
/***************************************************/
int Reply(const char* msg)
{
	// ������
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, "reply");
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	// ����Ϣ
	bzero(buf, MAX_BUF + 1);
	strcpy(buf, msg);
	if (send(fd, buf, strlen(buf), 0) <= 0)
		return 0;

	return 1;
}