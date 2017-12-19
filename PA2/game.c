/*
 *  @file game.c
 * @author Alexandra Wheeler
 * @date 10 Sept 2017
 * @brief  Make the board and plays the game
 */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"

int rowSize;
int columnSize;
int totalgen;
char **A;
char **B;
char **C;

/**
 * @brief setup sets up the boards, reads from the file and then calls play
 * @param *name is the name of the file to be read
 * @param print is a boolean 1 to print 0 to not
 * @param pause is a boolean 1 to print 0 to not
 * @note if the file doesn't exist or is empty it will end the function and stop.
 */
void setup(char *name, int print, int pause) {

	//create the 2d arrays
	A = malloc(rowSize * sizeof(char*));
	//loop invariant at end of each loop there will be another column added to each row.
	for (int i = 0; i < rowSize; i++) {
		A[i] = malloc(columnSize * sizeof(char));
	}
	B = malloc(rowSize * sizeof(char*));
	//loop invariant at end of each loop there will be another column added to each row.
	for (int j = 0; j < rowSize; j++) {
		B[j] = malloc(columnSize * sizeof(char));
	}
	C = malloc(rowSize * sizeof(char*));
	//loop invariant at end of each loop there will be another column added to each row.
	for (int k = 0; k < rowSize; k++) {
		C[k] = malloc(columnSize * sizeof(char));
	}

	FILE *input; //create a FILE for reading

	input = fopen(name, "r"); //read the file
	if (input == NULL) { //checks if the file is empty of non existent
		printf("File is empty or doesn't exit");
	} else {
		//variables for reading
		int r = 0; //current amount of elements in the row
		int cc = 0; //current amount of elements in the column
		int rmax = 0; //max amount of rows in the file
		int cmax = 0; //max amount of columns in the file
		char obtainC = 0; //char from file

		//get the size of the file
		//loop invariant outside:r is reset at end of loop
		//loop invariant inside:r increases at end of loop
		for (int x = 0; x < rowSize; ++x) {
			for (int y = 0; y < columnSize; ++y) {
				obtainC = fgetc(input);
				if (obtainC == EOF || obtainC == '\n') {
					break;
				} else {
					r++;
				}
			}
			if (r > rmax) {
				rmax = r;

			}
			r = 0;
		}

		rewind(input);		//reset the file reading

		char ch;		//get char from file
		//gets the amount of rows in the file
		//loop invariant: cmax will stay the same or increase if a '\n' was encountered
		while ((ch = fgetc(input)) != EOF) {
			if (ch == '\n')
				cmax++;
		}

		//center the array in the board
		int xstart = (rowSize - rmax) / 2;
		int ystart = (columnSize - cmax) / 2;
		rewind(input);

		//make the array's set with o's
		//loop invariant:each iteration of the loop will add a 'o' to the board
		for (int x = 0; x < rowSize; ++x)
			for (int y = 0; y < columnSize; ++y)
				A[x][y] = 'o';

		//loop invariant:each iteration of the loop will add a 'o' to the board
		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < columnSize; j++)
				B[i][j] = 'o';

		//loop invariant:each iteration of the loop will add a 'o' to the board
		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < columnSize; j++)
				C[i][j] = 'o';

		//add the array from the file to the board
		//loop invariant: at end of each loop obtainC will get the next character from the file
		for (int x = 0; x <= rmax; ++x) {
			for (int y = 0; y <= cmax; ++y) {
				obtainC = fgetc(input);
				if (obtainC == EOF || obtainC == '\n') { //checks if at end of file or newline character
					break;
				} else {
					A[x + xstart][y + ystart] = obtainC;
				}
			}
		}

		fclose(input); //close the file

		//print the inital board
		printBoard(A);
		printf(" \n \n  \n"); //add some spaces

		play(print, pause); //call play to evolve the board

	}
}

/**
 * @brief isNeigboor checks if the x, y of the array is an 'x'
 * @param **char is the array its checking the x and y of
 * @param x is the x coord of the array
 * @param y is the y coord of the array
 * @return returns 1 if it is an 'x' or 0 if not
 */
int isNeighboor(char ** curr, int x, int y) {
	if (curr[x][y] == 'x' || curr[x][y] == 'X') {
		return 1;
	}

	else {
		return 0;
	}
}
/*
 * @brief countNeighboors counts the nieghboors around the current cell
 * @param **curr is the current array
 * @param x current x coord of the cell
 * @param y current y coord of the cell
 * @return returns the total number of neighboors 0-8
 */
int countNeighboors(char ** curr, int x, int y) {
	//768
	//4 2
	//513

	int total = 0;
	if (x + 1 < rowSize) {
		// printf("1");
		total = total + isNeighboor(curr, x + 1, y);   //down
	}
	if (y + 1 < columnSize) {
		// printf("2");

		total = total + isNeighboor(curr, x, y + 1); //right
	}
	if (y + 1 < columnSize && x + 1 < rowSize) {
		// printf("3");

		total = total + isNeighboor(curr, x + 1, y + 1); //bottom right
	}
	if (y - 1 >= 0) {
		//printf("4");

		total = total + isNeighboor(curr, x, y - 1); //left
	}
	if (y - 1 >= 0 && x + 1 < rowSize) {
		//printf("5");

		total = total + isNeighboor(curr, x + 1, y - 1); //bottomleft
	}
	if (x - 1 >= 0) {
		// printf("6");

		total = total + isNeighboor(curr, x - 1, y); //up
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		// printf("7");

		total = total + isNeighboor(curr, x - 1, y - 1); //top left
	}
	if (x - 1 >= 0 && y + 1 < columnSize) {
		// printf("8");

		total = total + isNeighboor(curr, x - 1, y + 1); //topright
	}

	return total;
}

