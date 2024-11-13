#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t fill_mutex;
int arr[10];
int flag = 0;

pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;// unused

void *fill() 
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        pthread_mutex_lock(&fill_mutex);
        arr[i] = i;
        pthread_mutex_unlock(&fill_mutex);
        sleep(1);
    }
}

void *read()
{
    int i = 0;
    printf("Values filled in array are:");
    
    for (i = 0; i < 4; i++)
    {
        sleep(1);
        pthread_mutex_lock(&fill_mutex);
        printf("\n %d \n", arr[i]);
        pthread_mutex_unlock(&fill_mutex);
        
    }
}

int main() 
{
    pthread_t thread_id, thread_id1;
    int ret;
    void *res;

    ret = pthread_create(&thread_id, NULL, &fill, NULL);
    ret = pthread_create(&thread_id1, NULL, &read, NULL);

    printf("\n Created threads\n");
    pthread_join(thread_id, &res);
    pthread_join(thread_id1, &res);

    return 0;
}
