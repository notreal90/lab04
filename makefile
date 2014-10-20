#Student ID: 4903077
#Name: Matthew McAlpine
#CS2010 Fall 2014
#Lab Assignment 4

dict: main.o inoutstuff.o
	g++ main.o inoutstuff.o -o dict

main.o: inoutstuff.o
	g++ -c main.cpp
	
inoutstuff.o:
	g++ -c inoutstuff.cpp

clean:
	rm *.o dict
