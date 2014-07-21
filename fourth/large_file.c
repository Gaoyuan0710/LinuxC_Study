/*
 * =====================================================================================
 *
 *       Filename:  large_file.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月20日 19时56分04秒
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
#include "../lib/tlpi_hdr.h"

#define _FILE_OFFSET_BITS 64

int main(int argc, char *argv[])
{
	int fd;
	off_t off;
	ssize_t numWriten;

	if (argc != 3 || (strncmp(argv[1], "--help", 6) == 0))
	{
		printf("%s is file\n", argv[0]);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	if (-1 == fd) 
	{
		printf("open error\n");
	}

	off = atoll(argv[2]);

	if (lseek(fd, off, SEEK_SET) == -1)
	{
		printf("lessk error\n");
	}
	if (write(fd, "test", 4) == -1)
	{
		printf("write error\n");
	}

	return EXIT_SUCCESS;
}

