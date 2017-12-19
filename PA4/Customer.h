/*
 * @file Customer.h
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  customer header file
 */


#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Event.h"
#include <cstdlib>

class Customer: public Event {
public:
	using Event::action;

	//variables for a customer
	bool complete;
	int arrivalTime;

	Customer(int time);
	virtual ~Customer();
	void action(void);

};
#endif /* CUSTOMER_H_ */
