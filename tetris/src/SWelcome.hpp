/*
 * SWelcome.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef SWELCOME_HPP_
#define SWELCOME_HPP_

#include <applib/State.hpp>

#include "Controller.hpp"

class SWelcome : public State, public Controller {
public:
	SWelcome();
	const char * name();
	bool entry_action(void);
	bool action(void);
	State * exit_condition(State * slist[]);

};

#endif /* SWELCOME_HPP_ */
