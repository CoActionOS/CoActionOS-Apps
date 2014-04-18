/*
 * Nes.hpp
 *
 *  Created on: May 1, 2013
 *      Author: tgil
 */

#ifndef NES_HPP_
#define NES_HPP_

#include <stdint.h>

class Nes {
public:
	Nes();


	bool isA(){ return sample & (1<<A); }
	bool isB(){ return sample & (1<<B); }
	bool isselect(){ return sample & (1<<SELECT); }
	bool isstart(){ return sample & (1<<START); }
	bool isup(){ return sample & (1<<UP); }
	bool isdown(){ return sample & (1<<DOWN); }
	bool isleft(){ return sample & (1<<LEFT); }
	bool isright(){ return sample & (1<<RIGHT); }

	void refresh(void);

private:

	enum {
		A,
		B,
		SELECT,
		START,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	uint8_t sample;


};

#endif /* NES_HPP_ */
