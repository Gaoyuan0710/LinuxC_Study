/*
 * =====================================================================================
 *
 *       Filename:  vfork_test2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 11时16分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int createproc();
int main(){
    pid_t pid;
    pid = createproc();
    printf("pid: %d, ret_pid: %d\n", getpid(), pid);
    exit(0);
}
int createproc(){
    pid_t pid;
    pid = vfork();  
    printf("after vfork - pid: %d, ret_pid: %d\n", getpid(), pid);
    if(!pid){
        printf("pid: %d, parent: %d\n", getpid(), getppid());
        //execl("/bin/ls", "ls", "-l", NULL); //正常情况下，应该调用exec()家族的一个函数，载入新的程序
        return pid;
   // _exit(0);
	}   
    else return -1; 
}
