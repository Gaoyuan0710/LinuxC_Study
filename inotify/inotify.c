/*
 * =====================================================================================
 *
 *       Filename:  inotify.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月19日 23时31分33秒
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
#include <sys/inotify.h>
#include <errno.h>
#include <error.h>
#include <string.h>

#define ERROR(text) error(1, errno, "%s", text)

struct EventMask
{
	int flag;
	const char *name;
};

int freadsome(void *dest, size_t remain, FILE *file)
{
	char *offset = (char *)dest;
	while (remain)
	{

	}
}

int main(int argc, char *argv[])
{
	const char *target;
	int monitor;
	int watcher;
	char last_name[1024];
	char name[1024];
	if (argv == 1)
	{
		target = ".";
	}
	else
	{
		target = argv[1];
	}

	struct EventMask event_mask[] = {
		{IN_ACCESS,       		"IN_ACCESS"},
		{IN_ATTRIB,         	"IN_ATTRIB"},
		{IN_CLOSE_WRITE,        "IN_CLOST_WRETE"},
		{IN_CLOSE_NOWRITE, 		"IN_CLOSE_NOWRITE"},
		{IN_CREATE, 			"IN_CREAT"},
		{IN_DELETE, 			"IN_DELETE"},
		{IN_DELETE_SELF, 		"IN_DELETE_SELF"},
		{IN_MODIFY, 			"IN_MODIFY"},
		{IN_MOVE_SELF, 			"IN_MOVE_SELF"},
		{IN_MOVED_FROM, 		"IN_MOVE_FROM"},
		{IN_MOVED_TO, 			"IN_MOVE_TO"},
		{IN_OPEN, 				"IN_OPEN"},
		{IN_DONT_FOLLOW, 		"IN_DONT_FOLLOW"},
		{IN_EXCL_UNLINK, 		"IN_EXCL_UNLINK"},
		{IN_MASK_ADD, 			"IN_MASK_ADD"},
		{IN_ONESHOT, 			"IN_ONESHOT"},
		{IN_ONLYDIR, 			"IN_ONLYDIR"},
		{IN_IGNORED, 			"IN_OGNORED"},
		{IN_ISDIR, 				"IN_ISDIR"},
		{IN_Q_OVERFLOW, 		"IN_Q_OVERFLOW"},
		{IN_UNMOUNT, 			"IN_UNMOUNT"}
	};

	if ((monitor = inotify_init()) == -1)
	{
		ERROR("monitor");
	}
	if ((watcher = inotify_add_watch(monitor, target, IN_ALL_EVENTS)) == -1)
	{
		ERROR("inotify_add_watch");
	}

	FILE *monitor_file = fopen(monitor, "r");
	
	return EXIT_SUCCESS;
}

