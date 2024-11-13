#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>//for open files
#include <unistd.h>//for close files


int main(int argc,char *argv[])
{
	int fd = open("foo.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("open ok\n");
	}
	close(fd);
	return 0;
}

void open_and_close(int argc,char *argv[])
{

}

