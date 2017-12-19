/*
 * Board.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Organism.h"
#include <iostream>

class Board {
public:
	int size;
	Organism*** board;
	Board(int size);

	virtual ~Board();
	uint findemptyCell(int row, int column);
	bool prey(int row, int column);
	void print();
	uint antSpaces(int row, int col);
	bool isNull(int x, int y);
};

#endif /* BOARD_H_ */
