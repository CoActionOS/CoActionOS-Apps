/*
 * SPlay.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef SPLAY_HPP_
#define SPLAY_HPP_

#include <applib/State.hpp>
#include "Controller.hpp"
#include "TPiece.hpp"

class SPlay : public State, public Controller {
public:
	SPlay();
	const char * name();
	bool entry_action(void);
	bool action(void);
	State * exit_condition(State * slist[]);
private:

	enum {
		ROWS = 22,
		COLUMNS = 10
	};

	TPiece piece;
	uint8_t layout[ROWS][COLUMNS];

	bool orient_top;

	inline int translate_y(int y){
		if( orient_top ){
			return lcd().height() - y;
		}

		return y;
	}

	bool iscollision(int dirx, int diry);
	void updatelayout(void);
	void setpiece(bool enabled = true);
	void drawblock(int r, int c);
	void draw(void);

	uint8_t x_min;
	uint8_t x_max;
	uint8_t y_min;
	uint8_t y_max;
	uint8_t bwidth;

	int lines;
	int level;

	int down_counter;

};

#endif /* SPLAY_HPP_ */
