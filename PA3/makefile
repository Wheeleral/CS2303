CFLAGS=-g 

all:PA3

PA3: main.o Tree.o StringManipulation.o
	gcc -o PA3 main.o Tree.o StringManipulation.o
	
main.o: main.c
	gcc -c   main.c
	
Tree.o: Tree.c
	gcc -c Tree.c

StringManipulation.o: StringManipulation.c
	gcc -c StringManipulation.c

clean:
	rm  *.o PA3
	
docs:
	doxygen