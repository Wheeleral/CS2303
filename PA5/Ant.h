/*
 * @file ant.h
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  prey class
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Board.h"
#include "PA5.h"
#include <iostream>

class Ant: public Organism {
public:
	Ant(int row, int column);
	virtual ~Ant();
	void breed(int row, int col);
	void move(int row, int col);
	bool isPrey();
	void print();

	string name;
private:
	int x, y;
	int step;
	bool breedable;
	const int breedingSteps = 3;
};

#endif /* ANT_H_ */
