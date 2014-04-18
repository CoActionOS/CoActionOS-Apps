/*
 * Dpad.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <dev/hio.h>

#include "Dpad.hpp"

int Dpad::fd = -1;

Dpad::Dpad() {
	// TODO Auto-generated constructor stub

	if( fd == -1 ){
		fd = open("/dev/hio0", O_RDWR);
		if( fd < 0 ){
			perror("failed to open hio");
		}
	}

}

bool Dpad::report_button(int which){
	uint8_t report;
	if( ioctl(fd, I_HIO_REPORT, &report) < 0 ){
		perror("failed to get report");
	}
	if( report & which ){
		return true;
	}
	return false;
}

bool Dpad::up(){
	return report_button(HIO_DPAD_UP);
}

bool Dpad::down(){
	return report_button(HIO_DPAD_DOWN);
}

bool Dpad::left(){
	return report_button(HIO_DPAD_LEFT);
}

bool Dpad::right(){
	return report_button(HIO_DPAD_RIGHT);
}

bool Dpad::center(){
	return report_button(HIO_DPAD_CENTER);
}