/*
 * @brief finished checks if the game is finished by surpassing the total number of generations or boards are the same
 * @param currentgen, the current generation the game is at
 * @param checkState Is which order the boards are called in compareAll
 * @return returns 1 if the game is still on, 0 if the boards are the same and 2 if the current generation has passed the total number of generations
 */
int finished(int currentgen, int checkState) {
	if (currentgen >= totalgen) { //out of gens
		return 2;
	}
	switch (checkState) { //which compareAll should be called
	case 0:
		if (compareAll(A, C, B) == 1) { //arrays are different
			return 1;
		} else { //arrays same
			return 0;
		}
		break;
	case 1:
		if (compareAll(B, A, C) == 1) {
			return 1;
		} else { //arrays same
			return 0;
		}
		break;
	case 2:
		if (compareAll(C, B, A) == 1) {
			return 1;
		} else { //arrays same
			return 0;
		}
		break;
	}
}
/*
 * @brief playone plays one generation of the game
 * @param **curr is the current board that will be checked
 * @param **new is the board that will be modified
 * @note the function will insert new x or o depending on countNeighboors
 */
void playone(char **curr, char **new) {
	//iterates through the curr array
	//loop invariant: a new countNeighboors will be created each run through
	for (int c = 0; c < columnSize; c++) {
		for (int r = 0; r < rowSize; r++) {
			int a = countNeighboors(curr, r, c); //get the amount of occupied nearby cells
			if (curr[r][c] == 'x') {
				if (a < 2 || a >= 4) { //death condition
					new[r][c] = 'o';
				} else { //surviving condition
					new[r][c] = 'x';
				}
			} else {
				if (a == 3) { //birth condition
					new[r][c] = 'x';
				}
			}

		}
	}
}
/*
 * @brief if the function calls for a pause it will call this function to wait until a char is hit
 * @note it says enter but any key and enter works
 */
void wait(void) {
	char c;
	printf("Hit enter to move to next generation ");
	c = getchar();
	printf("\n\n");
}

/*
 * @play will play through the generations until a termination condition is fulfilled
 * @param print, 1 means it will print the board between generations 0 it will not
 * @param pause, 1 it will pause between generations calling wait(), 0 it will not
 *
 */
void play(int print, int pause) {
	int currentgen = 1; //generation the program is at
	int state = 0; //state of which boards are "active"
	int fin = 0; // if the game is finished
	int finstate = 1; //how the game finished
	printf("Starting Game\n");
	//runs through the game
	//loop invariant: state will always increase and get modded by three at end of loop.
	while (fin == 0) {
		//which boards are active
		//0: A is going into B
		//1: B is going into C
		//2: C is going into A
		switch (state) {
		case 0: //A -> B
			playone(A, B);

			if (print == 1) { //if the board is to be printed
				printf("At %i generations\n", currentgen);
				printBoard(B);
			}

			if (pause == 1) //if the game is to wait
				wait();

			finstate = finished(currentgen, 0); //get if game is finished
			if (finstate == 0 || finstate == 2) {
				printf("Game finished after %i generations\n", currentgen);
				printBoard(B); //print final board
				if (finstate == 2) { //termination condition:number of generations
					printf(
							"Game went through the total number of generations\n");
				} else { //termination condition: boards were the same
					printf(
							"Game finished through previous iterations were the same\n");
				}
				fin = 1; //loop is finished
			}
			break;
		case 1: //B->C
			playone(B, C);

			if (print == 1) {
				printf("At %i generations\n", currentgen);
				printBoard(C);
			}

			if (pause == 1)
				wait();

			finstate = finished(currentgen, 1);
			if (finstate == 0 || finstate == 2) {
				printf("Game finished after %i generations\n", currentgen);
				printBoard(C);
				if (finstate == 2) {
					printf(
							"Game went through the total number of generations\n");
				} else {
					printf(
							"Game finished through previous iterations were the same\n");
				}
				fin = 1;
			}
			break;
		case 2: //c->A
			playone(C, A);

			if (print == 1) {
				printf("At %i generations\n", currentgen);
				printBoard(A);
			}

			if (pause == 1)
				wait();

			finished(currentgen, 2);
			if (finstate == 0 || finstate == 2) {
				printf("Game finished after %i generations\n", currentgen);
				printBoard(A);
				if (finstate == 2) {
					printf(
							"Game went through the total number of generations\n");
				} else {
					printf(
							"Game finished through previous iterations were the same\n");
				}
				fin = 1;
			}
			break;

		}

		currentgen++; //to next generation and beyond!
		state++;
		state = state % 3; //mod the states by three for the switch statement
	}

}
