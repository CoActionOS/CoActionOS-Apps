/*
 * Dpad.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef DPAD_HPP_
#define DPAD_HPP_

class Dpad {
public:
	Dpad();

	bool up();
	bool down();
	bool left();
	bool right();
	bool center();

private:
	static int fd;
	bool report_button(int which);

};

#endif /* DPAD_HPP_ */
