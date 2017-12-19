/*
 * @file game.h
 * @author Alexandra Wheeler
 * @date 13 Sept 2017
 * @brief  header file for game.c
 */

#ifndef GAME_H_
#define GAME_H_
//global variables
int rowSize;
int columnSize;
int totalgen;
extern char **A;
extern char **B;
extern char **C;

//functions
void setup(char *input, int print, int pause);
void playone(char **curr, char **new);
int countNeighboors(char **curr, int x, int y);

int isNeighboor(char **curr, int x, int y);
void play(int print, int pause);
int finished(int currentgen, int checkState);
void wait(void);

#endif /* GAME_H_ */
