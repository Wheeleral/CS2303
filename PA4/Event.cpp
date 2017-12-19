/*
 * @file Event.cpp
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  Event object
 */

#include "Event.h"
#include <iostream>

int Event::Id = 0;

Event::Event() {
	duration = 0;
	time = 5;
	iD = Id;
	Id++;
}

Event::~Event() {
	// TODO Auto-generated destructor stub
}
void Event::action() {
	std::cout << "not this kind of action" << std::endl;
}
