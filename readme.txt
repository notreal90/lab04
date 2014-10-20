Student ID: 4903077
Name: Matthew McAlpine
CS2010 Fall 2014
Lab Assignment 4


This project reads from the cin and counts how many times a word appears.
Any non alpha character is both ignored and treated as a new word.

The makefile should be properly configured so using make from this directory should work fine.
It compiles as "dict".
arraytools.cpp isn't used and was origionally planned to be holding excess functions.  The makefile doesn't use it.

It was designed primarily to be fed a file from the command line.
IE: dict < testfile.txt.
It can be run through the user manually typing in things to the console as well.
In either case a word longer than whatever the max word size was set to at compile time (default 20) is treated as an escape command.


By default it pre populates the list with the ten most commonly used words.
This behaviour can be changed by changing PRELOADLIBRARY to false prior to compiling.

as it sees any non alpha character as equivelent to a space contractions will end up counted as two words:
IE: "they're" will be seen as "they" and "re".

it doesn't care about capitalization as all characters are converted to lowercase.

It will accept words up to whatever the constant int of WordSize is set to (default 20)
It treats a word longer than WordSize as an escape command.
WordSize is also used for formating it's output when it prints the word count.

It will accept up to whatever the constant int LibrarySize is set to (default 40000).
If the library somehow goes above this amount the program will stop parsing new words and print out the library as it stands at that moment.

