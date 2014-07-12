/*
 * =====================================================================================
 *
 *       Filename:  6-1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月23日 17时29分38秒
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

char globuf[65536];
int primes[] = {2, 3, 5, 7};

static int square(int x)
{
	int result;

	result = x * x;

	return result;
}

static void doCal(int val) 
{
	printf("The square of %d is %d\n", val, square);

	if (val < 1000)
	{
		int t;

		t = val * val * val;

		printf("The cube of %d is %d\n", val, t);
	}
}

int main(int argc, char *argv[])
{
	static int key = 9937;
	static char mbuf[10240000] = {'a'};
	char *p;

	p = (char *)malloc(1024);

	doCal(key);

	return EXIT_SUCCESS;
}

