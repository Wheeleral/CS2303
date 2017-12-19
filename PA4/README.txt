README.txt
qSim
Alexandra Wheeler

Description: This program will take a user inputted number of tellers, customers, total simulation 
time, average service time, and optionally a seed. It will run a simulation of customers ariving and 
being helped by tellers. This simulation will run twice. The first will be with a line for each teller
the second will be with a common queue for all tellers. The program will then output the number of customers 
served, the number of tellers, the average time spent in bank, the total service time, the total idle teller
 time, and the maximum wait time.
Information on priority queue was taken from https://stackoverflow.com/questions/19535644/how-to-use-the-priority-queue-stl-for-objects

To Compile:
In the console type 
	./qSim #customers #tellers simulationTime averageServiceTime <seed>
	
	<seed> is optional and is a number that will allow for the same random numbers each run
	
	If the program doesn't compile, then cd into the Debug folder of the project and rerun the code
Loop Invariants:
	In sim.cpp main()
		For the four for loops that create the tellers and customers
			The eventQueue will be one bigger each run through of the loop
		For the while loop of the simulation time(shows twice)
			simTime will increase each run through of the loop
		For the for loop in the while loop(shows twice)
			At end of each run of the loop, it will get the top of the eventQueue(unless it's empty in which the while loop will end)
				

Example Input and Output:
Input:
./qSim 100 4 60 2.3 10

Output:
The Number of Customers Served: 100
Number of Tellers 4 Tellers with a Queue Each
The Average Time Spent in Bank: 3.26
The Total Service Time 168
The Total Idle Teller Time: 58
The Maximum wait time: 6


The Number of Customers Served: 100
Number of Tellers 4 Tellers with a Common Queue
The Average Time Spent in Bank: 2.84
The Total Service Time 178
The Total Idle Teller Time: 127
The Maximum wait time: 7


Analysis:
Run 1:
./qSim 100 4 60 2.3 10
The Number of Customers Served: 100
Number of Tellers 4 Tellers with a Queue Each
The Average Time Spent in Bank: 3.26
The Total Service Time 168
The Total Idle Teller Time: 58
The Maximum wait time: 6


The Number of Customers Served: 100
Number of Tellers 4 Tellers with a Common Queue
The Average Time Spent in Bank: 2.84
The Total Service Time 178
The Total Idle Teller Time: 127
The Maximum wait time: 7


Run 2:
./qSim 100 10 60 2.3 10
The Number of Customers Served: 100
Number of Tellers 10 Tellers with a Queue Each
The Average Time Spent in Bank: 2.45
The Total Service Time 164
The Total Idle Teller Time: 393
The Maximum wait time: 4


The Number of Customers Served: 100
Number of Tellers 10 Tellers with a Common Queue
The Average Time Spent in Bank: 2.45
The Total Service Time 206
The Total Idle Teller Time: 373
The Maximum wait time: 4


Run3:
 ./qSim 100 2 60 2.3 10
The Number of Customers Served: 100
Number of Tellers 2 Tellers with a Queue Each
The Average Time Spent in Bank: 9.78
The Total Service Time 112
The Total Idle Teller Time: 1
The Maximum wait time: 27


The Number of Customers Served: 100
Number of Tellers 2 Tellers with a Common Queue
The Average Time Spent in Bank: 3.09
The Total Service Time 172
The Total Idle Teller Time: 71
The Maximum wait time: 6

The common queue is better when there are a lower number of tellers, The more tellers the less effective it is. 
