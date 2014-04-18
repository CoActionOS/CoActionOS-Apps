/*
 * SMachine.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include "SMachine.hpp"
#include "SWelcome.hpp"
#include "SPlay.hpp"
#include "SPause.hpp"
#include "SOver.hpp"

SWelcome welcome;
SPlay play;
SPause pause;
SOver over;


State * states[] = {
		&welcome,
		&play,
		&pause,
		&over,
		0
};


SMachine::SMachine() : SMach(states, &welcome){
	// TODO Auto-generated constructor stub

}



void SMachine::run(void){
	SMach::exec(states, this);
}

bool SMachine::action(void){
	const int delay = 75;

	Timer::wait_msec(delay);
	//Controller::update();

	return SMach::action();
}
