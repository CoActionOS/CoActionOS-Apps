/*
 * Rgb.hpp
 *
 *  Created on: Dec 12, 2013
 *      Author: tgil
 */

#ifndef RGB_HPP_
#define RGB_HPP_

#include <applib/Pwm.hpp>

class Rgb {
public:
	Rgb();

	typedef struct {
		uint16_t r;
		uint16_t g;
		uint16_t b;
	} color_t;

	static int init();
	static void setcolor(uint16_t r, uint16_t g, uint16_t b);
	static inline void setcolor(color_t & color){ setcolor(color.r, color.g, color.b); }


private:
	static Pwm pwm;

	enum {
		RED_CHANNEL = 3,
		GREEN_CHANNEL = 2,
		BLUE_CHANNEL = 1
	};
};

#endif /* RGB_HPP_ */
