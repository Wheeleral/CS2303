/*
 * @file Organism.cpp
 * @author Alexandra Wheeler
 * @date 8 Oct 2017
 * @brief  Organism abstract class
 */

#include "Organism.h"
/*
 * @brief constructor, creates a organism object
 * @return Organism
 * @note this is an abstract class
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}
/*
 * @brief destructor, destroys a organism object
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

/*
 * @brief move
 */
void Organism::move(int row, int col) {
	cout << "Wrong" << endl;
}
/*
 * @brief  breed
 */
void Organism::breed(int row, int col) {
	cout << "Wrong" << endl;

}
/*
 * @brief  getName
 */
void Organism::getName() {
	cout << "Wrong" << endl;

}
/*
 * @brief  print
 */
void Organism::print() {
	cout << "wrong" << endl;
}

/*
 * @brief isPrey, shouldn't be used
 */
bool Organism::isPrey() {
	return false;
}
