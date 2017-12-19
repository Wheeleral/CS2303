/*
 * @file Board.cpp
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  Board class, contains all of the organisms
 */

#include "Board.h"

/*
 * @brief board constructor, creates a board object
 * @param sizeM, total size of the board
 * @return an board with sizeM, made of organisms
 */
Board::Board(int sizeM) {

	size = sizeM;
	board = new Organism**[size];
	//loop invariant: a new row is added each iteration
	for (int i = 0; i < size; i++) {
		board[i] = new Organism*[size];
	}

	//loop invariant:at end of each iteration the k,m spot is set to null
	for (int k = 0; k < size; k++) {
		for (int m = 0; m < size; m++) {
			board[k][m] = NULL;
		}
	}
}
/*
 * @brief  deletes a board object
 */
Board::~Board() {
	//loop invariant: each iterations deletes part of the array
	for (int i = 0; i < size; i++)
		delete[] board[i]; /* deleting first part of the array */
	delete[] board; /* deleting the array */
}


/*
 * @brief isNull, checks if that spot of the board is null
 * @param x, row of the board of the cell to check
 * @param x, row of the board of the cell to check
 * @return true if object is null, false if there is something there
 *
 */
bool Board::isNull(int x, int y) {
	if (this->board[x][y] == NULL)
		return true;
	else
		return false;
}

/*
 * @brief findemptyCell, checks if that spot of the board has nearby open cells
 * @param x, row of the board of the cell to check
 * @param x, row of the board of the cell to check
 * @return amount of the surrounding cells that are open
 */
uint Board::findemptyCell(int row, int column) {
	uint total = 0;
	if (row - 1 >= 0 && this->board[row - 1][column] == NULL)
		total += 1;

	if (row + 1 < this->size && this->board[row + 1][column] == NULL)
		total += 4;

	if (column - 1 >= 0 && this->board[row][column - 1] == NULL)
		total += 8;

	if (column + 1 < this->size && this->board[row][column + 1] == NULL)
		total += 2;
	return total;
}

/*
 * @brief antSpaces, checks if that spot of the board has ants nearby
 * @param x, row of the board of the cell to check
 * @param x, row of the board of the cell to check
 * @return amount of the surrounding cells that have ants
 */
uint Board::antSpaces(int row, int col) {
	uint total = 0;
	if (row - 1 >= 0 && board[row - 1][col] != NULL
			&& board[row - 1][col]->isPrey())
		total += 1;

	if (row + 1 < size && board[row + 1][col] != NULL
			&& board[row + 1][col]->isPrey())
		total += 4;

	if (col - 1 >= 0 && board[row][col - 1] != NULL
			&& board[row][col - 1]->isPrey())
		total += 8;

	if (col + 1 < size && board[row][col + 1] != NULL
			&& board[row][col + 1]->isPrey())
		total += 2;

	return total;
}
/*
 * @brief isNull, checks if that spot of the board is prey or not
 * @param x, row of the board of the cell to check
 * @param x, row of the board of the cell to check
 * @return true if the object is prey, false if not
 */
bool Board::prey(int row, int column) {
	return board[row][column]->isPrey();
}

/*
 * @brief print, prints the board
 */
void Board::print() {
	//loop invariant: Each iteration a new character and space is printed
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == NULL) {
				cout << "/ ";
			} else {
				board[i][j]->print();
			}
		}
		cout << endl;
	}
	cout << endl;
}

