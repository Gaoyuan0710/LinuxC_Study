/*
 * =====================================================================================
 *
 *       Filename:  times1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 20时32分39秒
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
#include <sys/times.h>
#include "apue.h"

static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);

int main(int argc, char *argv[])
{
	int i;

	setbuf(stdout, NULL);
	for (i = 1; i < argc; i++)
	{
		do_cmd(argv[i]);
	}

	exit(0);
}
static void do_cmd(char *cmd)
{
	struct tms tmstart, tmsend;
	clock_t start, end;
	int status;

	printf("\nCommand:%s\n", cmd);

	if ((start = times(&tmstart)) == -1)
	{
		printf("time error\n");
	}
	if ((status = system(cmd)) < 0)
	{
		printf("system error\n");
	}
	if ((end = times(&tmsend)) == -1)
	{
		printf("time error\n");
	}
	pr_times(end - start, &tmstart, &tmsend);
	pr_exit(status);
}

static int pr_times(clock_t real, struct tms *tmstart, struct tms *tmsend)
{
	static long clktck = 0;

	if (clktck == 0)
	{
		if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
		{
			printf("sysconf error\n");
		}
	}
	printf("reakd");
}
