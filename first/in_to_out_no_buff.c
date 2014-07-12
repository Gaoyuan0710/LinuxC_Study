/*
 * =====================================================================================
 *
 *       Filename:  in_to_out.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月12日 11时31分22秒
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

#define BUFFSIZE 4096

int main(int argc, char *argv[])
{
	int n;
	char buffer [BUFFSIZE];

	while ((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0)
	{
		if ((n = write(STDOUT_FILENO, buffer, n)) != n)
		{
			printf("write error\n");
			
			return -1;
		}
	}

	if (n < 0)
	{
		printf("read error \n>");

		return -2;
	}
	return EXIT_SUCCESS;
}

