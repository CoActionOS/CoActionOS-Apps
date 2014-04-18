
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <sched.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "tests.h"

#define SLAVE_APP "/app/ram/sig_slave"

static volatile int status;

static bool proc_done;

static pthread_t create_detached_thread(void* (*func)(void*));
static void * new_proc(void * arg);

int signal_master_test(void){
	pthread_t t;

	if ( sigset_test() < 0 ){
		printf("sigset test failed\n");
		return -1;
	}

	if ( signal_test() < 0 ){
		printf("signal test failed\n");
		return -1;
	}

	if( access(SLAVE_APP, F_OK) < 0 ){
		printf("Test SIGKILL (process)...failed (slave application not found)\n");
		return -1;
	}

	printf("Test SIGKILL (process)...");
	fflush(stdout);

	proc_done = true;

	if ( (t = create_detached_thread(new_proc)) < 0 ){
		return -1;
	}

	//wait for the process to start
	while( proc_done == true ){
		usleep(50*1000);
	}

	sleep(3);

	printf("Send kill to %d...", getpid() + 1);
	fflush(stdout);
	kill(getpid() + 1, SIGKILL);

	//wait for the process to complete
	while( proc_done == false ){
		usleep(50*1000);
		//pthread_kill(t, SIGCONT);
	}

	if ( status == SIGKILL ){
		printf("passed\n");
	} else {
		printf("failed: bad exit status (%d)\n", status);
	}

	printf("All Tests Completed successfully\n");

	return 0;
}

pthread_t create_detached_thread(void* (*func)(void*)){
	pthread_t t;
	pthread_attr_t attr;

	if ( pthread_attr_init(&attr) < 0 ){
		perror("Failed to init pthread attr");
		return -1;
	}

	if ( pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) < 0 ){
		perror("Failed to set detach state");
		return -1;
	}


	if ( pthread_create(&t, &attr, func, NULL) < 0 ){
		perror("Failed to start thread");
		return -1;
	}

	return t;
}

void * new_proc(void * arg){
	proc_done = false;
	errno = 0;
	status = system(SLAVE_APP);
	printf("killed thread\n");
	if ( status < 0 ){
		perror("error");
	}
	proc_done = true;
	return NULL;
}


