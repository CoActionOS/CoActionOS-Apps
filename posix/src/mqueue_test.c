/*
 * mqueue_test.c
 *
 *  Created on: May 25, 2013
 *      Author: tgil
 */


#include <pthread.h>
#include <mqueue.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

static int start_producer(void);
static void * consumer(void * args);
static void * producer(void * args);

static void add_timespec(struct timespec * ts, uint32_t nsec);

#define VALID_QUEUE "queue1"
#define TOO_LONG_QUEUE "012345678901234567890123456789012345678901234567890"

int mqueue_test(void){
	int err;
	mqd_t mqdes;
	int i;
	char msg[32];
	unsigned prio;
	struct timespec timeout;
	struct mq_attr attr;

	printf("Test mq_open() ENOENT...");
	errno = 0;
	mqdes = mq_open("/app/some_queue", O_RDWR, 0666, &attr);
	if ( errno != ENOENT ){
		printf("Should have failed with ENOENT not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	/*
	attr.mq_maxmsg = 8;
	attr.mq_msgsize = 32000000;

	printf("Test mq_open() ENOMEM...");
	errno = 0;
	mqdes = mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != ENOMEM ){
		printf("Should have failed with ENOMEM not %d\n", errno);
		return -1;
	}
	printf("passed\n");
	*/

	printf("Test mq_open() ENAMETOOLONG...");
	errno = 0;
	attr.mq_maxmsg = 0;
	attr.mq_msgsize = 32;
	mq_open(TOO_LONG_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != ENAMETOOLONG ){
		printf("Should have failed with ENAMETOOLONG not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	printf("Test mq_open() EINVAL...");
	errno = 0;
	attr.mq_maxmsg = 0;
	attr.mq_msgsize = 0;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EINVAL ){
		printf("Should have failed with EINVAL not %d\n", errno);
		return -1;
	}

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 0;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EINVAL ){
		printf("Should have failed with EINVAL not %d\n", errno);
		return -1;
	}

	attr.mq_maxmsg = 0;
	attr.mq_msgsize = 10;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EINVAL ){
		printf("Should have failed with EINVAL not %d\n", errno);
		return -1;
	}

	attr.mq_maxmsg = -5;
	attr.mq_msgsize = 10;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EINVAL ){
		printf("Should have failed with EINVAL not %d\n", errno);
		return -1;
	}

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = -5;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EINVAL ){
		printf("Should have failed with EINVAL not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	attr.mq_maxmsg = 8;
	attr.mq_msgsize = 32;


	printf("Test mq_open() O_CREAT...");
	errno = 0;
	mqdes = mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if( mqdes == (ssize_t)-1 ){
		fflush(stdout);
		perror("failed");
		return -1;
	}
	printf("passed\n");

	printf("Test mq_open() EEXIST...");
	errno = 0;
	mq_open(VALID_QUEUE, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
	if ( errno != EEXIST ){
		printf("Should have failed with EEXIST not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	i = 0;
	do {
		sprintf(msg, "message:%d", i);
		prio = i;
		clock_gettime(CLOCK_REALTIME, &timeout);
		add_timespec(&timeout, 100*1000*1000); //add 100ms
		err = mq_timedsend(mqdes, msg, 32, prio, &timeout);
		if ( err > 0 ){
			printf("Sent:%s\n", msg);
		} else {
			printf("Send Failed %d\n", errno);
			if ( errno != ETIMEDOUT ){
				printf("TEST FAILED!!!!!\n");
			}
		}
		i++;
	} while(err > 0);

	errno = 0;

	do {
		clock_gettime(CLOCK_REALTIME, &timeout);
		add_timespec(&timeout, 100*1000*1000); //add 100ms
		err = mq_timedreceive(mqdes, msg, 32, &prio, &timeout);
		if ( err > 0 ){
			printf("Recv:%s\n", msg);
		} else {
			printf("Receive Error: %d\n", errno);
			errno = 0;
		}
	} while(err > 0);


	//Start the consumer thread
	if ( start_producer() == 0 ){
		//call the producer
		consumer(NULL);
	} else {
		printf("Failed to start consumer\n");
	}

	printf("Test mq_close()...");
	if ( mq_close(mqdes) < 0 ){
		fflush(stdout);
		perror("failed");
		return -1;
	}
	printf("passed\n");

	printf("Test mq_unlink()...");
	if ( mq_unlink(VALID_QUEUE) < 0 ){
		fflush(stdout);
		perror("failed");
		return -1;
	}
	printf("passed\n");

	printf("Test mq_unlink() ENOENT...");
	errno = 0;
	mq_unlink("queue1");
	if ( errno != ENOENT ){
		printf("Should have failed with ENOENT not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	printf("Test mq_unlink() ENAMETOOLONG...");
	errno = 0;
	mq_unlink(TOO_LONG_QUEUE);
	if ( errno != ENAMETOOLONG ){
		printf("Should have failed with ENAMETOOLONG not %d\n", errno);
		return -1;
	}
	printf("passed\n");

	printf("All Tests Passed\n");

	return 0;
}


int start_producer(void){
	pthread_t t;
	pthread_attr_t attr;
	int err;

	printf("start producer\n");
	err = pthread_attr_init(&attr);
	if ( err < 0 ){
		printf("Failed to start producer (attr_init) (%d)\n", errno);
		return -1;
	}

	err = pthread_attr_setstacksize(&attr, 2048);
	if ( err < 0 ){
		printf("Failed to start producer (setstacksize) (%d)\n", errno);
		return -1;
	}

	if ( pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) < 0 ){
		printf("Faild to set detach state (%d)\n", errno);
	}

	err = pthread_create(&t, &attr, producer, NULL);
	if ( err < 0 ){
		printf("Failed to start producer (create) (%d)\n", errno);
		return -1;
	}

	return 0;
}

void * consumer(void * args){
	int i;
	int err;
	int mqdes;
	char msg[32];
	unsigned int prio;

	printf("%d:start consumer\n", pthread_self());
	mqdes = mq_open(VALID_QUEUE, O_RDONLY, 0, NULL);
	if ( mqdes == -1 ){
		printf("Consumer failed to open queue\n");
		return NULL;
	}


	//gobble up 8 messages
	for(i=0; i < 8; i++){
		printf("%d:Waiting for Message\n", pthread_self());
		err = mq_receive(mqdes, msg, 32, &prio);
		if ( err > 0 ){
			printf("%d:Consume:%s\n", pthread_self(), msg);
		} else {
			printf("%d:Receive Error: %d\n", pthread_self(), errno);
			errno = 0;
		}
	}

	//gobble up 16 messages with one second delays between reads
	for(i=0; i < 16; i++){
		err = mq_receive(mqdes, msg, 32, &prio);
		if ( err > 0 ){
			printf("%d:Consume:%s\n", pthread_self(), msg);
		} else {
			printf("%d:Receive Error: %d\n", pthread_self(), errno);
			errno = 0;
		}
		usleep(200*1000);
	}

	printf("%d:Consumer Close mq\n", pthread_self());
	if ( mq_close(mqdes) < 0 ){
		printf("Consumer failed to close queue\n");
	}

	printf("%d:Consumer done\n", pthread_self());
	return NULL;

}

void * producer(void * args){
	int i;
	int err;
	int mqdes;
	int prio;
	char msg[32];


	printf("%d:Producing\n", pthread_self());
	mqdes = mq_open(VALID_QUEUE, O_RDWR, 0, NULL);
	if ( mqdes == -1 ){
		printf("Producer failed to open queue\n");
		return NULL;
	}

	//send up 8 messages with 100ms delays between messages
	for(i=0; i < 8; i++){
		sprintf(msg, "message:%d", i);
		prio = i;
		printf("%d:Sending message\n", pthread_self());
		err = mq_send(mqdes, msg, 32, prio);
		if ( err > 0 ){
			printf("%d:Produce:%s\n", pthread_self(), msg);
		}
		usleep(100*1000);
	}

	//Produce 16 messages as fast as possible
	for(i=0; i < 16; i++){
		sprintf(msg, "message:%d", i);
		prio = i;
		err = mq_send(mqdes, msg, 32, prio);
		if ( err > 0 ){
			printf("%d:Produce:%s\n", pthread_self(), msg);
		}
	}

	printf("%d:Producer Close mq\n", pthread_self());
	if ( mq_close(mqdes) < 0 ){
		printf("%d:Producer failed to close queue\n", pthread_self());
	}

	printf("%d:Producer done\n", pthread_self());
	return NULL;
}

void add_timespec(struct timespec * ts, uint32_t nsec){
	ts->tv_nsec += nsec;
	if( ts->tv_nsec > 1E9 ){
		ts->tv_sec++;
		ts->tv_nsec -= 1E9;
	}

}


