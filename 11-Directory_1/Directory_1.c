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


void directory_lab(int argc,char *argv[]);

int main(int argc,char *argv[])
{
	directory_lab(argc,argv);
  	
	return 0;
}

void directory_lab(int argc,char *argv[])
{
	DIR *dir;
	
	printf("argv[0]=%s\n",argv[0]);
	printf("argv[1]=%s\n",argv[1]);
	
	struct dirent *dirp;
	
	
	if(argc != 2)//parent
	{
		printf("please provide the directory to the list output\n");
		exit(1);
    }
    
    if( (dir = opendir(argv[1])) == NULL ) 
    {
		printf("cannot open directory");
		exit(1);
    }

    while( (dirp = readdir(dir)) != NULL)//infinite loop for parent
 	{
 		printf("%s\n",dirp->d_name);
 	}
 	
 	closedir(dir);
 	exit(0);
	return ;
	
}

