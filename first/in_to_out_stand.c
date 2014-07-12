/*
 * =====================================================================================
 *
 *       Filename:  in_to_out_stand.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月12日 11时38分44秒
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

int main(int argc, char *argv[])
{
	int n;

	while ((n = fgetc(stdin)) != EOF)
	{
		if (putc(n, stdout) == EOF)
		{
			printf("output error\n");

			return -1;
		}
	}

	if (ferror(stdin))
	{
		printf("input error\n");

		return -2;
	}


	return EXIT_SUCCESS;
}

