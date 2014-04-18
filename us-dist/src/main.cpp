#include <cstdio>

#
#include <applib/Timer.hpp>
#include <applib/Tmr.hpp>
#include <applib/Pin.hpp>
#include <applib/Dac.hpp>
#include <applib/coactionhero.h>

int main(int argc, char * argv[]){
	Timer t;
	int timeout;

	Pin trigger(COACTION_EXP_PIO1_PORT, COACTION_EXP_PIO1_PINMASK, true);
	Pin echo(COACTION_EXP_PIO0_PORT, COACTION_EXP_PIO0_PINMASK, true);

	trigger.init(PIO_MODE_OUTPUT);
	echo.init(PIO_MODE_INPUT);


	while(1){
		//Create a pulse on the trigger
		trigger.set();
		Timer::wait_usec(100);
		trigger.clr();

		//wait until the echo goes high
		timeout = 0;
		while( echo.isclr() && (timeout < 10000) ){
			timeout++;
		}

		//Measure the width of the pulse
		t.start();
		timeout = 0;
		while( echo.isset() && (timeout < 10000)){
			timeout++;
		}
		t.stop();

		if( timeout == 10000 ){
			printf("Timeout\n");
		}

		//The pulse width is proportional to the distance
		printf("Distance is %d\n", (int)t.value());

		Timer::wait_msec(100);

	}



	return 0;
}

