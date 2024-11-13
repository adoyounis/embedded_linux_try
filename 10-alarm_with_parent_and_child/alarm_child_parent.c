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

char p_flag=0;
char c_flag=0;

void parent_alarm_handler(int sig)
{
	p_flag = 1;
	alarm(2);
	signal(SIGALRM,parent_alarm_handler);
}

void child_alarm_handler(int sig)
{
	c_flag = 1;
	alarm(1);
	signal(SIGALRM,child_alarm_handler);
}

void fork_lab();

int main()
{
  fork_lab();
  	
  return 0;
}

void fork_lab()
{
  	pid_t pid;
	pid = fork();
	if(pid>0)//parent
	{
      printf("I'm a parent of with pid = %d\n",getpid());
      alarm(2);
      signal(SIGALRM,parent_alarm_handler);
      
    }
    else if(!pid) //child
    {
      printf("I'm a parent of with pid = %d\n",getpid());
      alarm(1);
      signal(SIGALRM,child_alarm_handler);
    }
    else if(pid < 0) 
    {
      perror("fork");
    }
    while(1)//infinite loop for parent
 	{
 		if(p_flag == 1)
 		{
 			printf("parent\n");
 			p_flag = 0;
 		}
 		 if(c_flag == 1)
 		{
 			printf("child\n");
 			c_flag = 0;
 		}
 	}
	return ;
}

