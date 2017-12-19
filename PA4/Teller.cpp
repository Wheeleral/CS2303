/*
 * @file Teller.cpp
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  Teller object
 */


#include "Teller.h"

#include "sim.h"

float Teller::averageServiceTime = 0;

/*
 * @brief constructor, creates a teller object
 * @return Teller, has a ID, idle time and service time.
 */
Teller::Teller() {

	iD += 500; //adding 500 to the id, to signify a teller
	tIdleTime = 1;
	this->time = 10;
	serviceTime = 0;
}

/*
 * @brief destructor, deletes a teller object
 */
Teller::~Teller() {
	// TODO Auto-generated destructor stub
}

/*
 * @brief action, completes the action of a teller
 * @note this function overrides the one in event
 */
void Teller::action(void) {
	Event* t = eventQueue.top();
	eventQueue.pop();//gets the top of the queue and pops it
	if (line.empty()) { //checks if the teller line is empty

		if (commonQueueLine && !commonQueue.empty()) {
			//if there is a common queue adds the customer event to a teller line
			line.push(commonQueue.top());
			commonQueue.pop();
			action();

		}
		//idle time
		serviceTime = 150 * rand() / float(RAND_MAX) + 1;
		t->time = simTime + serviceTime;
		tIdleTime += serviceTime;
		eventQueue.push(t);

	} else {//service the customer.
		serviceTime = 2 * averageServiceTime * rand() / float(RAND_MAX);

		tServiceTime += serviceTime;
		Customer* c = line.front();
		maxWaitTime = max(maxWaitTime, simTime - c->arrivalTime);

		c->time = simTime + serviceTime;
		c->complete = true;
		t->time = simTime + serviceTime;

		eventQueue.push(c);
		eventQueue.push(t);

		line.pop();
	}

}

