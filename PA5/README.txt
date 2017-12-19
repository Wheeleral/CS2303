README.txt
PA5
Alexandra Wheeler

Description: This program will take a user inputted grid size, number of starting doodle bugs, number of starting ants, total time steps, seed number and 
number of steps for pausing. This a predator prey simulation in which the predator and prey move around and bred. The predator will eat the prey and die if they 
have not eaten recently. The program works from left to right and top to bottom. Each oragnaism will move and then breed, doodlebugs will do so first and then ants will.


To Compile:
In the console type 
	/.PA5 gridSize #doodlebugs #ants #time_steps seed pause
	
	All options are optional, and have defualt values otherwise, but they are optional running from the right and side. 
	<seed> is optional and is a number that will allow for the same random numbers each run
	
Loop Invariants:
	In PA5.cpp
		in anyDoodleBugs() and anyAnts, totalAnts and totalBugs-
			each iteration of the loop will obtain a new cell from the board
		in main (by order of appearance)
			an new ant will be placed each run of the for loop (line 176)
			a new cell will be checked each run of the while loop (line 178)
			an new bug will be placed each run of the for loop (line 191)
			a new cell will be checked each run of the while loop (line 193)
			each run through of the loop, the number of steps of each existing ant and doodlebug will increase(line 213)
			Another cell is checked for a doodlebug/Ant each iteration (line 218, 233, 250, 264)
	In Board.cpp
		constructor:
			a new row is added each iteration(line 20)
			at end of each iteration the k,m spot is set to null (line 25)
		destructor:
			each iterations deletes part of the array (line 36)
		print()
			Each iteration a new character and space is printed (line 119)
	In Ant.cpp
		breed()
			at end of loop will have a new random x each iteration (line 52)	
		move()
			at end of loop will have a new random x each iteration (line 87)
	In Doodlebug.cpp
		breed()
			at end of loop will have a new random x each iteration (line 56)	
		move()
			at end of loop will have a new random x each iteration (line 101, 137)



Sample Input:
./PA5 10 10 40 10 2 10

Sample Outut:
At Step: 0
* / / / / / / / * / 
/ / % / / / / % / * 
/ / * / / / % / / / 
/ * / / / * / / / / 
* / / % / / / / / / 
* * * * * / * % / / 
* / * * / * * / / / 
* * / / / / * / % / 
/ * / * / / % / % / 
/ * / / % / % / / / 



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Program Finished at 10 steps out of total of 10 steps
Started with 40 ants and 10 bugs on a 10x10 board with a seed of 2, pausing every 10 steps and 10 total Steps
Total Ants: 98
Total DoodleBugs: 17
Number of Ants remaining: 37
Number of DoodleBugs remaining: 3
Final Board
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* * * * * % / / / / 
* * * * / / / / / / 
* * * * / / / * / / 
* * * * / / * * / / 
% * * * / / * / * / 
* * % * / / * * * / 
* * / * / * / / / / 
* * / / / / / / / / 
/ / / / / / / / / / 
/ / / / / / / / / / 




Sample Input 2:
 ./PA5 20 10 100 5 


Sample Output 2:
At Step: 0
/ / / / / / / / * * / / / / / / / / / * 
* / / / / % / / * * / / / / * / / / / * 
/ / / / / / / % / * * / / / / / / / / * 
/ / / % / * / * / / * / / / * * / * * / 
/ / / / / * / / / / / / / * / / / / * / 
* / / / / / * / * % / / / * / / / / / / 
/ / / / * * / / * * * / / / / * / / * / 
% / / * * / / * / * / / / * / / / / * / 
/ * / * * / / * * / / * / * / / / * * / 
/ / / / * / / / / / / / / / * * / / / / 
* / / * / / / * / / / / / / * * / / / / 
/ / / / / / / * * * / / / / / / * / * / 
* / * * / / / / * * % / / / / / * * * / 
/ * / / / / % / / / / / / / / / * * / / 
/ / / / % / / * / / * / / / * / / * / / 
/ / / / / / * / / / / / / * / / / / * / 
* / * * / * / / % / / * * / / * / / * * 
/ * / / / / * / * / / * * / / * / / / / 
/ / / / % / * / / / / / * / / * / * / / 
/ / / / / / / * / / / / / / / / / / / / 

At Step: 1
/ / / / / / / * / / * * / / / / / / * / 
/ / * / % / * * / / * * * * / / / / * * 
/ / * / / / / / * / / / * / / / / / / / 
/ / / % / / / / / / / / / * * * * * * * 
/ / / % / / / * / * * / * / / / / * * / 
/ / / * * * / * % / * / * / / / / * / / 
/ * / * / / / / / / / * * * * / / * * / 
/ * * * / / * * / / / / / / / / / / / / 
/ / / * * / / / % * * / / * / / * * / / 
/ / / * * / / * / / / / / * / * / / / / 
% % / / * / / / / * / / / * / / * * / / 
/ / / * * / / * / * / / / / * / * * * * 
/ * / * / / * / / % / / / / / / * / / * 
* * / * / / / / / / / / / / / * * * / / 
* / / / % / % / / * / / / / / * * * * / 
/ * * / / / * * * * / / * / / / / / / / 
/ * * / / / / / % / * / / * * / / * / * 
/ * / / / * / / / / / * / * * * * / / / 
/ * / % / * / / / / * * / / / / * * / / 
/ / / * * / * / / / * * / / / / / / / / 

