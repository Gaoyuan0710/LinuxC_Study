/*
 * =====================================================================================
 *
 *       Filename:  testMySystem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 17时19分53秒
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
#include "../lib/apue.h"
#include "mySystem.c"
int main(int argc, char *argv[])
{
	int status;

	if ((status = mySystem("date")) < 0)
	{
	//	err_sys("mySystem error\n");
	}
//	pr_exit(status);

	if ((status = mySystem("nosuchcommand")) < 0)
	{
//		err_sys("mySystem error\n");
	}
//	pr_exit(status);

	if ((status = mySystem("who")) < 0)
	{
//		err_sys("mySystem error\n");
	}
//	pr_exit(status);

	exit(0);
}
