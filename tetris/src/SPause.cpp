/*
 * SPause.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include "SPause.hpp"

SPause::SPause() {
	// TODO Auto-generated constructor stub

}

const char * SPause::name(){
	return "pause";
}

bool SPause::entry_action(void){


	return true;
}

bool SPause::action(void){

	return true;
}

State * SPause::exit_condition(State * slist[]){
	State * next = 0;
	return next;
}

