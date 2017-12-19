/*
 * @file Tree.h
 * @author Alexandra Wheeler
 * @date 21 Sept 2017
 * @brief  Header for the Binary Tree functions
 */

#ifndef TREE_H_ //checks if header file is defined
#define TREE_H_


struct node {
	char *word;		///< part of payload, word string
	int count;			///< part of payload, count
	struct node *left, *right; ///<left and right nodes of the struct
};
typedef struct node Node;

//function declarations
Node *findItem(Node *p, char *w);
Node *addItem(Node *p, char *w);
void printTreeItem(Node *p);
void printTree(Node *p, char * file);


#endif /* TREE_H_ */
