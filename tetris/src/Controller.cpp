/*
 * Controller.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include "Controller.hpp"

MLcd Controller::lcd_;
Dpad Controller::dpad_;


void Controller::init(void){
	if ( lcd_.init("/dev/mlcd0") < 0 ){
		perror("failed to init LCD");
	}
}
