/*
 * =====================================================================================
 *
 *       Filename:  5-4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月21日 18时49分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

int myDup(int oldfd);
int myDup2(int newfd, int oldfd);

int main(int argc, char *argv[])
{
	int fd;
	int newfd;

	if ((fd = open("test.txt", O_RDONLY) == -1))
	{
		printf("open error\n");
	}

	newfd = myDup(fd);

	if (newfd == -1)
	{
		printf("mydup error\n");
	}

	printf("oldfd is %d, while the new fd is %d\n", fd, newfd);

	printf("Please input the new fd\n");
	scanf("%d", &newfd);

	newfd = myDup2(fd, newfd);

	if (newfd == -1)
	{
		printf("myDup2 error\n");
	}
	printf("oldfd is %d, while the new fd is %d\n", fd, newfd);


	return EXIT_SUCCESS;
}
int myDup(int oldfd)
{
	int newfd = fcntl(oldfd, F_DUPFD, oldfd + 1);
	return newfd;
}
int myDup2(int oldfd, int newfd)
{
	int fd = newfd;

	if(oldfd == newfd)
	{
		return newfd;
	}
	else
	{
		if (fcntl(newfd, F_GETFL) != -1)
		{
			close(newfd);
		}
		newfd = fcntl(oldfd, F_DUPFD, fd);
		if (newfd != fd)
		{
			newfd = fcntl(newfd, F_SETFD, fd);
		}

		return newfd;
	}
}
