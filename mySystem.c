/*
 * =====================================================================================
 *
 *       Filename:  mySystem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 17时10分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int mySystem (const char *cmdString)
{
	pid_t pid;
	int status;

	if (cmdString == NULL)
	{
		return (1);
	}

	if ((pid = fork()) < 0)
	{
		status = -1;
	}
	else if (pid == 0)
	{
		execl("/bin/sh", "sh", "-c", cmdString, (char *)0);
		_exit(127);
	}
	else
	{
		while (waitpid(pid, &status, 0) < 0)
		{
			if (errno != EINTR)
			{
				status = -1;
				break;
			}
		}
	}

	return status;
}
