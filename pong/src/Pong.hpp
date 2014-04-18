/*
 * Pong.hpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#ifndef PONG_HPP_
#define PONG_HPP_

#include <applib/MLcd.hpp>
#include <applib/Font8.hpp>

#include "Nes.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

class Pong {
public:
	Pong(int x1, int y1, int x2, int y2, MLcd * lcd, Nes * c1, Nes * c2 = 0);

	void update(void);

private:
	int xmin;
	int ymin;
	int xmax;
	int ymax;
	Ball ball;
	Paddle p1;
	Paddle p2;
	MLcd * lcd;
	Nes * c1;
	Nes * c2;
	void draw(void);
	int p1_score;
	int p2_score;
	bool showscore;

};

#endif /* PONG_HPP_ */
