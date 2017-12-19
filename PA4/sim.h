/*
 * @file sim.h
 * @author Alexandra Wheeler
 * @date 27 Sept 2017
 * @brief  main function header file
 */

#ifndef SIM_H_

#include "Event.h"
#include "Teller.h"
#include <iostream>

using namespace std;// makes outputing information easier

//data values
extern int maxWaitTime;
extern float tServiceTime;
extern float tCustomerTime;
extern int simTime;
extern int tIdleTime;
extern bool commonQueueLine;

//comparators for priority queue
class TellerComparator {
public:
	bool operator()(Teller* t1, Teller* t2) {
		return t1->line.size() > t2->line.size();
	}
};

//comparator for customers and priority queue
class CustomerComparator {
public:
	bool operator()(Event *c1, Event *c2) {
		return c1->time > c2->time;
	}
};


//priority queues
typedef std::priority_queue<Customer*, std::vector<Customer*>,
		CustomerComparator> CommonQueue; /**< If there is a common queue line, customers are in here*/

typedef std::priority_queue<Teller*, std::vector<Teller*>, TellerComparator> TellerQueue; /**< Teller lines, to tell what is shortest*/

typedef std::priority_queue<Event*, std::vector<Event*>, CustomerComparator> EventQueue; /**<Event Queue, order of total event */

//make the queues global
extern TellerQueue tellers;
extern EventQueue eventQueue;
extern CommonQueue commonQueue;

#endif /* SIM_H_ */
