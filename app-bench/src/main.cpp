#include "tests.h"

#include <cstdio>





int main(int argc, char * argv[]){

	if( file_test() < 0 ){
		printf("File test failed\n");
		return 1;
	}

	if( string_test() < 0 ){
		printf("String test failed\n");
		return 1;
	}

	if( xml_test() < 0 ){
		printf("Xml test failed\n");
		return 1;
	}


	return 0;
}



