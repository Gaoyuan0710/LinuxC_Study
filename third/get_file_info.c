/*
 * =====================================================================================
 *
 *       Filename:  get_file_info.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月13日 15时55分15秒
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

int main(int argc, char *argv[])
{
	int val;

	if (argc != 2)
	{
		printf("The filename is null\n");

		return -1;
	}
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	{
		printf("Fcntl error \n");

		return -2;
	}
	switch (val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("Read and write\n");
			break;
		default:
			printf("Unknow access mode\n");
			
			return -3;
	}

	if (val & O_APPEND)
	{
		printf("append\n");
	}
	if  (val & O_NONBLOCK)
	{
		printf("nonblocking\n");
	}
	if (val & O_SYNC);
	{
		printf("synchronous writes\n");
	}
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if (val & O_FSYNC)
	{
		printf("synchronous writes\n");
	}
#endif

	return EXIT_SUCCESS;
}

