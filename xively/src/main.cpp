

#include <cstdio>
#include <applib/Timer.hpp>
#include <applib/Tmr.hpp>
#include <applib/Signal.hpp>

#include "Controller.hpp"


static void sketch(void);

int main(int argc, char * argv[]){

	printf("Hello Xively Board\n");
	Controller::init();
	sketch();
	return 0;
}



void sketch(void){
	Lcd lcd = Controller::lcd();
	Joystick j = Controller::joystick();
	unsigned int x, y;

	x = 10;
	y = 10;

	while( !j.center() ){

		if( j.left() && (x > 0) ){
			x--;
		}

		if( j.right() && (x < lcd.xmax()) ){
			x++;
		}

		if( j.up() && (y < lcd.ymax()) ){
			y++;
		}

		if( j.down() && (y > 0) ){
			y--;
		}

		lcd.setpixel(x,y);
		lcd.refresh();
		Timer::wait_msec(100);

	}

	lcd.clear();
	lcd.refresh();

}


