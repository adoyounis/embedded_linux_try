#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int ret;
  const char *parameter[] = {"ls","-la",NULL};
  
  ret = execvp("ls",parameter);//depend ls in user path
  printf("my pid is: %d\n parent pid is: %d",getpid(),getppid());
  if(ret < 0)
  {
    perror("execvp");
  }
  return 0;
}
