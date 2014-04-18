/*
 * Controller.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <applib/MLcd.hpp>
#include "Dpad.hpp"

class Controller {
public:

	static MLcd & lcd(){ return lcd_; }
	static Dpad & dpad(){ return dpad_; }

private:

	static MLcd lcd_;
	static Dpad dpad_;

};

#endif /* CONTROLLER_HPP_ */
