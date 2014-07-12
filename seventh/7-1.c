/*
 * =====================================================================================
 *
 *       Filename:  7-1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月23日 18时25分42秒
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

#include "../lib/tlpi_hdr.h"

#define MAX_ALLOCS 1000000

int main(int argc, char *argv[])
{
	char *ptr[MAX_ALLOCS];
	int j;
	int freeStep, freeMin, freeMax, blockSize, numAllocs;

	printf("\n");

	if(argc < 3 || (strncmp(argv[1], "--help", 6) == 0))
	{
		printf("error in argvs\n");
	}

	numAllocs = atoi(argv[1]);
	blockSize = atoi(argv[2]);

	freeStep = (argc > 3 ) ? atoi(argv[3]) : 1;
	freeMin = (argc > 4) ? atoi (argv[4]) : 1;
	freeMax = (argc > 5) ? atoi (argv[5]) : 1;

	if (freeMax > numAllocs) 
	{
		printf("freeMax > numAllocs \n error\n");
	}

	printf("Initial program break: %10p\n", sbrk(0));

	printf("Allocing %d * %d bytes\n", numAllocs, blockSize);

	for (j = 0; j < numAllocs; j++)
	{
		ptr[j] = malloc(blockSize);

		if (ptr[j] == NULL)
		{
			printf("malloc error\n");
		}
		printf("After malloc(), program break is: %10p\n", sbrk(0));
	}

	printf("Program break is now %10p\n", sbrk(0));

	printf("Freeing bolcks from %d to %d in steps of %d\n", freeMin, freeMax, freeStep);

	for(j = freeMin - 1; j < freeMax; j += freeStep)
	{
		free(ptr[j]);
	}
	printf("After free(), program break is %10p\n", sbrk(0));

	return EXIT_SUCCESS;
}

