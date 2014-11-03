/*
 * Test.hpp
 *
 *  Created on: Oct 22, 2014
 *      Author: tgil
 */

#ifndef TEST_HPP_
#define TEST_HPP_

#include <applib/Timer.hpp>

class Test {
public:
	Test();

	void start(const char * name);
	void stop(bool passed, const char * desc = 0);
	inline void passed(){ stop(true); }
	inline void failed(const char * desc){ stop(false, desc); }
	uint32_t elapsed();
	void update();

private:
	Timer t;
};

#endif /* TEST_HPP_ */
