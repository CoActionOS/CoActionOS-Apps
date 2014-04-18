/*
 * Nes.cpp
 *
 *  Created on: May 1, 2013
 *      Author: tgil
 */

#include <unistd.h>
#include <stdio.h>
#include <applib/Pio.hpp>
#include "Nes.hpp"

#define LATCH_PORT 0
#define LATCH_PINMASK (1<<0)

#define DATA_PORT 0
#define DATA_PINMASK (1<<1)

#define PULSE_PORT (1)
#define PULSE_PINMASK (1<<22)


Nes::Nes() {
	// TODO Auto-generated constructor stub
	Pio latch(LATCH_PORT);
	Pio data(DATA_PORT);
	Pio pulse(PULSE_PORT);

	latch.init(LATCH_PINMASK, PIO_MODE_OUTPUT);
	pulse.init(PULSE_PINMASK, PIO_MODE_OUTPUT);
	data.init(DATA_PINMASK, PIO_MODE_INPUT);

	latch.clrmask(LATCH_PINMASK);
	pulse.clrmask(PULSE_PINMASK);
}


void Nes::refresh(void){
	Pio latch(LATCH_PORT);
	Pio data(DATA_PORT);
	Pio pulse(PULSE_PORT);
	int i;


	sample = 0xFF;

	latch.setmask(LATCH_PINMASK);
	usleep(12);
	latch.clrmask(LATCH_PINMASK);

	for(i = 0; i < 8; i++){
		if( data.get() & DATA_PINMASK ){
			sample &= ~(1<<i);
		}

		usleep(12);
		pulse.setmask(PULSE_PINMASK);
		usleep(12);
		pulse.clrmask(PULSE_PINMASK);
	}
}
