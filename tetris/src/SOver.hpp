/*
 * SOver.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef SOVER_HPP_
#define SOVER_HPP_

#include <applib/State.hpp>

class SOver : public State {
public:
	SOver();
	const char * name();
	bool entry_action(void);
	bool action(void);
	State * exit_condition(State * slist[]);
};

#endif /* SOVER_HPP_ */
