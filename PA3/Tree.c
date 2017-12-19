/*
 *  @file Tree.c
 * @author Alexandra Wheeler
 * @date 21 Sept 2017
 * @brief  Binary Tree functions
 *
 */
//include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

int totalWords;/**< total number of words in the file(s) */
int distinctWords;/**< number of distinct words */
FILE *output;/**< file name of the output file */

/*
 * @brief *findItem finds the specified item from *w
 * @param *p the root node
 * @param *w is the word to be searching through the tree
 * @return returns the node the word can be found at
 * @note this function isn't used but here for debugging purposes
 */
Node *findItem(Node *p, char *w) {
	if (p == NULL) //if the item isn't here
		return NULL;
	int c = strcmp(w, p->word); //compares the current word value to the item to be searched

	if (c == 0)//if they're the same
		return p;
	else if (c < 0)//transverse the tree to find the item
		return findItem(p->left, w);
	else
		return findItem(p->right, w);
}

/*
 * @brief *addItem adds an item to the binary tree
 * @param *p is the root node
 * @param *w is the word to add to the tree or increment the counter
 * @return returns the root node
 * @note if *w is found in the tree it will increment the counter
 */
Node *addItem(Node *p, char *w) {
	totalWords++;

	if (p == NULL) { //if the node doesn't exist add it
		distinctWords++;
		p = malloc(sizeof(Node));
		char *c = malloc(strlen(w) + 1);//create the pointer for the word, which is the size of the length of the word +1

		p->word = strcpy(c, w); //set the struct values for the new node
		p->count = 1;
		p->left = p->right = NULL;

		return p;
	}
	int c = strcmp(w, p->word);//compare the node value to specified word
	if (c == 0)//if node exists increment the count of the word
		p->count++;
	else if (c < 0)
		p->left = addItem(p->left, w);
	else
		p->right = addItem(p->right, w);

	return p;
}
/*
 * @brief Prints out the tree to the open file.
 * @param *p is the root node
 * @note as the word is printed it will free the item.
 */
void printTreeItem(Node *p) {
	if (p == NULL)
		return;
	printTreeItem(p->left);//transverse the left
	fprintf(output, "%6d | %s\n", p->count, p->word);//print out the word
	printTreeItem(p->right);//transverse the right
	free(p->word);//frees the tree as it goes through
	free(p->left);
}

/*
 * @brief printTree will open the file , call printTreeItem and formats the bottom of the file
 * @param *p is the root node
 * @param *file is the file name to write to
 * @note will also close the file when finished with the function.
 */
void printTree(Node *p, char * file) {
	output = fopen(file, "w");//open th ouput file for writing (clears the file)
	printTreeItem(p);//print out the items
	//formats the bottom of the file
	fprintf(output, "---------------------------------------\n");
	fprintf(output, "Distinct Words: %d\n", distinctWords);
	fprintf(output, "Total Words: %d (Including Duplicates)", totalWords);
	fclose(output);
}
