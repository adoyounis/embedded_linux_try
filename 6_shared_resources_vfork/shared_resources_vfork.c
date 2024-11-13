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
  /*pid_t pid;
  pid = vfork();
  int i =3;
  unsigned int g =7;
  const char *arguments[] = {"gedit",NULL};
  int ret;
  
  while(i--)
  {
    if(pid>0)
    {
      printf("I'm a parent of child process with pid = %d\n",pid);
      printf("g value in parent is= %d\n", g--);
    }
    else if(!pid) //pid=0
    {
      printf("I'm a child process\n");
      printf("g value in child is= %d\n", g--);
    }
    else if(pid < 0) 
    {
      perror("fork");
    }
    
  }
  
  if(getpid() == 0)
  {
  	printf("g value out while and still in child is= %d\n", g--);
  }
   else
  {
  	printf("g value out while and still in parent is= %d\n", g--);
  }
  
  //while(1);//infinite loop for parent*/
  printf("hello\n");
  int n=10;
  pid_t pid=vfork();
  if(pid == 0)
  {
  	printf("child process start\n");
  	n=20;
  }
  else
  {
  	printf("now coming to parent\n");
  	
  }
	printf("value of n: %d\n",n);
	
return ;
}


