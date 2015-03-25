/*
 * file_test.c
 *
 *  Created on: Oct 22, 2014
 *      Author: tgil
 */


#include "Test.hpp"
#include "tests.h"


#include <applib/Timer.hpp>
#include <applib/File.hpp>

static int create_test(void);
static int open_test(void);
//static int read_test(void);
//static int write_test(void);
//static int close_test(void);

int file_test(void){

	if( create_test() < 0 ){
		return -1;
	}

	if( open_test() < 0 ){
		return -1;
	}


	return 0;
}


int create_test(void){
	Test t;
	StringSmall str = "test\n";

	//start with a clean slate
	File::remove("/home/create_test.txt");

	t.start("file:create");

	File f;

	t.update();


	if( f.create("/home/create_test.txt") < 0 ){
		t.failed("failed to create /home/create_test.txt");
		return -1;
	}

	t.update();

	if( f.write(str.c_str(), str.size()) < 0 ){
		t.failed("failed to write test string");
		return -1;
	}

	t.update();

	if( f.close() < 0 ){
		t.failed("failed to close /home/create_test.txt");
		return -1;
	}

	t.update();

	//test create with no overwrite
	if( f.create("/home/create_test.txt", false) < 0 ){
		t.failed("failed no overwrite open");
		return -1;
	}

	t.update();

	//existing file should not have been overwritten
	if( f.size() != (int)str.size() ){
		t.failed("no overwrite open failed (truncated file)");
		return -1;
	}

	t.update();

	if( f.close() < 0 ){
		t.failed("failed to close no overwrite");
		return -1;
	}

	t.update();

	if( f.create("/home/create_test.txt", true) < 0 ){
		t.failed("failed to overwrite existing file");
		perror("failed to overwrite");
		return -1;
	}

	t.update();

	//after overwrite, size should be zero
	if( f.size() != 0 ){
		t.failed("failed to overwrite file");
		return -1;
	}

	t.update();

	if( f.close() < 0 ){
		t.failed("failed to close overwritten /home/create_test.txt");
		return -1;
	}

	//todo add permissions tests

	t.update();
	if( File::remove("/home/create_test.txt") < 0 ){
		t.failed("failed to remove /home/create_test.txt");
		return -1;
	}

	t.passed();
	return 0;

}

int open_test(void){
	Test t;
	StringSmall str = "test\n";

	File f;

	t.start("file:open");

	t.update();

	if( f.create("/home/open_test.txt") < 0 ){
		t.failed("failed to create /home/open_test.txt");
		return -1;
	}

	t.update();

	if( f.close() < 0 ){
		t.failed("failed to close /home/open_test.txt");
		return -1;
	}

	t.update();

	if( f.open("/home/open_test.txt", File::RDONLY) < 0 ){
		t.failed("failed to open read only");
		return -1;
	}

	t.update();

	if( f.write(str.c_str(), str.size()) < 0 ){
		if( errno != EACCES ){
			t.failed("returned wrong errno");
			printf("%d != %d\n", errno, EACCES);
			return -1;
		}
	} else {
		t.failed("write should have failed");
		return -1;
	}

	t.update();

	if( f.close() < 0 ){
		t.failed("failed to close read only");
		return -1;
	}


	t.update();

	t.passed();
	return 0;
}

