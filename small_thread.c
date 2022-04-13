#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

char ch='A';
void* small(void *arg);
void* big(void *arg);


void main()
{
	pthread_t id,id1;
	if(pthread_create(&id,NULL,&small,NULL)!=0)
	{
		printf("thread is not created\n");
		exit(0);
	}
	if(pthread_create(&id1,NULL,&big,NULL)!=0)
	{
        	printf("thread 1 is not created\n");
        	exit(0);
	}
	pthread_join(id,NULL);
	pthread_join(id1,NULL);
}


void* small(void *arg)
{
	int i=0;
	for(i=0;i<26;i++)
	printf("small word is %c\n",(ch+32+i));
}

void* big(void *arg)
{
        int i=0;
        for(i=0;i<26;i++)
        printf("big word is %c\n",ch+i);
}


