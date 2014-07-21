/*
 * =====================================================================================
 *
 *       Filename:  ugid_functions.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月26日 17时30分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */


#ifndef UGID_FUNCTIONS_H
#define UGID_FUNCTIONS_H

#include "../lib/tlpi_hdr.h"

char *userNameFromId(uid_t uid);
uid_t userIdFromName(const char *name);
char *groupNameFromId(gid_t gid);
gid_t groupIdFromName(const char *name);

#endif

