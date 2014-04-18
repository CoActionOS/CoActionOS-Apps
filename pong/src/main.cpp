#include <cstdio>
#include <unistd.h>

//LCD object
#include <applib/ExpLcdDevice.hpp>
#include <applib/Font8.hpp>

//NES object
#include "Nes.hpp"

//Pong class
#include "Pong.hpp"


int main(int argc, char * argv[]){
	Nes nes;
	ExpLcdDevice lcd;
	Pong pong(0, 0, lcd.width(), lcd.ymax(), &lcd, &nes);
	Font8 font;

	font.load("/home/font7x7.f8");
	lcd.init();
	lcd.setfont(&font);

	do {
		lcd.clear();
		pong.update();
		lcd.refresh();
		usleep(25*1000);
	} while( !nes.isselect());

	lcd.clear();


	return 0;
}
