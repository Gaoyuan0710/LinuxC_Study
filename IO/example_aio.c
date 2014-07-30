/*
 * =====================================================================================
 *
 *       Filename:  example_aio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月29日 15时25分03秒
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
#include <ctyped.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <aio.h>
#include <error.h>

#define BSZ 4096
#define NUMBUF 8

enum rwop{
	UNUSED = 0,
	READ_PENDING = 1,
	WRITE_PENDING = 2
};

struct buf{
	enum reop op;
	int last;
	struct aiocb aiocb;
	unsigned char data[BSZ];
};

struct buf bufs[NUMBUF];

unsigned char translate(unsigned char c)
{
	if (isalpha(c))
	{
		if (c >= 'n')
		{
			c -= 13;
		}
		else if (c >= 'a')
		{
			c += 13;
		}
		else if (c >= 'N')
		{
			c -= 13;
		}
		else {
			c += 13;
		}
	}
	return c;
}

int main(int argc, char *argv[])
{
	int ifd, ofd, i, j, n, err, numop;
	struct stat sbuf;
	const struct aiocb *aiolist[NUMBUF];
	off_t off = 0;

	if (argc != 3)
	{
		printf("Please input with the order INPUTFILE OUTPUTFILE\n");
		return -1;
	}
	if ((ifd = open(argv[[1], O_RDONLY]) < 0))
	{
		printf ("Open Input file error\n");
		return -2;
	}
	if ((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0766) < 0))
	{
		printf ("Creat Output file error\n");
		return -3;
	}

	for (i = 0; i < NUMBUF; i++)
	{
		bufs[i].op = UNUSED;
		bufs[i].aiocb.aio_buf = bufs[i].data;
		bufs[i].aiocb.aio_sigevent.sigev_notify = SIGEV_NONE;
		aiolist[i] = NULL;
	}
	numop = 0;

	for (;;)
	{
		for (i = 0; i < NBUF; i++)
		{
			switch(bufs[i].op)
			{
				case UNUSED:
					if (off < sbuf.st_size)
					{
						bufs[i].op = READ_PENDING;
						bufs[i].aiocb.aio_fildes = ifd;
						bufs[i].aiocb.aio_offset = off;
						off += BSZ;
						if (off >= sbuf.st_size)
					}
			}
		}
	}




	return EXIT_SUCCESS;
}

