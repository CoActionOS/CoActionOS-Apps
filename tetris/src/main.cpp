#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <applib/File.hpp>
#include <applib/Font8Util.hpp>
#include <stdlib.h>
#include <ctime>

#include "SMachine.hpp"
#include "Controller.hpp"


int main(int argc, char * argv[]){
	srand(time(NULL));

	SMachine mach;

	mach.run();


	return 0;
}

