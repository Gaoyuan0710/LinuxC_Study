/*
 * =====================================================================================
 *
 *       Filename:  8-1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月26日 19时25分35秒
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
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
	int var;
	pid_t pid;

	var = 88;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
	{
		printf("writer wrong\n");
	}

	printf("before fork\n");

	if ((pid = fork()) < 0){
		printf("fork error\n");
	}
	else if (pid == 0)
	{
		glob++;
		var++;
	}
	else
	{
		sleep(2);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

	return EXIT_SUCCESS;
}

