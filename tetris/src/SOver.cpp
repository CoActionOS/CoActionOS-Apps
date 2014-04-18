/*
 * SOver.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include "SOver.hpp"

SOver::SOver() {
	// TODO Auto-generated constructor stub

}

const char * SOver::name(){
	return "over";
}

bool SOver::entry_action(void){


	return true;
}

bool SOver::action(void){

	return true;
}

State * SOver::exit_condition(State * slist[]){
	State * next = 0;
	return next;
}
