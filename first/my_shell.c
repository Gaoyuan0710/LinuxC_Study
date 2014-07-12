/*
 * =====================================================================================
 *
 *       Filename:  my_shell.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月12日 13时03分14秒
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

#define MAXSIZE 4096

int main(int argc, char *argv[])
{
	char buf[MAXSIZE];
	pid_t pid;
	int status;

	printf("%% ");

	while (fgets(buf, MAXSIZE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = 0;
		}

		if ((pid = fork() < 0))
		{
			printf("fork error \n");

			return -1;
		}
		else if (pid == 0)
		{
			execlp(buf, buf, (char *)0);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
		{
			printf("wait pid error\n");

			return -2;
		}

		printf("%% ");
	}

	return EXIT_SUCCESS;
}

