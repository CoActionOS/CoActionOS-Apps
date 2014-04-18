/*
 * Tetris.hpp
 *
 *  Created on: May 2, 2013
 *      Author: tgil
 */

#ifndef TETRIS_HPP_
#define TETRIS_HPP_

#include <applib/MLcd.hpp>
#include <cstring>

#include "Nes.hpp"
#include "TPiece.hpp"

class Tetris {
public:
	Tetris(MLcd * lcd, Nes * ctrl){
		this->ctrl = ctrl;
		this->lcd = lcd;
		x_min = 5;
		x_max = lcd->xmax() - 3;
		y_min = 8;
		y_max = lcd->ymax();
		bwidth = 4;

		lines = 0;
		level = 0;
		memset(layout, 0, 22*10);
	}

	void run(void);



private:

	enum {
		ROWS = 22,
		COLUMNS = 10
	};

	TPiece piece;
	//Nes * ctrl;

	bool iscollision(int dirx, int diry);
	void updatelayout(void);
	void setpiece(bool enabled = true);
	void drawblock(int r, int c);
	void draw(void);
	uint8_t layout[22][10];
	MLcd * lcd;

	int lines;
	int level;

	uint8_t x_min;
	uint8_t x_max;
	uint8_t y_min;
	uint8_t y_max;
	uint8_t bwidth;

};

#endif /* TETRIS_HPP_ */
