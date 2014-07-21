/*
 * =====================================================================================
 *
 *       Filename:  longjmp.c
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2014年05月23日 15时52分47秒
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
#include <setjmp.h>
#include "../lib/tlpi_hdr.h"

static jmp_buf env;

static void f2(void)
{
	longjmp(env, 2);
}
static void f1(int argc)
{
	if (argc == 1)
	{
		longjmp(env, 1);
	}
	printf("here\n");
	f2();
}

int main(int argc, char *argv[])
{
	switch(setjmp(env))
	{
		case 0:
			printf("calling f1 after initial setjmp()\n");
			f1(argc);
			break;
		case 1:
			printf("We jumped back from f1()\n");
			break;
		case 2:
			printf("We jumped back from f2()\n");
			break;
	}

	return EXIT_SUCCESS;
}

