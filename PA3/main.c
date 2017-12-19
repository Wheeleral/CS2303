/*
 * @file main.h
 * @author Alexandra Wheeler
 * @date 21 Sept 2017
 * @brief  main function
 */
//include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Tree.h"
#include "StringManipulation.h"

int maxWordSize = 100; /**< max size a word can be */
Node* root; /**< current root of the tree */


/*
 * @brief main, main function of the program
 * @param argc, number of arguments in the run command, should be at least three
 * @param argv[] array of the arguments, argv[0]is the program name, argv[1] is the output file destination, the rest are the files to parse
 * @return returns 1 if the function went successfully, 0 if not
 *
 */
int main(int argc, char* argv[]) {
	if (argc < 3) { //sees if the arguments are less than what is needed
		printf("Too few arguments, need at least three had onle %i\n", argc);
		return 0;
	}

	char *Word; /**< word from file */
	Word = malloc(maxWordSize * sizeof(char*));/**< create word array that is the maxWordSize */
	int i = 2;
	for (i = 2; i < argc; i++) { //loop Invariant: at end of loop the binary tree will have the words of file i in it
		FILE *f = fopen(argv[i], "r");

		if (f == NULL) { //checks if file is empty
			printf("Unknown File at %s\n", argv[i]);
			return 0;
		}
		while (!feof(f)) { //Loop invariant: at end of each loop there will be a new word created

			fscanf(f, "%s", Word); //get a word from the file
			Word = stripWord(Word); //strip it of punctuation and case
			if (strcmp(Word, ""))
				root = addItem(root, Word);
		}
		fclose(f);
	}
	free(Word); //word is no longer necessary

	printTree(root, argv[1]); //print the tree
	printf("Printed Successfully to output file %s", argv[1]);
	return 0;

}

