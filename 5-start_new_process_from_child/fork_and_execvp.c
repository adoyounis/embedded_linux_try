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
  pid =fork();
  unsigned int i =3;
  const char *arguments[] = {"gedit",NULL};
  int ret;
  
  while(i--)
  {
    if(pid>0)
    {
      printf("I'm a parent of child process with pid = %d\n",pid);
    }
    else if(!pid) //pid=0
    {
      printf("I'm a child will invoke gedit!\n");
      ret = execvp("gedit",arguments);
      if(ret<0)
      {
      	perror("execv");
      }

    }
    else if(pid < 0) 
    {
      perror("fork");
    }
  }
  while(1);//infinite loop for parent

return ;
}


