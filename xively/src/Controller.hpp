/*
 * Controller.hpp
 *
 *  Created on: Dec 13, 2013
 *      Author: tgil
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <applib/Timer.hpp>
#include "Lcd.hpp"
#include "Joystick.hpp"
#include "Rgb.hpp"

/*! \brief Controller Class
 * \details This class controls all hardware access.
 *
 */
class Controller {
public:
	Controller();


	/*! \brief Initialize the hardware */
	static int init(void);

	static Lcd & lcd(){ return lcd_; }
	static Joystick & joystick(){ return joystick_; }
	static Rgb & rgb(){ return rgb_; }

private:
	static Lcd lcd_;
	static Joystick joystick_;
	static Rgb rgb_;

};

#endif /* CONTROLLER_HPP_ */
