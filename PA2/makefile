CFLAGS=-g 

all:life

life: life.o game.o board.o
	gcc -o life life.o game.o board.o 
	
life.o: life.c
	gcc -c   life.c
	
game.o: game.c
	gcc -c game.c
	
board.o: board.c
	gcc -c board.c
	
clean:
	rm  *.o life
	