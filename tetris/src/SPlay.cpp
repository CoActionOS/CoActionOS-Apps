/*
 * SPlay.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include <applib/Timer.hpp>
#include "SPlay.hpp"

SPlay::SPlay() {
	// TODO Auto-generated constructor stub

	level = 0;
	lines = 0;

	down_counter = 0;
	x_min = 0;
	x_max = 0;
	y_min = 0;
	y_max = 0;
	bwidth = 0;
}

const char * SPlay::name(){
	return "play";
}

bool SPlay::entry_action(void){
	int game_width;
	int game_height;

	printf("clear LCD?\n");
	lcd().clear();
	lcd().hold();
	//for now just draw a line
	lcd().line(lcd().xmax(), lcd().ymax(), 0, 0);
	lcd().release();


	bwidth = 1;

	do {
		bwidth++;
	} while( bwidth*COLUMNS < lcd().width() );

	bwidth--;

	printf("Block width is %d\n", bwidth);

	game_width = bwidth*COLUMNS;
	game_height = bwidth*ROWS;
	printf("Total width is %d of %d\n", game_width, lcd().width());

	x_min = (lcd().width() - game_width) / 2;
	x_max = x_min + game_width - 1; //x_max includes the position of the right-most piece
	y_min = (lcd().height() - game_height) / 2;
	y_max = y_min + game_height;

	//Start with a new piece
	piece.reset();
	piece.move(0, -4);

	down_counter = 0;

	return true;
}

bool SPlay::action(void){

	//update the gameplay


	//remove piece from board because it is about to move
	setpiece(false);

	if( dpad().left() ){
		if( !iscollision(-1, 0) ){
			piece.move(-1, 0);
		}
	}

	if( dpad().right()  ){
		if( !iscollision(1, 0) ){
			piece.move(1, 0);
		}
	}

	if( dpad().center() ){
		piece.rotate(true);
		if( iscollision(0, 0) ){
			piece.rotate(false);
		}
	}

	/*
			if( ctrl->isB() ){
				piece.rotate(false);
				if( iscollision(0, 0) ){
					piece.rotate(true);
				}
			}
	 */

	/*
			if( ctrl->isstart() ){

				//wait for start to be released
				do {
					ctrl->refresh();
					usleep(50*1000);
				} while( ctrl->isstart() );

				usleep(100*1000);

				lcd->clear();
				lcd->setstr("PAUSED", 10, 50);
				lcd->refresh();

				do {
					ctrl->refresh();
					usleep(50*1000);
				} while( !ctrl->isstart() );

				//wait for start to be released
				do {
					ctrl->refresh();
					usleep(50*1000);
				} while( ctrl->isstart() );

			}
	 */


	//check for collision
	down_counter++;
	if( dpad().down()  ){
		if( !iscollision(0, -1) ){
			piece.move(0, -1);
		} else {
			setpiece();
			updatelayout();
			piece.reset();
		}

	} else {
		if( down_counter >= 24 / (level+1) ){
			down_counter = 0;
			//move piece down
			if( !iscollision(0, -1) ){
				piece.move(0,-1); //move down
			} else {
				setpiece();
				updatelayout();
				piece.reset();
			}
		}
	}
	setpiece();
	draw();

	return true;
}

State * SPlay::exit_condition(State * slist[]){
	State * next = 0;

	//transition to pause?

	return next;
}

void SPlay::updatelayout(void){
	int i, j;
	int k, l;
	for(j=0; j < ROWS; j++){
		for(i=0; i < COLUMNS; i++){
			if( layout[j][i] == false ){
				break;
			}
		}
		if( i == COLUMNS ){
			//this is a solid line
			lines++;
			if( (lines % 10) == 0 ){
				level++;
			}
			for(l=j; l < ROWS; l++){
				for(k=0; k < 10; k++){
					if( l < (ROWS - 1) ){
						layout[l][k] = layout[l+1][k];
					} else {
						layout[l][k] = false;
					}
				}
			}
			draw();
			Timer::wait_msec(100);
			j--; //have j repeat this line since everything moved
		}
	}
}


bool SPlay::iscollision(int dirx, int diry){
	//check if piece will collide if moved in dirx
	int i;
	int x, y;
	for(i=0; i < 4; i++){
		x = piece.xpos(i) + dirx;
		y = piece.ypos(i) + diry;

		if( x< 0 ){
			return true;
		}

		if( x >= COLUMNS ){
			return true;
		}

		if ( y < 0 ){
			return true;
		}

		if( y >= ROWS ){
			return true;
		}

		//does it collide with anything in the layout
		if( layout[y][x] == true ){
			if( y >= (ROWS - 3) ){
				lcd().clear();
				//lcd->setstr("GAME OVER!!!", 0, 50);
			}

			return true;
		}

	}

	return false;

}

void SPlay::setpiece(bool enabled){
	int i;
	int x, y;
	for(i=0; i < 4; i++){
		x = piece.xpos(i);
		y = piece.ypos(i);
		if ( x < 0 ){
			printf("X < 0 error!\n");
			exit(1);
		}

		if ( x >= COLUMNS ){
			printf("X > 9 error!\n");
			exit(1);
		}

		if ( y < 0 ){
			printf("Y < 0 error!\n");
			exit(1);
		}

		if ( y >= ROWS ){
			printf("Y > 22 error!\n");
			exit(1);
		}

		layout[piece.ypos(i)][piece.xpos(i)] = enabled;
	}
}

void SPlay::draw(void){
	int i, j;
	char buffer[16];
	lcd().clear();
	lcd().hold();

	for(i=0; i < 10; i++){
		for(j=0; j < 20; j++){
			if( layout[j][i] == true ){
				drawblock(j, i);
			}
		}
	}


	//draw the decoration
	lcd().sethline(x_min-1, x_max + 1, y_min-1);
	lcd().setvline(x_max+1, y_min, y_max + 1);
	lcd().setvline(x_min-1, y_min, y_max + 1);

	sprintf(buffer, "%d : %d", level, lines);
	//lcd->setstr(buffer, x_min + 2, y_min-9);

	lcd().refresh();
}

void SPlay::drawblock(int r, int c){
	int x,y;
	int i,j;
	x = c*bwidth + x_min;
	y = r*bwidth + y_min;
	for(i=0; i < bwidth; i++){
		for(j=0; j < bwidth; j++){
			lcd().pixel(x+i, y+j);
		}
	}

}
