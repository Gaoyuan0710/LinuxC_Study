/*
 * =====================================================================================
 *
 *       Filename:  my_get_dir_info.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月16日 13时56分36秒
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
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/termios.h>
#include "../include/apue.h"

typedef int MyFunc(const char *, const struct stat *, int);

static MyFunc myfunc;
static int myftw(char *, MyFunc *);
static int dopath(MyFunc *);

static long nreg, ndir,nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
	int ret;

	if (argc != 2)
	{
		printf("The filename is null \n");

		return -1;
	}

	ret = myftw(argv[1], myfunc);
	ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;

	if (ntot == 0)
	{
		ntot = 1;
	}
	printf("regular files  = %7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
	printf("directories    = %7ld, %5.2f %%\n", ndir, ndir * 100.0 / ntot);
	printf("block special  = %7ld, %5.2f %%\n", nblk, nblk * 100.0 / ntot);
	printf("char special   = %7ld, %5.2f %%\n", nchr, nchr * 100.0 / ntot);
	printf("FIFOs          = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0 / ntot);
	printf("symbolic links = %7ld, %5.2f %%\n", nslink, nslink * 100.0 / ntot);
	printf("sockets        = %7ld, %5.2f %%\n", nsock, nsock * 100.0 / ntot);


	return EXIT_SUCCESS;
}

#define FTW_F   1
#define FTW_D   2
#define FTW_DNR 3
#define FTW_NS  4

static char *fullpath;
static size_t pathlen;

static int myftw(char *pathname, MyFunc *func)
{
	fullpath = path_alloc(&pathlen);

	if (pathlen <= strlen(pathname))
	{
		pathlen = strlen(pathname) * 2;
		if ((fullpath = realloc(fullpath, pathlen)) == NULL)
		{
			printf("realloc error\n");

			return -3;
		}
	}
	strcpy(fullpath, pathname);

	return (dopath(func));
}

static int dopath(MyFunc *func)
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	int ret, n;

	if (lstat(fullpath, &statbuf) < 0)
	{
		return (func(fullpath, &statbuf, FTW_NS));
	}
	if (S_ISDIR(statbuf.st_mode) == 0)
	{
		return (func(fullpath, &statbuf, FTW_F));
	}

	if ((ret = func(fullpath, &statbuf, FTW_D) != 0))
	{
		return ret;
	}

	n = strlen(fullpath);
	if (n + NAME_MAX + 2 > pathlen)
	{
		pathlen *= 2;

		if ((fullpath = realloc(fullpath, pathlen)) == NULL)
		{
			printf ("relloc failed\n");
		}
	}
	fullpath[n++] = '/';
	fullpath[n] = 0;

	if (dp = opendir(fullpath) == NULL)
	{
		return (func(fullpath, &statbuf, FTW_DNR));
	}
	while ((dirp = readdir(dp) != NULL))
	{
		if ((strncmp(dirp->d_name, ".", 1) == 0) || (strncmp(dirp->d_name, "..", 2)) )
		{
			continue;
		}
		strcpy(&fullpath[n], dirp->d_name);

		if ((ret = dopath(func)) != 0)
		{
			break;
		}
	}
	fullpath[n -1] = 0;

	if (closedir(dp) < 0)
	{
		printf("can't close ditectory\n");

		return -2;
	}

	return ret;
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
	switch(type)
	{
		case FTW_F:
			switch (statptr->st_mode & S_IFMT)
			{
				case S_IFREG:
					nreg++;
					break;
				case S_IFBLK:
					nblk++;
					break;
				case S_IFCHR:
					nchr++;
					break;
				case S_IFIFO:
					nfifo++;
					break;
				case S_IFLNK:
					nslink++;
					break;
				case S_IFSOCK:
					nsock++;
					break;
				case S_IFDIR:
					printf("for S_IFFIR for %s\n", pathname);
					return -3;
			}
			break;
		case FTW_D:
			ndir++;
			break;
		case FTW_DNR:
			printf("can't read directory %s\n", pathname);
			break;
		case FTW_NS:
			printf("stat error for %s", pathname);
			break;
		default:
			printf("unknow type %d for pathname %s\n", type, pathname);
	}

	return 0;
}
