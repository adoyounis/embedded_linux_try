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

void read_from_and_write_to_file(int argc,char *argv[]);

int main(int argc,char *argv[])
{
	read_from_and_write_to_file(argc,argv);
	return 0;
}

void read_from_and_write_to_file(int argc,char *argv[])
{
	int fd_in = -1;
	int fd_out = -1;
	
	char Buffer[10] = {0};
	
	int ret = 0;
	int retw = 0;
	
	char* input_file_name;
	char* output_file_name;
	
	if(argc != 3)//executable read write
	{
		printf("please provide a file name of write and read files!\n as ./write_file input.txt output.txt");// as ./write_file input.txt output.txt
		exit(EXIT_FAILURE);
	}
	
	input_file_name = argv[1];
	output_file_name = argv[2];
	
	
	fd_in = open(input_file_name, O_RDONLY);
	
	if(fd_in == -1)
	{
		printf("cannot open input file , error number=%d %s\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	/*
	r = 4
	w = 2
	x = 1
	for user: 4(r) + 2(w) = 6(rw)
	for group 4(r)
	for other 4(r)
	
	*/

	// O_RDWR  = read write
	// O_TRUNC = remove the previous content
	// O_CREAT = create a new one if it is not exist
	//0644 rw r r
	
	fd_out = open(output_file_name, O_CREAT||O_RDWR||O_TRUNC,0644);
	
	if(fd_out == -1)
	{
		printf("cannot open output file , error number=%d %s\n",errno,strerror(errno));
		close(fd_in);
		exit(EXIT_FAILURE);
	}

	while(ret = read(fd_in,(void*)Buffer,sizeof(Buffer)-1) > 0)
	{
		retw = write(fd_out,Buffer,ret);
		if(retw != ret)
		{
			printf("cannot write all data from input to output\n");
			close(fd_in);
			close(fd_out);
			exit(0);
		}
		printf("%s",Buffer);
		memset(Buffer,0,sizeof(Buffer));//memset function is used to set a block of memory with a specific value
	}
	close(fd_in);
	close(fd_out);
}

