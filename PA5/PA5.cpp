/*
 * @file PA5.cpp
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  main function
 */

#include "PA5.h"

//variables
Board * board;/**< Overall Board(Global)*/

int totalAnt;/**< Total number of Ants throughout the simulation(Global)*/
int totalBug;/**< Total number of Doodlebugs throughout the simulation(Global)*/
int size, numAnt, numBug, timeTotal, pause, seed; /**< Variables From command Line*/
int finalStep, remAnt, remBug;/**< Variables for deliverables*/

/*
 * @brief anyDoodlebugs, see's if there are any doodlebugs on the board
 * @return returns true if there are, false if not
 *
 */
bool anyDoodleBugs() {
	//loop invariant:each iteration of the loop will obtain a new cell from the board
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {

			if (!board->isNull(row, col)) {
				Organism* critter = board->board[row][col];

				bool prey = critter->isPrey();
				if (prey == false) {
					return true;
				}
			}
		}
	}
	return false;
}

/*
 * @brief anyAnts, see's if there are any ants on the board
 * @return returns true if there are, false if not
 *
 */
bool anyAnts() {
	//loop invariant:each iteration of the loop will obtain a new cell from the board
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {

			if (!board->isNull(row, col)) {
				Organism* critter = board->board[row][col];

				bool prey = critter->isPrey();
				if (prey == true) {
					return true;
				}
			}
		}
	}
	return false;
}

/*
 * @brief totalDoodlebugs, obtains the amount of doodelbugs on the board
 * @return total, the number of doodlebugs on the board
 *
 */
int totalDoodleBugs() {
	int total = 0;
	//loop invariant:each iteration of the loop will obtain a new cell from the board
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {

			if (!board->isNull(row, col)) {
				Organism* critter = board->board[row][col];

				bool prey = critter->isPrey();
				if (prey == false) {
					total++;
				}
			}
		}
	}
	return total;
}

/*
 * @brief totalAnts, obtains the amount of doodelbugs on the board
 * @return total, the number of doodlebugs on the board
 *
 */
int totalAnts() {
	int total = 0;
	//loop invariant:each iteration of the loop will obtain a new cell from the board
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {

			if (!board->isNull(row, col)) {
				Organism* critter = board->board[row][col];

				bool prey = critter->isPrey();
				if (prey == true) {
					total++;
				}
			}
		}
	}
	return total;
}

/*
 * @brief main, main function of the program
 * @param argc, number of arguments in the run command, should be between 1 and 7
 * @param argv[] array of the arguments, argv[0]is the program name, argv[1] = gridsize ,argv[2] =  #doodlebugs,
 * 			argv[3] = #ants, argv[4] = #time_steps of the tellers, argv[5] =  <seed> for srand, argv[6] = when program should pause(in steps)
 * @return returns 1 if the function went successfully, 0 if not
 *
 */
int main(int argc, char* argv[]) {

	totalAnt = 0;
	totalBug = 0;

	//parse the command arguments
	cout << "Start" << endl;
	if (argc >= 2)
		size = atoi(argv[1]);
	else
		size = 20;

	if (argc >= 3) {
		numBug = atoi(argv[2]);
		totalBug += numBug;
	} else {
		numBug = 5;
		totalBug += numBug;
	}
	if (argc >= 4) {
		numAnt = atoi(argv[3]);
		totalAnt += numAnt;

	} else {
		numAnt = 100;
		totalAnt += 100;
	}
	if (argc >= 5)
		timeTotal = atoi(argv[4]);
	else
		timeTotal = 1000;

	if (argc >= 6) {
		if (atoi(argv[5]) == 0) {
			srand(time(NULL));
			seed = (time(NULL));
		} else {
			srand(atoi(argv[5]));
			seed = atoi(argv[5]);
		}
	} else {
		srand(1);
		seed = 1;
	}
	if (argc >= 7)
		if (atoi(argv[5]) == 0)
			pause = 1;
		else
			pause = atoi(argv[6]);
	else
		pause = 1;

	//make board
	board = new Board(size);

	//loop invariant: an new ant will be placed each run of the for loop
	for (int ants = 0; ants < numAnt; ants++) {
		//loop invariant: a new cell will be checked each run of the while loop
		while (true) {

			int row = rand() % board->size;
			int col = rand() % board->size;

			if (board->isNull(row, col)) {
				board->board[row][col] = new Ant(row, col);
				break;
			}
		}
	}

	//loop invariant: an new bug will be placed each run of the for loop
	for (int bugs = 0; bugs < numBug; bugs++) {
		//loop invariant: a new cell will be checked each run of the while loop
		while (true) {
			int row = rand() % board->size;
			int col = rand() % board->size;

			//if (board->board[row][col] == NULL)
			if (board->isNull(row, col))

			{
				board->board[row][col] = new Doodlebug(row, col);
				break;
			}
		}
	}

	//Start the Simulation
	//cout << "Starting Board" << endl;
	//	board->print();
	cout << endl;

	//loop invariant: each run through of the loop, the number of steps of each existing ant and doodlebug will increase
	for (int gen = 0; gen < timeTotal; gen++) {

		//DOODLEBUG

		//loop invariant: Another cell is checked for a doodlebug each iteration
		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {
				Organism* critter = board->board[row][col]; //get organism from the cell

				if (!board->isNull(row, col)) { //checks if cell is null

					bool prey = critter->isPrey(); //checks if prey or not
					if (prey == false) {

						critter->move(row, col); //move
					}
				}
			}
		}

		//loop invariant: Another cell is checked for a doodlebug each iteration
		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {
				Organism* critter = board->board[row][col];

				if (!board->isNull(row, col)) {
					bool prey = critter->isPrey();
					if (prey == false) {
						critter->breed(row, col);
					}
				}

			}
		}

		//ANT

		//loop invariant: Another cell is checked for an ant each iteration
		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {

				Organism* critter = board->board[row][col];
				if (!board->isNull(row, col)) {
					bool prey = critter->isPrey();
					if (prey == true) {
						critter->move(row, col);
					}
				}
			}
		}

		//loop invariant: Another cell is checked for an ant each iteration
		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {

				Organism* critter = board->board[row][col];
				if (!board->isNull(row, col)) {
					bool prey = critter->isPrey();
					if (prey == true) {
						critter->breed(row, col);
					}
				}
			}
		}

		if (gen % pause == 0) { //check if the board needs to be printed
			cout << "At Step: " << gen << endl;
			board->print();

		}
		if ((!anyDoodleBugs() || !anyAnts())) { //sees if there are no ants or bugs
			finalStep = gen;
			break;
		} else {
			finalStep = timeTotal;
		}

	}

	//output
	cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
			<< endl;
	//calculate the number of bugs remaining
	remAnt = totalAnts();
	remBug = totalDoodleBugs();
	cout << "Program Finished at " << finalStep << " steps out of total of "
			<< timeTotal << " steps" << endl;
	cout << "Started with " << numAnt << " ants and " << numBug << " bugs on a "
			<< size << "x" << size << " board with a seed of " << seed
			<< ", pausing every " << pause << " steps and " << timeTotal
			<< " total Steps" << endl;
	cout << "Total Ants: " << totalAnt << endl;
	cout << "Total DoodleBugs: " << totalBug << endl;
	cout << "Number of Ants remaining: " << remAnt << endl;
	cout << "Number of DoodleBugs remaining: " << remBug << endl;
	cout << "Final Board" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
			<< endl << endl;
	board->print();

}

