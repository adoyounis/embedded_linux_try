#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>



void alarm_handler(int sig)
{
	//write(STDOUT_FILENO,"my alarm signal handler executes! number of signal is ",5);
	//printf("my alarm signal handler executes! number of signal is %d",sig);
	//set the default signal handler
	//execvp("ls","ls","-la",NULL);
	system("/bin/ls");
	exit(0);//to measure the time_out
}

void signal_lab()
{
	alarm(1);
	//(void) signal(SIGALRM,alarm_handler);//if you dont set this there will crash occur and to know what happens use strace
	
	for(;;)
	{
		sleep(1);
	}
}

int main()
{
	//make the default handler is alarm_handler
	signal_lab();
	return 0;
}






