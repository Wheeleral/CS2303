/*
 * @file sim.cpp
 * @author Alexandra Wheeler
 * @date 27 Sept 2017
 * @brief  main function
 */


//includes
#include "sim.h"

#include <queue>
#include <typeinfo>
#include "Customer.h"

int simTime = 0;/**< Total Simulation Time(Global)*/
float tServiceTime = 0;/**< Total Service Time (Global)*/
float tCustomerTime = 0;/**< Total Customer Time, amount of time all customers have spent at the bnak */
int maxWaitTime = 0;/**< maximum wait time a customer has waited */
int tIdleTime = 0;/**< Total Idle Time the Tellers have had*/
bool commonQueueLine = false; /**< If the simulation has a common Queue or not*/

TellerQueue tellers; //teller lines
EventQueue eventQueue; //total events
CommonQueue commonQueue; //single queue line

/*
 * @brief main, main function of the program
 * @param argc, number of arguments in the run command, should be at 5 or 6
 * @param argv[] array of the arguments, argv[0]is the program name, argv[1] = #customers,argv[2] =  #tellers,
 * 			argv[3] =  total simulationTime, argv[4] = averageServiceTime of the tellers, argv[5] =  <seed> for srand
 * @return returns 1 if the function went successfully, 0 if not
 *
 */
int main(int argc, char * argv[]) {

	//sets srand
	if (argc == 6)
		srand(atoi(argv[5]));
	else
		srand(time(NULL));

	//set values from argv[]
	int customers = atoi(argv[1]); /**< Number of customers*/
	int numTellers = atoi(argv[2]);/**< Number of Tellers*/
	float simulationTime = atof(argv[3]);/**<Simulation Time Total */

	float averageServiceTimes = atof(argv[4]);/**<Average Service time of tellers */
	Teller::averageServiceTime = averageServiceTimes; /**< set the static once*/

	//Simulation one

	//loopInvariant: The eventQueue will be one bigger each run through of the loop
	for (int i = 0; i < numTellers; i++) {
		Teller* t = new Teller();
		tellers.push(t);
		eventQueue.push(t);
	}

	//loopInvariant: The eventQueue will be one bigger each run through of the loop
	for (int i = 0; i < customers; i++) {
		Event * cust = new Customer((simulationTime * rand() / RAND_MAX) + 1);
		eventQueue.push(cust);
	}

	Event* currEvent;/**<Place Holder event for the one at the top of the stack */

	//loop Invariant: simTime will increase each run through of the loop
	while (simTime < simulationTime) { //simulation with a Queue per teller

		currEvent = eventQueue.top();

		//loop Invariant:At end of each run of the loop, it will get the top of the eventQueue(unless it's empty in which the while loop will end)
		while (simTime == currEvent->time) {
			currEvent->action();
			if (!eventQueue.empty()) {
				currEvent = eventQueue.top();
			}
		}
		simTime++;
	}

	cout << "The Number of Customers Served: " << customers << endl;
	cout << "Number of Tellers " << numTellers << " Tellers with a Queue Each"
			<< endl;
	cout << "The Average Time Spent in Bank: " << tCustomerTime / customers
			<< endl;
	cout << "The Total Service Time " << tServiceTime << endl;
	cout << "The Total Idle Teller Time: " << tIdleTime << endl;
	cout << "The Maximum wait time: " << maxWaitTime << endl;

	//reset the Simulation for Simulation 2
	maxWaitTime = 0;
	tCustomerTime = 0;
	tServiceTime = 0;
	tIdleTime = 0;
	simTime = 0;

	commonQueueLine = true;//change to using a common queue

	//loopInvariant: The eventQueue will be one smaller each run through of the loop
	while (!eventQueue.empty()) {
		eventQueue.pop();
	}

	//loopInvariant: The eventQueue will be one bigger each run through of the loop
	for (int i = 0; i < customers; i++) {
		Event * cust = new Customer((simulationTime * rand() / RAND_MAX) + 1);
		eventQueue.push(cust);
	}

	//loopInvariant: The eventQueue will be one bigger each run through of the loop
	for (int i = 0; i < numTellers; i++) {
		eventQueue.push(new Teller());
	}

	//loop Invariant: simTime will increase each run through of the loop
	while (simTime < simulationTime) { //Simulation with a common Queue

		currEvent = eventQueue.top();
		//loop Invariant:At end of each run of the loop, it will get the top of the eventQueue(unless it's empty in which the while loop will end)
		while (simTime == currEvent->time) {
			currEvent->action();
			if (!eventQueue.empty()) {
				currEvent = eventQueue.top();

			}

		}

		simTime++;
	}
	cout << "\n\n";
	cout << "The Number of Customers Served: " << customers << endl;
	cout << "Number of Tellers " << numTellers << " Tellers with a Common Queue"
			<< endl;
	cout << "The Average Time Spent in Bank: " << tCustomerTime / customers
			<< endl;
	cout << "The Total Service Time " << tServiceTime << endl;
	cout << "The Total Idle Teller Time: " << tIdleTime << endl;
	cout << "The Maximum wait time: " << maxWaitTime << endl;

}

