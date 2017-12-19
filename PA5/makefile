# Make file for Lab Exercise 2
# WRITTEN BY: Michael Main (main@colorado.edu), Jan 11, 1997
# MODIFIED BY:  Glynis Hamel 3/2/99
# MODIFIED BY:  Glynis Hamel 3/21/02
# MODIFIED BY:  Glynis Hamel 11/14/05 Converted from C++ to C
# MODIFIED BY:  Hugh Lauer 04/06/09 Substituted $(CFLAGS) for -g
# MODIFIED BY:	Hugh Lauer 08/18/13 Added -Wall and -m32 to CFLAGS
#
# This makefile is used as follows to regenerate files for the PA5 program:
#   make Board.o   --  Regenerates Board.o by compiling
#   make PA5.o   --  Regenerates PA5.o by compiling
#   make PA5     --  Regenerates the executable PA5 file by compiling
#   make              --  Same as "make PA5"
#

CFLAGS = -g

all: PA5

PA5: Board.o Ant.o Doodlebug.o Organism.o PA5.o
	g++ $(CFLAGS) -Wall PA5.o Board.o Ant.o Doodlebug.o Organism.o -o PA5 

Board.o: Board.h  Organism.h Board.cpp
	g++ $(CFLAGS) -Wall -c Board.cpp
	
Ant.o: Ant.h Board.h Organism.h  PA5.h  Ant.cpp
	g++ $(CFLAGS) -Wall -c Ant.cpp
	
Doodlebug.o: Doodlebug.h Board.h Organism.h  PA5.h Doodlebug.cpp
	g++ $(CFLAGS) -Wall -c Doodlebug.cpp
	
Organism.o: Organism.h Organism.cpp
	g++ $(CFLAGS) -Wall -c Organism.cpp
	
	
PA5.o: PA5.h Board.h PA5.cpp
	g++ $(CFLAGS) -Wall -c PA5.cpp

clean:
	rm -f PA5.o Board.o Ant.o Doodlebug.o Organism.o PA5


docs:
	doxygen


