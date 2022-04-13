#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


void main()
{
	
	pid_t pid;
	pid=fork();
	if(pid==0)//child process
	printf("child process started\n");
	else//parent process
	printf("parent process started %d\n",getpid());

}
