/*
 * =====================================================================================
 *
 *       Filename:  dispaly_env.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月22日 20时57分01秒
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

extern char **environ;

int main(int argc, char *argv[])
{
	char **ep;

	for (ep = environ; *ep != NULL; ep++) {
		printf("%s\n", *ep);
	}
	return EXIT_SUCCESS;
}

