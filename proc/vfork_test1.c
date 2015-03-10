/*
 * =====================================================================================
 *
 *       Filename:  vfork_test1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 10时27分11秒
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

int b;

int test1(int *a)
{
	pid_t pid;

	if ((pid = vfork()) < 0)
	{
		printf("vfork error\n");
	}
	if (pid == 0)
	{
		(*a)++;
		printf("child a = %d, b = %d\n", *a, b);
		_exit(0);
	}
	else{
		(*a)++;
		b++;
		printf("parent a = %d, b = %d\n", *a, b);
	//	exit(0);
	}
}
int main(int argc, char *argv[])
{
	b = 10;
	int a = 2;
	test1(&a);
	printf("main a = %d, b = %d\n", a, b);


	return EXIT_SUCCESS;
}

