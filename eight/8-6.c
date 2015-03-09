/*
 * =====================================================================================
 *
 *       Filename:  8-6.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月26日 20时58分04秒
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
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	if ((pid = fork ()) < 0)
	{
		printf("fork error\n");
	}
	else if(pip == 0)
	{
		if ((pid = fork()) < 0)
		{
			printf("fork error\n");
		}
		sle
	}


	return EXIT_SUCCESS;
}

