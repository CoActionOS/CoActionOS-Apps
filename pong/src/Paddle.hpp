/*
 * Paddle.hpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#ifndef PADDLE_HPP_
#define PADDLE_HPP_


#include <applib/MLcd.hpp>

class Paddle {
public:
	Paddle(int xpos, int ypos, int ymin_pos, int ymax_pos, int length) : x_pos(xpos), y_pos(ypos),
	y_minpos(ymin_pos+length/2), y_maxpos(ymax_pos-length/2),

	len(length>>1){}

	void draw(MLcd * lcd){
		lcd->setvline(x_pos, y_pos - len, len*2);
	}

	inline int ypos() const { return y_pos; }
	inline void move(int v) {
		y_pos += v;
		if(y_pos > y_maxpos ){
			y_pos = y_maxpos;
		} else if(y_pos < y_minpos ){
			y_pos = y_minpos;
		}
	}

	inline int xpos() const { return x_pos; }
	int deflect(int x, int y, int w, int h, int dir) const;
	inline int length() const { return len<<1; }

private:
	const int x_pos;
	int y_pos;
	const int y_minpos;
	const int y_maxpos;
	int len;

};

#endif /* PADDLE_HPP_ */
