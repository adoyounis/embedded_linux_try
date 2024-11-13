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

void read_from_file(int argc,char *argv[]);

int main(int argc,char *argv[])
{
	read_from_file(argc,argv);
	return 0;
}

void read_from_file(int argc,char *argv[])
{
	int fd = -1;
	char Buffer[10] = {0};
	int ret = 0;
	
	if(argc != 2)
	{
		printf("please provide a file name to read from!\n");// as ./open_file foo.txt
		exit(EXIT_FAILURE);
	}
	//fd = open("foo.txt", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		perror("open failed\n");
		exit(EXIT_FAILURE);
	}
	while(ret = read(fd,(void*)Buffer,sizeof(Buffer)-1) > 0)
	{
		printf("%s",Buffer);
		memset(Buffer,0,sizeof(Buffer));//memset function is used to set a block of memory with a specific value
	}
	close(fd);
}

