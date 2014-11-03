/*
 * Test.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: tgil
 */

#include <cstdio>
#include "Test.hpp"

Test::Test() {
	// TODO Auto-generated constructor stub

	t.reset();
}

void Test::start(const char * name){
	printf("%s test...", name);
	fflush(stdout);
	t.start();
}

void Test::stop(bool passed, const char * desc){
	t.stop();
	if( !passed ){
		printf("failed in %ldus: %s\n", t.usec(), desc);
	} else {
		printf("passed in %ldus\n", t.usec());
	}
}

uint32_t Test::elapsed(){ return t.usec(); }

void Test::update(){ printf("."); fflush(stdout); }
