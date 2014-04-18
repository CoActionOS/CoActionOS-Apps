/*
 * SMachine.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#ifndef SMACHINE_HPP_
#define SMACHINE_HPP_

#include <applib/SMach.hpp>
#include <applib/Timer.hpp>


class SMachine : public SMach {
public:
	SMachine();
	void run();
	bool action();
};

#endif /* SMACHINE_HPP_ */
