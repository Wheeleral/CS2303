/*
 * @file Teller.h
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  Teller object header file
 */

#ifndef TELLER_H_
#define TELLER_H_

#include <queue>
#include "Event.h"
#include "Customer.h"
using namespace std;

class Teller: public Event {
public:
	//variables
	static float averageServiceTime; /**<  There is only one of this object*/

	int time;
	int serviceTime;
	queue<Customer *> line; /**< Teller line*/


	Teller();
	virtual ~Teller();
	void action();
	void addCustomer();
};

#endif /* TELLER_H_ */
