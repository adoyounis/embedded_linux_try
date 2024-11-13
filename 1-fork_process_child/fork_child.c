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

int main()
{
  fork_lab();
  return 0;
}

void fork_lab()
{
  pid_t pid;
  pid =vfork();
  unsigned int i =1;
  
  while(i--)
  {
    if(pid>0)
    {
      printf("I'm a parent of child process with pid = %d\n",pid);
      printf("My pid = %d\n",getpid());
      printf("My parent pid = %d\n",getppid());
    }
    else if(!pid) //pid=0
    {
      printf("I'm a child process with pid = %d\n",pid);
      printf("My pid = %d\n",getpid());
      printf("My parent pid = %d\n",getppid());
      while(1);//infinite loop for child
    }
    else if(pid < 0) 
    {
      perror("fork");
    }
  }
  //while(1);//infinite loop for parent
  printf("->>>>>>>>>>>>>>> the end getpid= %d \n",getpid());
	
return 0;
}


