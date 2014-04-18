/*
 * SPause.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef SPAUSE_HPP_
#define SPAUSE_HPP_

#include <applib/State.hpp>

class SPause : public State {
public:
	SPause();
	const char * name();
	bool entry_action(void);
	bool action(void);
	State * exit_condition(State * slist[]);};

#endif /* SPAUSE_HPP_ */
