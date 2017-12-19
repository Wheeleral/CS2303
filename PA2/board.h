/*
 @file board.h
 * @author Alexandra Wheeler
 * @date 12 Sept 2017
 * @brief  utility functions header file
 */

#ifndef BOARD_H_
#define BOARD_H_

int rowSize;
int columnSize;

int compareBoard(char **new, char **old);
int compareAll(char** old, char** mid, char** new);
void printBoard(char** b);

#endif /* BOARD_H_ */
