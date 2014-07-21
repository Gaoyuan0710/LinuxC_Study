/*
 * =====================================================================================
 *
 *       Filename:  my_dup2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月13日 18时43分59秒
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
#include <fcntl.h>

int my_dup2(int oldfd, int newfd)
{
	int fd_array[255] = {0};
	int index = 0;
	int tmp;

	if (oldfd < 0 || oldfd > 255)
	{
		printf("The oldfd is wrong \n");

		return -1;
	}

	if (newfd < 0 || newfd > 255)
	{
		printf("The newfd is wrong \n");

		return -2;
	}
	if ((fd_array[index] = dup(oldfd)) == -1) 
	{
		printf("The old_fd is not opened\n");

		return -3;
	}
	else 
	{
		close(fd_array[index]);
	}

	if (oldfd == newfd)
	{
		return oldfd;
	}

	for (index = 0; index <= newfd; index++)
	{
		fd_array[index] = dup(oldfd);
		if (fd_array[index] == -1)
		{
			printf("dup error\n");

			return -4;
		}
		else if(fd_array[index] == newfd)
		{
			break;
		}
	}

	for (index-- ;index >=0; index--)
	{
		close(fd_array[index]);
	}

	return newfd;

}
int main(int argc, char *argv[])
{
	int fd = open("./try.txt", O_RDONLY | O_CREAT, 0666);

	fd = my_dup2(fd, 19);

	printf("newfd = %d\n", fd);

	


	return EXIT_SUCCESS;
}

