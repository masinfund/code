/*************************************************************************
	> File Name: thread2.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年05月14日 星期一 23时19分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
void* thread_main(void *arg);

int main(int argc,char *argv[])
{
	pthread_t t_id;
	int thread_param = 5;
	void * thr_ret;

	if (pthread_create(&t_id, NULL, thread_main, (void*)&thread_param) != 0)
	{
		puts("pthread_create() error!");
		return -1;
	};

	if(pthread_join(t_id,&thr_ret) != 0)	/*main函数将等待t_id中的进程终止
											  并将返回值保存到thr_ret中 */	
	{
		puts("pthread_join() error!");
		return -1;
	};

	printf("Thread return message: %s \n",(char*)thr_ret);
	free(thr_ret);
	return 0;
}

void* thread_main(void *arg)
{
	int i;
	int cnt = *((int*)arg);				//cnt值为5
	char *msg = (char*)malloc(sizeof(char) * 50);
	strcpy(msg,"Hello,I'am thread~ \n");

	for (i=0; i<cnt; i++)
	{
		sleep(1); puts("running thread");
	}
	return (void*)msg;
}
