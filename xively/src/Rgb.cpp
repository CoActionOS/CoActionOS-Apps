/*
 * Rgb.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: tgil
 */

#include "Rgb.hpp"

Pwm Rgb::pwm(1);

Rgb::Rgb() {
	// TODO Auto-generated constructor stub

}


int Rgb::init(){
	uint8_t chans = (1<<RED_CHANNEL)|(1<<GREEN_CHANNEL)|(1<<BLUE_CHANNEL);
	return pwm.init(chans, 1000000, 1000, 0, 1);
}

void Rgb::setcolor(uint16_t r, uint16_t g, uint16_t b){
	pwm.set(RED_CHANNEL, 1000 - r);
	pwm.set(GREEN_CHANNEL, 1000 - g);
	pwm.set(BLUE_CHANNEL, 1000 - b);
}
