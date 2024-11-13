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


void fork_lab();

static int idata = 111;

int main()
{
  fork_lab();
  return 0;
}

void fork_lab()
{
	static int istack = 111;
	pid_t child_pid;
	switch(child_pid = fork())//make copy to child and parent
	//switch(child_pid = vfork())//doesnt make copy for child 
	{
		case -1:
			perror("fork");
		case 0:
		{
			idata *= 3;
			istack *= 6;
			break;
		}
		default:
			sleep(10);//make it 3 , i make it 10 only for try stop process by ctrl+z and re run it by fg
			break;
	}
	printf("PID = %d (%s) idata=%d istack=%d\n",getpid(),(child_pid == 0)? "(child)" : "parent" , idata , istack);
	

return ;
}


