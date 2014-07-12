/*
 * =====================================================================================
 *
 *       Filename:  ls_version_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月12日 10时47分50秒
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
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2) 
	{
		printf("error order \n");
		
		return -1;
	}

	if ((dp = opendir(argv[1])) == NULL) 
	{
		printf("The directory is not existing \n");

		return -2;
	}

	while ((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);

	return EXIT_SUCCESS;
}

