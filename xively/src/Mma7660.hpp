/*
 * Mma7660.hpp
 *
 *  Created on: Dec 13, 2013
 *      Author: tgil
 */

#ifndef MMA7660_HPP_
#define MMA7660_HPP_

class Mma7660 {
public:
	enum {
		I2C_PORT = 2,
		I2C_FREQ = 400000
	};

	Mma7660();
};

#endif /* MMA7660_HPP_ */
