#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

char ch='A';
//int i=0;
void* fun_call(void* arg);

void main()
{
	int ret,ret1;
	pid_t pid;
	pthread_t id,id1;
	pid=fork();
	if(pid==0)//child process
	{
	printf("child process started\n");
	ret=pthread_create(&id,NULL,&fun_call,NULL);
	if(ret!=0)
        {
                printf("thread is not created in parent\n");
                exit(0);
        }

	}
	else//parent process
	{
	printf("parent process started %d\n",getpid());
	ret1=pthread_create(&id1,NULL,&fun_call,NULL);
	if(ret1!=0)
	{
		printf("thread is not created in parent\n");
		exit(0);
	}
	}
	pthread_join(id,NULL);
	pthread_join(id1,NULL);
//	exit(0);
}

void* fun_call(void* arg)
{
	int i=0;
	for(i=0;i<26;i++)
	printf("alphabet is %c %d\n",ch+i,i);
}
