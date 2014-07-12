/*
 * =====================================================================================
 *
 *       Filename:  my_tee.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月19日 19时17分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../lib/tlpi_hdr.h"
//#include "../lib/error_functions.h"

#define MAX_READ 20
#define MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) 

int main(int argc, char *argv[])
{
	int fd, opt;
	char buf[MAX_READ + 1];
	ssize_t numRead;
	off_t offSet;

	if (argc < 2 || (strncmp(argv[1], "--help", 6) == 0) )
	{
//		usageErr("%s [-a] file");i
		printf("file is wrong\n");
	}

	fd = open(argv[argc - 1], O_RDWR | O_CREAT, MODE);
	if (-1 == fd)
	{
//		errExit("open");
		printf("open wrong\n");
	}
	offSet = lseek(fd, 0, SEEK_SET);
	while ((opt = getopt(argc, argv, ":a")) != -1) 
	{
		switch(opt)
		{
			case 'a':
				offSet = lseek(fd, -1, SEEK_END);
				break;
			case '?':
			default:
				fprintf(stderr, "%s option: '%c' is invalid: ignore\n", argv[0], opt);
				exit(EXIT_FAILURE);
				break;
		}
	}

	while ((numRead = read(STDIN_FILENO, buf, MAX_READ)) > 0) 
	{
		buf[numRead] = '\0';

		if (write(STDOUT_FILENO, buf, numRead + 1) != (numRead + 1)) 
		{
//			fatal("couldn't write whole buf");
			printf("couldn't write whole buf\n");
		}
		if (write(fd, buf, numRead) != (numRead)) 
		{
//			fatal("couldn't write whole buf");
			printf("couldn't write whole buf\n");

		}
	}
	if (numRead == -1) 
	{
//		errExit("read");
		printf("read\n");
	}
	if(close(fd) == -1) 
	{
//		errExit("close file");
		printf("close file \n");
	}

	return EXIT_SUCCESS;
}

