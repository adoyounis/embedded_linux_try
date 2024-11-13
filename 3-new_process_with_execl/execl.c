#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int ret;
  ret = execl("/bin/ls","ls","-la",NULL);
  printf("my pid is: %d\n parent pid is: %d",getpid(),getppid());
  if(ret < 0)
  {
    perror("execl");
  }
  return 0;
}
