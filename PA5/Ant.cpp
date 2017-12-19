/*
 * @file ant.cpp
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  prey class
 */

#include "Ant.h"
/*
 * @brief ant constructor, creates an ant object
 * @param row, initial row it starts at
 * @param column, initial column is starts at
 * @return an ant with a number of steps, if breedable, x and y
 */
Ant::Ant(int row, int column) {
	// TODO Auto-generated constructor stub
	this->step = 0;
	this->breedable = false;
	this->x = row;
	this->y = column;
}

Ant::~Ant() {
}

/*
 * @brief isPrey, tells if the object is prey
 * @return true since it's an ant
 */
bool Ant::isPrey() {
	return true;
}

/*
 * @brief breed, breeds the ant, makes babies
 * @param row, row of the current ant
 * @param col, column of the current ant
 */
void Ant::breed(int row, int col) {
	uint emptycell;
	if (this->breedable == false) { //checks if breedable
		return;

	} else {
		emptycell = board->findemptyCell(row, col);
		if (emptycell == 0)
			return;

		int x;
		//loop invariant: at end of loop will have a new random x each iteration
		//gets a random number between 0 and 3 and checks if it is an emptycell
		while (true) {
			x = rand() % 4;
			if (1 << x & emptycell)
				break;
		}
		//breed ant
		if (x == 0) {
			board->board[row - 1][col] = new Ant(row - 1, col);
		} else if (x == 2) {
			board->board[row + 1][col] = new Ant(row + 1, col);

		} else if (x == 3) {
			board->board[row][col - 1] = new Ant(row, col - 1);

		} else { //3
			board->board[row][col + 1] = new Ant(row, col + 1);

		}
		totalAnt++;
		this->breedable = false;
		this->step = 0;

	}
}

/*
 * @brief move, moves the ant, makes exercise
 * @param row, row of the current ant
 * @param col, column of the current ant
 */
void Ant::move(int row, int col) {

	uint open = board->findemptyCell(row, col);
	if (open != 0) {
		int x;
		//loop invariant: at end of loop will have a new random x each iteration
		//gets a random number between 0 and 3 and checks if it is an emptycell
		while (true) {
			x = rand() % 4;
			if (1 << x & open)
				break;
		}
		//move to new square
		if (x == 0)//up
			board->board[row - 1][col] = this;
		else if (x == 2)//down
			board->board[row + 1][col] = this;
		else if (x == 3)//left
			board->board[row][col - 1] = this;
		else//right
			board->board[row][col + 1] = this;
		board->board[row][col] = NULL;
	} else
		board->board[row][col] = this;
	this->step++;
	if (this->step >= breedingSteps) {
		this->breedable = true;
		step = 0;
	}
}

/*
 * @brief print, how to print the object
 */
void Ant::print() {
	cout << "* ";
}
