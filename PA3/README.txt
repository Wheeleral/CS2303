README.txt
PA3
Alexandra Wheeler

Description: This file will take in an output file and many input files. The program will then go through each file and obtain the words in it and put them into
a binary search tree. Duplicates will have their counter increased to know the number of occurances of the word. It will then write the tree in-order to the give
output file. At the end of the file it will show the number of total words and of distinct words. 

To compile type into the command line:
	make 
Or in eclipse type build.
Then to run the program type
	./PA3 outputfilename.txt inputfile1.txt inputfile2.txt ...
	Where outputfilname.txt is the name of the file to write the occurances to
	inputfile1.txt and so on are the input files
	
	And example is:
		./PA3 masqueOutput.txt MasqueOfTheRedDeath.txt

To read a file it must exist in the project or have the path be given to it.
		
Loop invariants:
	main.c
		main()
			The first loop invariant is the for loop:at end of loop the binary tree will have the words of file i in it
			The second loop invariant is the while loop:at end of each loop there will be a new word created
	StringManipulation.c
		stripWord()
			The loop invariant is:at the end of the loop it will have checked the ith char in the word