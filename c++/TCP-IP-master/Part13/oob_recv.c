/*************************************************************************
	> File Name: oob_recv.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年05月12日 星期六 22时04分04秒
 ************************************************************************/

/* MSG_OOB:紧急接收使用示例*/ 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

#define BUF_SIZE 30
void error_handling(char *message);
void urg_handler(int signo);

int acpt_sock;
int recv_sock;

int main(int argc,char *argv[])
{
	struct sockaddr_in recv_adr, serv_adr;
	int str_len , state;
	socklen_t serv_adr_sz;
	struct sigaction act;
	char buf[BUF_SIZE];
	if (argc != 2) {
		printf("Usage: %s <port> \n",argv[0]);
		exit(1);
	}

	act.sa_handler = urg_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	acpt_sock = socket(PF_INET,SOCK_STREAM,0);
	memset(&recv_adr,0,sizeof(recv_adr));
	recv_adr.sin_family = AF_INET;
	recv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	recv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(acpt_sock,(struct sockaddr*)&recv_adr,sizeof(recv_adr)) == -1)
		error_handling("bind() error!");
	listen(acpt_sock,5);

	serv_adr_sz = sizeof(serv_adr);
	recv_sock = accept(acpt_sock,(struct sockaddr*)&serv_adr,&serv_adr_sz);

	fcntl(recv_sock,F_SETOWN,getpid());		//getpid返回调用此函数的进程ID,此语句指定当前进程为处理SIGURG信号的主体
	state = sigaction(SIGURG,&act,0);		//收到MSG_OOB紧急消息时,操作系统产生SIGURG信号,并调用Handler

	while((str_len=recv(recv_sock,buf,sizeof(buf),0)) != 0)
	{
		if (str_len == -1)
			continue;
		buf[str_len] = 0;
		puts(buf);
	}
	close(recv_sock);
	close(acpt_sock);
	return 0;
}

void urg_handler(int signo)
{
	int str_len;
	char buf[BUF_SIZE];
	str_len = recv(recv_sock,buf,sizeof(buf)-1,MSG_OOB);	//调用紧急接收
	buf[str_len] = 0;
	printf("Urgent message: %s \n",buf);
}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}




























