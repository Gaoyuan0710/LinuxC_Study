/*
 * =====================================================================================
 *
 *       Filename:  beer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 21时23分28秒
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
#include <pthread.h>

int num = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void *drink(void * no)
{
	pthread_mutex_lock(&mutex);
	num++;

	if ((num / 10 > 0)  && (num % 10 == 1)){
		pthread_cond_broadcast(&cond);
	}
	
	if ((num % 10) < 10 )
	{
		pthread_cond_wait(&cond, &mutex);
		printf("The Group %d   %ld I drink beer\n", *(int *)no / 10, (long)pthread_self());
	}
	pthread_mutex_unlock(&mutex);

}
int main(int argc, char *argv[])
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	pthread_t pthread_id;

	int i = 100;

	for (i = 1; i <= 100; i++)
	{
		pthread_create(&pthread_id, NULL, drink, &i);
		printf("NUM %d pid = %ld\n", i, (long)getpid());
	}
	sleep(20);
	return EXIT_SUCCESS;
}

