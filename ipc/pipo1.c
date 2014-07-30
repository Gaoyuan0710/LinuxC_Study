/*
 * =====================================================================================
 *
 *       Filename:  pipo1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 17时14分50秒
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

#define MAXLINE 1024
#define DEF_PAGER "/bin/more"
int main(int argc, char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char *pager, *argv0;
	char line[MAXLINE];
	FILE *fp;

	if (argc != 2)
	{
		printf("Usae :a.out <pathname>\n");

		return -1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Open file error\n");

		return -2;
	}
	if (pipe(fd) < 0)
	{
		printf("Pipe error\n");

		return -3;
	}
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");

		return -4;
	}
	else if (pid > 0)
	{
		close(fd[0]);

		while (fgets(line, MAXLINE, fp) != NULL)
		{
			n = strlen(line);

			if (write(fd[1], line, n) != n)
			{
				printf("write error\n");
				return -5;
			}
		}
		if (ferror(fp))
		{
			printf("fgets error\n");

			return -6;
		}
		close(fd[1]);
		if (waitpid(pid, NULL, 0) < 0)
		{
			printf("waitpid error\n");

			return -7;
		}
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (fd[0] != STDIN_FILENO){
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			{
				printf("dup2 error\n");
				return -8;
			}
			close(fd[0]);
		}
		if ((pager = getenv("PAGER")) == NULL)
		{
			pager = DEF_PAGER;
		}
		if ((argv0 = strrchr("PAGER", '/')) != NULL)
		{
			argv0++;
		}
		else
		{
			argv0 = pager;
		}
		if (execl(pager, argv0, (char *)0) < 0)
		{
			printf("execl error\n");

			return -9;
		}

		exit(0);
	} 


	return EXIT_SUCCESS;
}

