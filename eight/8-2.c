/*
 * =====================================================================================
 *
 *       Filename:  8-2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月26日 19时42分59秒
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

int glob = 6;

int main(int argc, char *argv[])
{
	int var;
	pid_t pid;

	var = 88;

	printf("before vfork()\n");

	if((pid = vfork()) < 0)
	{
		printf("vfork error\n");
	}
	else if(pid == 0)
	{
		glob++;
		var++;
		_exit(0);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	return EXIT_SUCCESS;
}

