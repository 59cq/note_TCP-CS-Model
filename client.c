#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
	printf("服务器创建socket...\n");
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 > sockfd)
	{
		perror("socket");
		return -1;
	}

	printf("准备地址...\n");
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7777);
	addr.sin_addr.s_addr = inet_addr("114.55.255.246");
	socklen_t len = sizeof(addr);

	printf("绑定连接服务器...\n");
	if(connect(sockfd,(struct sockaddr*)&addr,len))
	{
		perror("bind");
		return -1;
	}

	for(;;)
	{
		char buf[1024] = {};
		printf(">");
		gets(buf);
		write(sockfd,buf,strlen(buf)+1);
		if(0 == strcmp("quit",buf))
		{
			printf("通信结束!\n");
			break;
		}
		printf("read:");
		read(sockfd,buf,sizeof(buf));
		printf("%s\n",buf);
	}
	close(sockfd);
}
