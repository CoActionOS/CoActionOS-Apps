/*
 * Pong.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: tgil
 */

#include <cstdio>
#include <cstring>
#include "Pong.hpp"

Pong::Pong(int x1, int y1, int x2, int y2, MLcd * lcd, Nes * c1, Nes *c2) :
p1((x2-x1) / 10, (y2-y1)/2,
		y1+1, y2,
		8),

		p2((x2-x1) - (x2-x1) / 10, (y2-y1)/2,
				y1+1, y2,
				8){
	// TODO Auto-generated constructor stub


	this->c1 = c1;
	this->c2 = c2;
	xmin = x1;
	ymin = y1;
	xmax = x2;
	ymax = y2;
	this->lcd = lcd;

	p1_score = 0;
	p2_score = 0;
	showscore = false;

	ball.setpos((xmax-xmin)/2, (ymax-ymin)/2);
	ball.setdeltax(1);
	ball.setdeltay(1);

}

void Pong::update(void){
	//update the ball position
	int x, y;
	int tmp;
	char buffer[32];

	if( showscore == true ){
		sprintf(buffer, "Score:%d %d", p1_score, p2_score);
		//lcd->setstr(buffer, false, (xmax-xmin)/2 - strlen(buffer)*4, (ymax-ymin)/2 - 4);
		if( c1 != 0 ){
			c1->refresh();
			if( c1->isstart() ){
				showscore = false;
			}
		}

		if( c2 != 0 ){
			c2->refresh();
			if( c2->isstart() ){
				showscore = false;
			}
		}

		if( showscore ){
			draw();
			return;
		} else {
			ball.setpos((xmax-xmin)/2, (ymax-ymin)/2);
		}
	}


	x = ball.xpos();
	y = ball.ypos();
	x += ball.deltax();

	//check for a deflection
	ball.setdeltax( p1.deflect(x, y, ball.width(), ball.height(), ball.deltax()) );
	ball.setdeltax( p2.deflect(x, y, ball.width(), ball.height(), ball.deltax()) );

	//check for a score
	tmp = ball.width()/2;
	if( (x + tmp > xmax) ){
		//score
		showscore = true;
		p1_score++;
	}

	if( (x - tmp < xmin) ){
		//score
		showscore = true;
		p2_score++;
	}

	//check for bouncing off the top/bottom
	y += ball.deltay();
	tmp = ball.height()/2;
	if( y + tmp >= ymax ){
		y = ymax - tmp;
		ball.setdeltay( ball.deltay() * -1 );
	} else if( y - tmp <= ymin ){
		y = ymin + tmp;
		ball.setdeltay( ball.deltay() * -1 );
	}

	ball.setpos(x,y);

	if( c1 == 0 ){
		//update p1 paddle
		if( (ball.deltax() < 0) && (ball.xpos() < (xmax-xmin)/2) ){
			if( ball.ypos() > p1.ypos() ){
				p1.move(1);
			} else if( ball.ypos() < p1.ypos() ){
				p1.move(-1);
			}
		}
	} else {
		c1->refresh();
		if( c1->isup() ){
			p1.move(1);
		} else if( c1->isdown() ){
			p1.move(-1);
		}
	}

	if( c2 == 0 ){
		if( (ball.deltax() > 0) && (ball.xpos() > (xmax-xmin)*5/6) ){
			if( ball.ypos() > p2.ypos() ){
				p2.move(1);
			} else if( ball.ypos() < p2.ypos() ){
				p2.move(-1);
			}
		}
	} else {
		c2->refresh();
		if( c2->isup() ){
			p2.move(1);
		} else if( c2->isdown() ){
			p2.move(-1);
		}
	}

	draw();

}


void Pong::draw(void){

	//redraw
	lcd->sethline(xmin, ymin, xmax-xmin);
	lcd->sethline(xmin, ymax, xmax-xmin);
	ball.draw(lcd);
	p1.draw(lcd);
	p2.draw(lcd);

}

