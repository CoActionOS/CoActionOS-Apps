/*
 * IO.hpp
 *
 *  Created on: Dec 13, 2013
 *      Author: tgil
 */

#ifndef IO_HPP_
#define IO_HPP_

#include <applib/Pin.hpp>
#include <applib/Adc.hpp>

namespace Input {

enum {
	JOY_PORT = 0,
	JOY_LEFT = 15,
	JOY_RIGHT = 24,
	JOY_DOWN = 17,
	JOY_UP = 23,
	JOY_CENTER = 16,
	JOY_MASK = (1<<JOY_LEFT)|(1<<JOY_RIGHT)|(1<<JOY_DOWN)|(1<<JOY_UP)|(1<<JOY_CENTER)
};


class JoyUp : public Pin { public: JoyUp(): Pin(JOY_PORT,23){}; };
class JoyDown : public Pin { public: JoyDown(): Pin(JOY_PORT,17){}; };
class JoyLeft : public Pin { public: JoyLeft(): Pin(JOY_PORT,15){}; };
class JoyRight : public Pin { public: JoyRight(): Pin(JOY_PORT,24){}; };
class JoyCenter : public Pin { public: JoyCenter(): Pin(JOY_PORT,16){}; };


enum {
	POT1_CHANNEL = 4,
	POT2_CHANNEL = 5
};
}

namespace Output {
class LcdReset : public Pin { public: LcdReset(): Pin(0,8){}; };
}

#endif /* IO_HPP_ */
