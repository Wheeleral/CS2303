/*
 * @file doodlebug.cpp
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  predator class
 */
#include "Doodlebug.h"
#include "PA5.h"
/*
 * @brief doodlebug constructor, creates an doodlebug object
 * @param row, initial row it starts at
 * @param column, initial column is starts at
 * @return a dodolebug with a number of steps, if breedable, x and y, and when it last ate
 */
Doodlebug::Doodlebug(int row, int column) {
	// TODO Auto-generated constructor stub
	this->step = 0;
	this->breedable = false;
	this->x = row;
	this->y = column;
	this->lastEaten = 0;
}
/*
 * @brief  deletes an doodlebug object
 */
Doodlebug::~Doodlebug() {
}
/*
 * @brief isPrey, tells if the object is prey
 * @return false since it's an doodlebug, its the predator
 */
bool Doodlebug::isPrey() {
	return false;
}

/*
 * @brief breed, breeds the doodlebug, makes babies
 * @param row, row of the current doodlebug
 * @param col, column of the current doodlebug
 */
void Doodlebug::breed(int row, int col) {
	uint emptycell;
	if (this->breedable == false) {
		return;

	} else {
		emptycell = board->findemptyCell(row, col);
		if (emptycell == 0) {
			return;

		}

		int x;
		//loop invariant: at end of loop will have a new random x each iteration
		//gets a random number between 0 and 3 and checks if it is an emptycell
		while (true) {
			x = rand() % 4;
			if (1 << x & emptycell)
				break;
		}
		//creates spawn
		if (x == 0) {
			board->board[row - 1][col] = new Doodlebug(row - 1, col);
		} else if (x == 2) {
			board->board[row + 1][col] = new Doodlebug(row + 1, col);

		} else if (x == 3) {
			board->board[row][col - 1] = new Doodlebug(row, col - 1);

		} else { //1
			board->board[row][col + 1] = new Doodlebug(row, col + 1);

		}
		totalBug++;
		this->breedable = false;
		this->step = 0;

	}
}

/*
 * @brief move, moves the doodlebug, makes exercise
 * @param row, row of the current doodlebug
 * @param col, column of the current doodlebug
 */
void Doodlebug::move(int row, int col) {
	if (this->lastEaten >= 3) //starve
			{
		delete this;
		board->board[row][col] = NULL;
		return;
	}
	uint ants = board->antSpaces(row, col);
	uint open = board->findemptyCell(row, col);
	if (ants != 0) {
		//eats an ant and moves

		int x;
		//loop invariant: at end of loop will have a new random x each iteration
		//gets a random number between 0 and 3 and checks if it is an emptycell
		while (true) {
			x = rand() % 4;
			if (1 << x & ants)
				break;
		}
		if (x == 0) {
			delete board->board[row - 1][col];
			board->board[row - 1][col] = NULL;
			board->board[row - 1][col] = this;
		} else if (x == 2) {
			delete board->board[row + 1][col];
			board->board[row + 1][col] = NULL;
			board->board[row + 1][col] = this;

		} else if (x == 3) {
			delete board->board[row][col - 1];
			board->board[row][col - 1] = NULL;
			board->board[row][col - 1] = this;

		} else {
			delete board->board[row][col + 1];
			board->board[row][col + 1] = NULL;
			board->board[row][col + 1] = this;

		}
		board->board[row][col] = NULL;
		this->lastEaten = 0;
		this->step++;
		if (this->step >= StepsForBreeding)
			this->breedable = true;
		return;
	} else if (open != 0) {
		//no ants nearby
		int x;
		//loop invariant: at end of loop will have a new random x each iteration
		//gets a random number between 0 and 3 and checks if it is an emptycell
		while (true) {
			x = rand() % 4;
			if (1 << x & open)
				break;
		}
		if (x == 0)
			board->board[row - 1][col] = this;
		else if (x == 2)
			board->board[row + 1][col] = this;
		else if (x == 3)
			board->board[row][col - 1] = this;
		else
			board->board[row][col + 1] = this;
		board->board[row][col] = NULL;
		this->step++;
		if (this->step >= StepsForBreeding) {
			this->breedable = true;
			this->step = 0;
		}
		this->lastEaten++;

	} else {		//no where to move
		board->board[row][col] = this;

		this->step++;
		if (this->step >= StepsForBreeding) {
			this->breedable = true;
			this->step = 0;
		}
		this->lastEaten++;
	}

}

/*
 * @brief print, how to print the object
 */
void Doodlebug::print() {
	cout << "% ";
}
