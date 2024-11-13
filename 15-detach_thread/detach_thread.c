#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void *thread(void* data)
{
	int i = 0;
	for(;i<5 ;i++ )
	{
		printf("%d-hello from thread\n",i);
		
	}
	pthread_detach( pthread_self() );
}
int main(int argc,char *argv[])
{

	pthread_t th;
	pthread_create(&th,NULL,thread,NULL);
	usleep(500);//you should make 
	//pthread_join(th,NULL);//if you comment this line the thread will not execute
	return 0;
}