At Step: 2
/ / * / / / * / / * * * * / / / / * * / 
/ / / % / * / / / / / * * * / / * * * / 
/ * / / / / * / / * / / * * * / * * * * 
/ / / / / / / / / * / / * * * / / * / / 
/ / / / / / / % / * % * / / / / / / * / 
/ / / / / / / / / / % * / / / / / / * / 
* / / * * / * * / / * / * / / / * / * * 
* * / * * / * * / / % % / * * * / / / / 
/ / * / * / * / * * * * / * * * / / * * 
/ / * / / * * / / * / / / * * * * / * / 
/ / / / / / / / / / / / / / * * / * * * 
/ / / * / / / * * % / / / / * * / * / / 
/ / / / / * * / / / / / / / / * * * * / 
% / / / / / / / / / / / / / * * / * * * 
* * / / / / / / / % % / * * * / * / * * 
* * * * / / / / / / / * / / / / * * / / 
* * / / / / / / / * * * * * * * / * * / 
* / / / * / / / / / / * / / * * / * / / 
/ * * / * * / * * * / * / * * * / / / / 
/ / / % / / / / / * / / / / / / / / / / 

At Step: 3
/ * / / / / * / / * * * * * / / * * / / 
/ * / / / * * / / * * / / / * * * * / / 
/ / / / / * / / * * * * * / / * * * * / 
/ / / / * * / / / % % * * * / * * / / / 
/ / / / / / / / / / / / / / / / * * * / 
* / / / / / / * / / % / / / / / / * * / 
* * * * / * / / / / / / / / / % / / * * 
* * * * / * / / / / / / / / / % / / / * 
/ * * * * * * * / % / / / / / / * * * / 
/ / / / * * * / / / / / / / / * * * * * 
/ / / / / / / / / / / / / / * * / * / / 
/ / / / / / * / % * / / / / / / / / * / 
/ / * * / * / * * * / / / / / / * * * * 
/ / / / / / / / / / / / * % % * * * / / 
* / / / / / / / / % / / / * / * * * * / 
/ / * / / / / / / / / % * * * * / * * * 
% % * / * * / / / / / * * / * / * / * / 
/ * * * / / / / * / * * * * * / * / / / 
* / / * % / * / / * / * / * * / / / / / 
* / / / % / * * * * / / / / / / / / / / 

At Step: 4
* * * / / * * * * * * * / * * * * * * / 
* / / / / * / * * * * * / / * * * * * / 
/ / / / * / / * * % * / * * * * * * * / 
/ / / / / * / / * * * / % / / / / * / / 
* * / / / / / / / / / / / * * / * * / / 
* * / / / * * * * / % / / * * / * * / / 
/ * * * / / * / / / / / / / / / * / * / 
* * / * * / * * / % / / / / % / * * * / 
* * * * * * * * / / / / / / / / / * * * 
* * * / * / * / / / / / / / * / % * * * 
/ / * / / / * / / / / / / / * * * * * * 
/ / * / / / / * / / / / / * * / / / * * 
/ * / * * / / / % % / / / / / * * / / / 
/ / / / * / / / / / / / / * * * / / * * 
/ / / / / / / / / / / / / / * / / * / * 
/ / * / * / / / / / / / % * / / * * % * 
/ / * / * / / / / / / % % * / / / / % / 
/ / / % % / * * * * / / * * * * * / / / 
% * * / % / * * * * * / * * * / / / / / 
/ / * / / / * / * * / / / / / / / / * * 



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Program Finished at 5 steps out of total of 5 steps
Started with 100 ants and 10 bugs on a 20x20 board with a seed of 1, pausing every 1 steps and 5 total Steps
Total Ants: 272
Total DoodleBugs: 23
Number of Ants remaining: 157
Number of DoodleBugs remaining: 17
Final Board
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* * * / / * * * * * * * / * * * * * * / 
* / / / / * / * * * * * / / * * * * * / 
/ / / / * / / * * % * / * * * * * * * / 
/ / / / / * / / * * * / % / / / / * / / 
* * / / / / / / / / / / / * * / * * / / 
* * / / / * * * * / % / / * * / * * / / 
/ * * * / / * / / / / / / / / / * / * / 
* * / * * / * * / % / / / / % / * * * / 
* * * * * * * * / / / / / / / / / * * * 
* * * / * / * / / / / / / / * / % * * * 
/ / * / / / * / / / / / / / * * * * * * 
/ / * / / / / * / / / / / * * / / / * * 
/ * / * * / / / % % / / / / / * * / / / 
/ / / / * / / / / / / / / * * * / / * * 
/ / / / / / / / / / / / / / * / / * / * 
/ / * / * / / / / / / / % * / / * * % * 
/ / * / * / / / / / / % % * / / / / % / 
/ / / % % / * * * * / / * * * * * / / / 
% * * / % / * * * * * / * * * / / / / / 
/ / * / / / * / * * / / / / / / / / * * 

