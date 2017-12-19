/*
 * @file Organism.h
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  Organism abstract class
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <iostream>

using namespace std;
class Organism {
public:

	Organism();
	virtual ~Organism();
	virtual void move(int row, int col);
	virtual void breed(int row, int col);
	virtual bool isPrey();
	virtual void getName(); //don't want
	virtual void print();

};

#endif /* ORGANISM_H_ */
