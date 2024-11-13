#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void *thread(void* data)
{
	int i = 0;
	for(i=0;i<5;i++)
	{
		printf("%d-hello from thread\n",i);
	}
}
int main(int argc,char *argv[])
{

	pthread_t th;
	pthread_create(&th,NULL,thread,NULL);
	pthread_join(th,NULL);//if you comment this line the thread will not execute
	return 0;
}
