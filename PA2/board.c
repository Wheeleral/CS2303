/*
 @file board.c
 * @author Alexandra Wheeler
 * @date 10 Sept 2017
 * @brief  utility functions
 */

//compare two boards
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
int rowSize;
int columnSize;

/**
 * @brief compareBoard will compare two boards to see if there are anything differnet between them
 * @param **new is the current board
 * @param **old is one of the old boards
 * @return returns 1 if the boards are different, 0 if they are the same
 */
int compareBoard(char **new, char **old) {
	//loop invariant: each iteration at end will move onto the next cell for both arrays
	for (int r = 0; r < rowSize; r++) {
		for (int c = 0; c < columnSize; c++) {

			if (old[r][c] != new[r][c]) {
				return 1;
			}
		}
	}
	return 0;
}

/*
 * @brief compareAll will compare the current board to the two old ones
 * @param **new is the current board
 * @param **old is an of the old board
 * @param **mid is another old board
 * @return returns 1 if the boards are the same, zero if they are different
 */
int compareAll(char **old, char ** mid, char ** new) {
	if (((compareBoard(new, mid)) == 1 && (compareBoard(new, old))) == 1) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * @brief prints out the given board
 * @param **b is the board to be printed
 */
void printBoard(char ** b) {
	//loop invariant: at end of each iteration there will be one more charactered printed
	for (int r = 0; r < rowSize; r++) {
		for (int c = 0; c < columnSize; c++) {

			printf("%c", b[r][c]);
		}
		printf("\n");
	}
	printf("\n \n  \n");
}
