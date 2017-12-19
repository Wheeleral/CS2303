/*
 * @file life.c
 * @author Alexandra Wheeler
 * @date 15 Sept 2017
 * @brief  Game of Life from James Conway, takes an input board and evolves it.
 * @brief main file of the project, includes the main.
 */
//includes
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

/**
 * @brief main function takes in 4-6arguments from the command line
 * @param argc Number of arguments
 * @param argv[1] X size of the board, rowSize
 * @param argv[2] Y size of the board, columnSize
 * @param argv[3] totalgen, Maximum number of generations that to board can be
 * @param argv[4] file name
 * @param argv[5] print 'y' or 'n'
 * @param argv[6] pause 'y' or 'n'
 */
int main(int argc, char *argv[]) {
	int pause = 0;
	int print = 0;

	//global variables
	extern int rowSize;
	extern int columnSize;
	extern int totalgen;

	//check if the number of arguments are correct
	if (argc < 5) {
		printf("To few arguments");
		return 0;
	}
	if (argc > 7) {
		printf("To many arguments");
	}

	rowSize = atoi(argv[1]); //convert from char to int
	columnSize = atoi(argv[2]);
	totalgen = atoi(argv[3]);

	//set print and pause if they were included in the command argument
	if (argc == 7) {
		if (*argv[6] == 'y') {
			pause = 1;
		}
		if (*argv[5] == 'y') {
			print = 1;
		}

	} else if (argc == 6) {
		if (*argv[5] == 'y') {
			print = 1;
		}

	}

	//call function setup in game.c
	setup(argv[4], print, pause);

//free(A);
//free(B);
//free(C);
}
