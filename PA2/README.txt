README FILE

PA2

Alexandra Wheeler
09/15/2017

README FILE


Description:
	This program is based off of James Conway's game of life. 
	It takes a text file of 'x' and 'o' and then converts that into an array that will evolve the board.
	
	To compile the program fun 
		make
	first, this will create .o and life files. 
	To get rid of these type:
		make clean
		
	To run the program type
		./life x y gen file print pause
		
	x and y are the size the game will play on
	gen is the number of genertaions that the program will play unless the board stops evolving
	file is the file name such as test.txt
	print is optional, 'y' is for if the program will print each generation 'n' is it won't
	pause is optional, 'y' is for the program to pause between generations 'n' is for it to go automatically
	
	So ./life 20 20 10 test.txt 
	Is the same as
		./life 20 20 10 test.txt n n 
		
		
Loop Invariants:
	board.c:
		In function compareBoard:  each iteration at end will move onto the next cell for both arrays
		In function printBoard:at end of each iteration there will be one more charactered printed
	game.c:
		In function setup:
			For creation of the arrays: at end of each loop there will be another column added to each row.
			Getting size of file: 
				outside:r is reset at end of loop
				inside:r increases at end of loop
			While loop for getting size: cmax will stay the same or increase if a '\n' was encountered
			Setting array A,B, C to all 'o': each iteration of the loop will add a 'o' to the board
			Adding array from file to board: at end of each loop obtainC will get the next character from the file
		In function playone:a new countNeighboors will be created each run through
		In function play:state will always increase and get modded by three at end of loop.
			