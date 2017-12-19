/*
 * @file doodlebug.h
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  predator class
 */
#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Board.h"
#include <iostream>

class Doodlebug: public Organism {
public:
	Doodlebug(int row, int column);
	virtual ~Doodlebug();
	void breed(int row, int col);
	void move(int row, int col);
	bool isPrey();
	void print();

private:
	int x, y;
	int step;
	bool breedable;
	int lastEaten;

	const int StepsForBreeding = 8;
};

#endif /* DOODLEBUG_H_ */
