/*
 * TPiece.cpp
 *
 *  Created on: May 2, 2013
 *      Author: tgil
 */

#include "TPiece.hpp"

const int8_t TPiece::rot_sin[4] = {
		0,
		1,
		0,
		-1
};

const int8_t TPiece::rot_cos[4] = {
		1,
		0,
		-1,
		0
};

TPiece::TPiece() {
	// TODO Auto-generated constructor stub

}

void TPiece::move(int dirx, int diry){
	int i;
	for(i=0; i < 4; i++){
		x_pos[i] += dirx;
		y_pos[i] += diry;
	}
}

void TPiece::reset(void){
	int xref = 4;
	int yref = 20;
	int t;

	t = rand() % 7;


	switch(t){
	case L:
		x_pos[1] = xref; y_pos[1] = yref;
		x_pos[0] = xref; y_pos[0] = yref-1; //center of mass
		x_pos[2] = xref; y_pos[2] = yref-2;
		x_pos[3] = xref + 1; y_pos[3] = yref-2;
		break;
	case J:
		x_pos[1] = xref; y_pos[1] = yref;
		x_pos[0] = xref; y_pos[0] = yref-1; //center of mass
		x_pos[2] = xref; y_pos[2] = yref-2;
		x_pos[3] = xref - 1; y_pos[3] = yref-2;
		break;
	case LONG:
		x_pos[1] = xref-2; y_pos[1] = yref;
		x_pos[0] = xref; y_pos[0] = yref; //center of mass
		x_pos[2] = xref-1; y_pos[2] = yref;
		x_pos[3] = xref+1; y_pos[3] = yref;
		break;
	case T:
		x_pos[1] = xref; y_pos[1] = yref+1;
		x_pos[0] = xref; y_pos[0] = yref; //center of mass
		x_pos[2] = xref+1; y_pos[2] = yref;
		x_pos[3] = xref-1; y_pos[3] = yref;
		break;
	case Z:
		x_pos[1] = xref-1; y_pos[1] = yref;
		x_pos[0] = xref; y_pos[0] = yref; //center of mass
		x_pos[2] = xref; y_pos[2] = yref-1;
		x_pos[3] = xref+1; y_pos[3] = yref-1;
		break;
	case S:
		x_pos[1] = xref+1; y_pos[1] = yref;
		x_pos[0] = xref; y_pos[0] = yref; //center of mass
		x_pos[2] = xref; y_pos[2] = yref-1;
		x_pos[3] = xref-1; y_pos[3] = yref-1;
		break;
	case SQUARE:
		x_pos[0] = xref; y_pos[0] = yref; //center of mass
		x_pos[1] = xref; y_pos[1] = yref-1;
		x_pos[2] = xref+1; y_pos[2] = yref;
		x_pos[3] = xref+1; y_pos[3] = yref-1;
		break;
	}
}

void TPiece::rotate(bool cc){
	int i;
	int x1;
	int y1;
	int rc;
	int rs;
	int rotation;
	int xref, yref;

	if( cc ){
		rotation = 3;
	} else {
		rotation = 1;
	}

	xref = x_pos[0];
	yref = y_pos[0];
	rc = rot_cos[rotation];
	rs = rot_sin[rotation];
	for(i = 0; i < 4; i++){
		x1 = (x_pos[i] - xref) * rc - (y_pos[i] - yref) * rs;
		y1 = (x_pos[i] - xref) * rs + (y_pos[i] - yref) * rc;
		x_pos[i] = x1 + xref;
		y_pos[i] = y1 + yref;
	}
}

