/*
 * =====================================================================================
 *
 *       Filename:  5-2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月20日 20时16分12秒
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
#include <ctype.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	int fd;
	off_t off;
	ssize_t numWrite;

	if (argc != 2 || (strncmp(argv[1], "--help", 6) == 0))
	{
		printf("%s is file\n", argv[0]);
	}

	fd = open(argv[1], O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	if(fd == -1)
	{
		printf("open error\n");
	}

	off = lseek(fd, 0, SEEK_SET);

	if (off == -1)
	{
		printf("lseek error\n");
	}
	
	numWrite = write(fd, "Kevin Durant\n", 13);

	if (numWrite == -1)
	{
		printf("write error\n");
	}
	close(fd);

	return EXIT_SUCCESS;
}

