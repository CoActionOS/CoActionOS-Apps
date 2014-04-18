

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

#define DIRECTORY_TEST 1
#define FILE_TEST 1
#define SLEEP_TEST 1


int main(int argc, char * argv[]){



	if( stdio_test() < 0 ){
		printf("STDIO Test Failed\n");
		return -1;
	}

	if ( aio_test() < 0 ){
		printf("AIO Test Failed\n");
		return -1;
	}


	if ( listio_test() < 0 ){
		printf("LIO Test Failed\n");
		return -1;
	}

	if ( dirent_test() < 0 ){
		printf("DIRENT Test Failed\n");
		return -1;
	}

	if ( sem_test() < 0 ){
		printf("SEM Test Failed\n");
		return -1;
	}


	if ( mqueue_test() < 0 ){
		printf("MQUEUE Test Failed\n");
		return -1;
	}


	if ( num_test() < 0 ){
		printf("NUM Test Failed\n");
		return -1;
	}



	if ( sched_test() < 0 ){
		printf("SCHED Test Failed\n");
		return -1;
	}

	if ( pthread_master_test() < 0 ){
		printf("PTHREAD Test Failed\n");
		return -1;
	}



	if ( DIRECTORY_TEST ){
		if ( unistd_directory_test() < 0 ){
			printf("Directory test failed\n");
			exit(1);
		}
	}

	if ( FILE_TEST ){
		if ( unistd_file_test() < 0 ){
			printf("File test failed\n");
			exit(1);
		}
	}

	if( unistd_access_test() < 0 ){
		printf("Access test failed\n");
		exit(1);
	}

	if ( SLEEP_TEST ){
		if ( unistd_sleep_test() < 0 ){
			printf("Sleep test failed\n");
			exit(1);
		}
	}

	if ( signal_master_test() < 0 ){
		printf("SIGNAL Master Test Failed\n");
		return -1;
	}

	printf("All Tests Passed\n");
	return 0;


}
