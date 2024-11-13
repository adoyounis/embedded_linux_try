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
  
  /*if( (pid = fork()) > 0)
  {
    printf("this from parent %d \n",pid);
  }
  else
  {
    printf("this from child %d \n",pid);
  }*/
  
  printf("my pid is: %d\nparent pid is: %d \n",getpid(),getppid());
}


