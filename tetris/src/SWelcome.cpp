/*
 * SWelcome.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: tgil
 */

#include "SWelcome.hpp"

SWelcome::SWelcome() {
	// TODO Auto-generated constructor stub

}


const char * SWelcome::name(){
	return "welcome";
}

bool SWelcome::entry_action(void){
	printf("Enter Welcome\n");

	lcd().hold();

	printf("Hold LCD\n");
	//for now just draw a line
	lcd().line(0, 0, lcd().xmax(), lcd().ymax());

	printf("release LCD\n");
	lcd().release();

	printf("Release LCD\n");

	return true;
}

bool SWelcome::action(void){

	if( dpad().center() == true ){
		printf("pushed\n");
	}

	return true;
}

State * SWelcome::exit_condition(State * slist[]){
	State * next = 0;


	//wait for the user to push the center button
	if( dpad().center() == true ){
		next = find(slist, "play");
	}

	return next;
}

