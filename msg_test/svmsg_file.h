/*
 * =====================================================================================
 *
 *       Filename:  svmsg_file.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 17时11分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <stddef.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SERVER_KEY 0x1aaaaaa1
#define PATH_MAX 256

struct requestMsg {
	long mtype;
	int clientId;
	char pathname[PATH_MAX];
};

#define REQ_MSG_SIZE (offsetof(struct requestMsg, pathname) - \
					 offsetof(struct requestMsg, clientId) + PATH_MAX)

#define RESP_MSG_SIZE 8192

struct reponseMsg {
	long ntype;
	char data[]
}
