/*
 * Lcd.hpp
 *
 *  Created on: Dec 13, 2013
 *      Author: tgil
 */

#ifndef LCD_HPP_
#define LCD_HPP_

#include <applib/Nhdc12832.hpp>

class Lcd : public Nhdc12832 {
public:
	enum {
		SPI_PORT = 1,
		CS_PORT = 0,
		CS_PIN = 18,
		A0_PORT = 0,
		A0_PIN = 6,
		SPI_PINASSIGN = 0,
		SPI_FREQ = 4000000
	};

	Lcd() : Nhdc12832(SPI_PORT,CS_PORT,CS_PIN,A0_PORT,A0_PIN){};
	int init(){ return Nhdc12832::init(SPI_FREQ, SPI_PINASSIGN); }
};

#endif /* LCD_HPP_ */
