/*
 * @file Customer.cpp
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  main function
 */


#include "Customer.h"

#include "sim.h"

/*
 * @brief constructor, creates a customer object
 * @param time, arrival time of the customer
 * @return Customer, has a arrival time and knows if is a completed task or not
 *
 */
Customer::Customer(int time) {
	this->time = time;
	this->arrivalTime = time;
	complete = false;
//doesn't need an id, b/c each customer is an event and each event has an id
}

/*
 * @brief destructor, destroys a customer object
 * @return Nothing, frees the memory of the customer
 *
 */
Customer::~Customer() {
	// TODO Auto-generated destructor stub
}


/*
 * @brief action, completes the action of a customer
 * @note this function overrides the one in event
 * @note this function will delete the customer object when the function is done
 */
void Customer::action(void) {
	eventQueue.pop();

	if (!this->complete) {//sees if the customer is a completed(their service is done)

		if (commonQueueLine) { //sends to common queue
			commonQueue.push(this);

		} else {//sends to shortest teller
			Teller* shortest = tellers.top();
			shortest->line.push(this);
			tellers.pop();
			tellers.push(shortest);
		}

	} else {
		tCustomerTime += (simTime - arrivalTime);
		delete this;
	}
}


