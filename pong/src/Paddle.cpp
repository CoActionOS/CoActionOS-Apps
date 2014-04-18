/*
 * Paddle.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#include "Paddle.hpp"


int Paddle::deflect(int x, int y, int w, int h, int dir) const {

	if( x + w*dir/2 == xpos() ){
		//is ball incoming too high?
		if((y-h/2) > (ypos() + len) ){
			//too high
			return dir;
		}

		//is ball incoming too low?
		if((y+h/2) < (ypos() - len) ){
			//too high
			return dir;
		}

		return -1*dir;

	}

	return dir;
}

