
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


static int stress_test1(void);
static int stress_test2(void);

int main(int argc, char * argv[]){

	if ( stress_test1() < 0 ){
		printf("Stress test one failed\n");
		exit(1);
	}

	if ( stress_test2() < 0 ){
		printf("Stress test two failed\n");
		exit(1);
	}

	return 0;
}

int stress_test1(void){
	int i;
	int j;
	int ret;
	struct stat st;
	char buffer[64];

	FILE * f;

	printf("append test...");
	fflush(stdout);
	for(i = 0; i < 1000; i++){
		if ( i % 50 == 0 ){
			printf("%d...", i);
			fflush(stdout);
		}

		f = fopen("/home/log.txt", "a");
		if ( f == NULL ){
			perror("Failed to open file");
			return -1;
		}

		strcpy(buffer, "1234567890123456789012345678901234567890123456789\n");
		ret = fprintf(f, "%s", buffer);
		if ( ret != strlen(buffer) ){
			printf("Ret is %d == %d\n", ret, strlen(buffer));
		}
		if ( ret != strlen(buffer) ){
			perror("write failed");
			fclose(f);
			break;
		}

		fstat(fileno(f), &st);
		fclose(f);

		fflush(stdout);
		f = fopen("/home/log.txt", "r");
		if ( f == NULL ){
			perror("Failed to open file");
			return -1;
		}

		fstat(fileno(f), &st);

		//only check the last four entries
		if( st.st_size > 100 ){
			fseek(f, st.st_size- 100, SEEK_SET);
		}

		j = 0;
		errno = 0;
		while(1){

			if ( fgets(buffer, 64, f) == NULL ){
				break;
			}
			if ( strcmp(buffer, "1234567890123456789012345678901234567890123456789\n") != 0 ){
				printf("Bad comparison at line %d %ld\n", j, st.st_size);
				exit(1);
			}
			j++;
		}
		fstat(fileno(f), &st);
		fclose(f);
	}
	printf("passed\n");

	return 0;
}

int stress_test2(void){
	int i;
	struct stat st;
	FILE * f;

	printf("Starting stess test 2\n");
	printf("appending...");
	fflush(stdout);
	f = fopen("/home/log.txt", "a");
	if ( f == NULL ){
		perror("Failed to open file");
		return -1;
	}

	for(i = 0; i < 10000; i++){
		if ( i % 100 == 0 ){
			printf(".");
			fflush(stdout);
		}

		if ( fprintf(f, "123456789\n") < 0 ){
			perror("write failed");
			break;
		}
	}
	fstat(fileno(f), &st);
	printf("%ld bytes\n", st.st_size);
	fclose(f);
	return 0;
}
