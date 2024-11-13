#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void *thread(void* data)
{
	long long int i = 0;
	while(1)
	{
		printf("%d\n",i);
		i++;
	}
}
int main(int argc,char *argv[])
{
	long long int i = 0;
	pthread_t th;
	pthread_create(&th,NULL,thread,NULL);
	while(1)//comment this and note the difference
	{
		printf("%d\n",i);
		i--;
	}
	return 0;
}
