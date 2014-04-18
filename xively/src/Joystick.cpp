/*
 * Joystick.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: tgil
 */

#include "Joystick.hpp"

Joystick::Joystick() {
	// TODO Auto-generated constructor stub

}

int Joystick::init(){
	Pio joy(Input::JOY_PORT);
	return joy.init(Input::JOY_MASK, Pio::INPUT | Pio::PULLDOWN);
}
