/*
 * TPiece.hpp
 *
 *  Created on: May 2, 2013
 *      Author: tgil
 */

#ifndef TPIECE_HPP_
#define TPIECE_HPP_


#include <applib/MLcd.hpp>
#include <stdlib.h>

class TPiece {
public:
	TPiece();

	void rotate(bool cc);

	enum Block {
		ONE,
		TWO,
		THREE,
		FOUR
	};

	enum PType {
		L,
		J,
		LONG,
		T,
		Z,
		S,
		SQUARE
	};

	void reset(void);

	inline uint8_t xpos(uint8_t b) const {
		if( b < 4){
			return  x_pos[b];
		} else {
			return 0;
		}
	}
	inline uint8_t ypos(uint8_t b) const {
		if( b < 4){
			return  y_pos[b];
		} else {
			return 0;
		}
	}

	void move(int dirx, int diry);




private:
	//int rotation;
	uint8_t x_pos[4];
	uint8_t y_pos[4];

	static const int8_t rot_sin[4];
	static const int8_t rot_cos[4];


};

#endif /* TPIECE_HPP_ */
