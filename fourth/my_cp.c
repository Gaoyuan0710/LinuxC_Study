/*
 * =====================================================================================
 *
 *       Filename:  my_cp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月19日 20时15分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include "../lib/tlpi_hdr.h"


#define BUF_SIZE 1024
#define OpenFlags (O_CREAT | O_WRONLY | O_TRUNC)
#define FilePerms (S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP | S_IWOTH)

int main(int argc, char *argv[])
{
	int oldFd, newFd;
//	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	if (argc != 3 || (strncmp(argv[1], "--help", 6)) == 0) 
	{
		printf("please input with the right order %s oldfile newfile\n", argv[1]);
	}
	oldFd = open(argv[1], O_RDONLY);
	newFd = open(argv[2], OpenFlags, FilePerms);
	if (oldFd == -1) 
	{
		printf("open oldfile wrong\n");
	}
	if (newFd == -1) 
	{
		printf("open new file wrong\n");
	}

	while ((numRead = read(oldFd, buf, BUF_SIZE)) > 0) 
	{
		if((write(newFd, buf, numRead)) != numRead)
		{
			printf("couldn't write the whole buf\n");
		}
	}
	if (numRead == -1)
	{
		printf("read wrong\n");
	}
	if (close(oldFd) == -1)
	{
		printf("close oldfile wrong\n");
	}
	if (close(newFd) == -1)
	{
		printf("close new file wrong\n");
	}

	return EXIT_SUCCESS;
}

