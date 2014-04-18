/*
 * Joystick.hpp
 *
 *  Created on: Dec 12, 2013
 *      Author: tgil
 */

#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_

#include "IO.hpp"

class Joystick {
public:
	Joystick();
	static int init();
	static bool left(){ return (value() & (1<<Input::JOY_LEFT)) != 0; };
	static bool right(){ return (value() & (1<<Input::JOY_RIGHT)) != 0; };
	static bool up(){ return (value() & (1<<Input::JOY_UP)) != 0; };
	static bool down(){ return (value() & (1<<Input::JOY_DOWN)) != 0; };
	static bool center(){ return (value() & (1<<Input::JOY_CENTER)) != 0; };

private:
	static pio_sample_t value(){
		Pio p(Input::JOY_PORT);
		return p.value();
	}
};

#endif /* JOYSTICK_HPP_ */
