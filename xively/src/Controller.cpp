/*
 * Controller.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: tgil
 */

#include "Controller.hpp"
#include "IO.hpp"

Lcd Controller::lcd_;
Joystick Controller::joystick_;
Rgb Controller::rgb_;

Controller::Controller() {
	// TODO Auto-generated constructor stub

}

int Controller::init(void){
	Output::LcdReset rst;
	joystick().init();
	rst.init(Pin::OUTPUT);
	rst.clr();
	Timer::wait_msec(50);
	rst.set();

	if( lcd().init() < 0 ){
		perror("failed to init");
	}



	return 0;
}
