/*
 * =====================================================================================
 *
 *       Filename:  atomic_append.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月20日 20时35分35秒
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

#define OpenFlag (O_RDWR | O_CREAT)

int main(int argc, char *argv[])
{
	int i, fd, numBytes;
	int openflags;
	off_t off;
	ssize_t numWrite;

	if(argc < 3 || (strncmp(argv[1], "--help", 6)) == 0)
	{
		printf("filename\n");
	}

	if (argc != 4) 
	{
		openflags = (OpenFlag | O_APPEND);
	}
	else
	{
		openflags = OpenFlag;
	}
	numBytes = atoi(argv[2]);

	fd = open(argv[1], openflags, S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		printf("open wrong\n");
	}

	for (i = 0; i < numBytes; ++i)
	{
		if((argc > 3) && (argv[3] == "x"))
		{
			if (lseek(fd, 0, SEEK_SET) == -1)
			{
				printf("lseek error\n");
			}
		}
		if (write(fd, "A", 1) != 1)
		{
//			getchar();
			printf("Write error\n");
		}
	}

	return EXIT_SUCCESS;
}

