#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void my_signal_handler(int sig)
{
	printf("my signal handler executes! i got signal %d",sig);
	//set the default signal handler
	(void) signal(SIGINT,SIG_DFL);
	
	
}
int main()
{
	//make the default handler is my_signal_handler
	(void) signal(SIGINT,my_signal_handler);
	while(1)
	{
		printf("Allah Akbar\n");
		sleep(1);
	}
	return 0;
}




