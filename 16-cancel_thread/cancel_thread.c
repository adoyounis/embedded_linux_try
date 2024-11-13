#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void *thread(void* data)
{
	int i = 0;
	while(1)
	{
		printf("%d-hello from thread\n",i);
		i++;
	}

}

int main(int argc, char **argv)
{
    int s, res;
    pthread_t th;
    pthread_create(&th, NULL, thread, NULL);
    usleep(500);  /* Give thread a chance to get started */
    printf("main(): sending cancellation request\n");
    s = pthread_cancel(th);
    if (s != 0)
        perror("pthread_cancel");

    /* Join with thread to see what its exit status was */
    s = pthread_join(th, &res);
    if (res == PTHREAD_CANCELED)
        printf("main(): thread was canceled\n");

    while (1);
    return 0;
}

