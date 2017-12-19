/*
 * @file StringManipulation.h
 * @author Alexandra Wheeler
 * @date 21 Sept 2017
 * @brief  string manipulations
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* previous; /**< previous wrod for stripping the string */

/*
 * @brief *stripWord strips a given word of case and punctuation
 * @param *word is the word to get modified
 * @return returns the word that got stripped
 */
char * stripWord(char * word) {
	previous = malloc(strlen(word) + 1);
	int previousCount = 0;
	for (int i = 0; word[i]; i++) { //Loop Invariant: at the end of the loop it will have checked the ith char in the word
		char c = word[i];
		if (ispunct(c)) { //checks if the char is a punctuation type
			if (c == '\'') //checks the cases where the punctuation may be necessary
				previous[previousCount] = c;
			else if (c == '-') {
				if (isalpha(word[i - 1]) && isalpha(word[i + 1])) //check if each side of the - is an alphanumeric character
					previous[previousCount] = c;
				else
					previousCount--;
			} else
				previousCount--;
		} else {
			previous[previousCount] = tolower(c); //make the case lower
		}
		previousCount++;

	}

	return previous;

}
