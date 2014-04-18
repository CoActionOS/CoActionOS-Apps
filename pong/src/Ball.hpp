/*
 * Ball.hpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#ifndef BALL_HPP_
#define BALL_HPP_

#include <applib/MBitmap.hpp>
#include <applib/MLcd.hpp>


class Ball {
public:
	Ball();

	inline int xpos() const { return x_pos; }
	inline int ypos() const { return y_pos; }
	inline int deltax() const { return delta_x; }
	inline int deltay() const { return delta_y; }

	inline void setpos(int x, int y) { x_pos = x; y_pos = y; }
	inline void setdeltax(int v) { delta_x = v; }
	inline void setdeltay(int v) { delta_y = v; }
	inline int width(){ return bitmap_var.width(); }
	inline int height(){ return bitmap_var.height(); }

	void draw(MLcd * lcd){
		lcd->setbitmap(&bitmap_var, x_pos-4, y_pos+3);
	}

private:
	int x_pos;
	int y_pos;
	int delta_x; //speed in x dir
	int delta_y; //speed in y dir
	const MBitmap bitmap_var;
	static const uint8_t bitmap_mem[8];

};

#endif /* BALL_HPP_ */
