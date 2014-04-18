/*
 * Ball.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#include "Ball.hpp"

const uint8_t Ball::bitmap_mem[8] = {
		0x3C,
		0x7E,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0x7E,
		0x3C
};

Ball::Ball() : bitmap_var((const uint8_t*)bitmap_mem, 8, 8){

}

