/*
Student ID: 4903077
Name: Matthew McAlpine
CS2010 Fall 2014
Lab Assignment 4
* This project reads from the cin and counts how many times a word appears.
* Any non alpha character is both ignored and treated as a new word.
* 
* By default it pre populates the list with the ten most commonly used words.
* This behaviour can be changed by changing PRELOADLIBRARY to false prior to compiling.
* 
* as it sees any non alpha character as equivelent to a space contractions will end up counted as two words:
* IE: "they're" will be seen as "they" and "re".
* 
* it doesn't care about capitalization as all characters are converted to lowercase.
* 
* It will accept words up to whatever the constant int of WordSize is set to (default 20)
* It treats a word longer than WordSize as an escape command.
* WordSize is also used for formating it's output when it prints the word count.
* 
* It will accept up to whatever the constant int LibrarySize is set to (default 40000).
* If the library somehow goes above this amount the program will stop parsing new words and print out the library as it stands at that moment.
* 
* 
 */
#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

const bool OUTPUTLIST = false; //if true, will out put the library at various stages for debug purposes.
const bool PRELOADLIBRARY = true; //if true program will preload dictonary with the 10 most common words.
const bool OUTLISTAFTERPASS = false; //if the program should dump the library after every word.
const bool OUTVARAFTERPASS = false; //if the program should dump iterators after pass.


//const bool PRINTWHOLELIBRARY = true;  //No longer used.  If the library print function will print the whole thing, even empty cells.

const int WordSize = 20; //Maximum size of a given word.
const int LibrarySize = 40000; //maximum library size.


/*Didn't work.
//This section is commented out because stuff didn't work.
//void fillarraypart(int[] *a, int b, int c, int d);
//void printLibrary(char toPrint[LibrarySize][WordSize], int wordCount[LibarySize], int letterCount[LibrarySize], int finalLoc);
//int arrayFill(int *toBeFilled, int toFillWith, int startIndex, int endIndex); //storred in arraytools.c
*/

int main() {
	
	char testWord[WordSize];  //Stores the word that'll be tested against the library.
	int testWordSize = 0;//Stores the size of the word to be tested.
	char library[LibrarySize][WordSize];//The actual library.
	int letterCount[LibrarySize] = {};//Stores the size of each word in the library.
	int wordCount[LibrarySize] = {}; //Counts occurence of each word.
	int libraryNewLocation = 0; //points to the next slot for a new word.
	
	
	int count = 0; //used for various loops.  Probably should have not given it such a wide scope in hindsight.
	
	
	void printLibrary(char library[LibrarySize][WordSize], int letterCount[LibrarySize], int wordCount[LibrarySize]);
	void pl();
	
	
	/*More that didn't work.
	//char *(libraryPointer[LibrarySize][WordSize]);
	//libraryPointer = &(library);
	//int *wordCountPointer;
	//wordCountPointer = &wordCount[0];
	*/
	
	
	if(PRELOADLIBRARY == true){
		//Looked up the 10 most common words.  I figure this'll slightly improve search efficency.
		//Word: the
		library[0][0] = 't';
		library[0][1] = 'h';
		library[0][2] = 'e';
		letterCount[0] = 3;
		
		//Word: be
		library[1][0] = 'b';
		library[1][1] = 'e';
		letterCount[1] = 2;
		
		//word: to
		library[2][0] = 't';
		library[2][1] = 'o';
		letterCount[2] = 2;
		
		//word: of
		library[3][0] = 'o';
		library[3][1] = 'f';
		letterCount[3] = 2;
		
		//word: and
		library[4][0] = 'a';
		library[4][1] = 'n';
		library[4][2] = 'd';
		letterCount[4] = 3;
		
		//word: a
		library[5][0] = 'a';
		letterCount[5] = 1;
		
		//word: in
		library[6][0] = 'i';
		library[6][1] = 'n';
		letterCount[6] = 2;
		
		//word: that
		library[7][0] = 't';
		library[7][1] = 'h';
		library[7][2] = 'a';
		library[7][3] = 't';
		letterCount[7] = 4;
		
		//word: have
		library[8][0] = 'h';
		library[8][1] = 'a';
		library[8][2] = 'v';
		library[8][3] = 'e';
		letterCount[8] = 4;
		
		//word: i
		library[9][0] = 'i';
		letterCount[9] = 1;			
		
		libraryNewLocation = 10;
		//arrayFill(wordCountPointer,0,0,9);  //didn't work.
		
		//TODO: moveinto own function?
		//This next bit is for loading a subsection of an array with 0.
		//Should probably make that it's own generic function if time permits.
		count = 0;
		while (count < 10){
			wordCount[count] = 0;
			count++;
			
		}
		
		
		
	}
	
	if(OUTPUTLIST == true){
		cout << "--Library as of preload: --";
		cout << '\n';
		printLibrary(library, letterCount, wordCount);
		cout << "-----";
		cout << '\n';
	}
	
	//TODO:  Fold into own functions?
	
	
	int countTest = 0;//Stores possition in searching library.
	int countTest2 = 0;//Stores position in comparing word.
	int countTest3 = 0;//Stores position in loading new word into library.
	bool notFound = true;
	bool wrong = false;
	bool abortLoop = false;
	char ch;  //stores tested character.
	testWordSize = 0;
	while((cin.good()) && (libraryNewLocation < LibrarySize) && (!abortLoop)){
		
		ch = cin.get();
		/*
		if (ch == '^'){
			abortLoop = true;
		}
		*/
		if (isalpha(ch)){
			ch = tolower(ch);
			testWord[testWordSize] = ch;
			testWordSize++;
			
		}else{
			if(testWordSize > 0){
				countTest = 0;
				notFound = true;
				wrong = false;
				while((notFound) && (countTest < libraryNewLocation)){
					if(letterCount[countTest] == testWordSize){
					//if(true){
						
						
						
						countTest2 = 0;
						wrong = false;
						while((countTest2 < testWordSize) && (!wrong)){
							if(library[countTest][countTest2] != testWord[countTest2]){
								wrong = true;
								
							}
							countTest2++;
						}
						if(!wrong){
							wordCount[countTest]++;
							notFound = false;
						}
						
						
					}
					countTest++;
				}
				if(notFound){
					wordCount[libraryNewLocation] = 1;
					letterCount[libraryNewLocation] = testWordSize;
					countTest3 = 0;
					while(countTest3 < testWordSize){
						library[libraryNewLocation][countTest3] = testWord[countTest3];
						countTest3++;
					}
					libraryNewLocation++;
					
				}	
			}
			testWordSize = 0;
			
			
		}
		
		if(OUTLISTAFTERPASS){
			pl();
			cout << "---Library as of now---";
			pl();
			printLibrary(library, letterCount, wordCount);
			pl();
			cout << "---------";
			pl();
			
		}
		if(OUTVARAFTERPASS){
			//pl();
			cout << "testWordSize: ";
			cout << testWordSize;
			cout << "  libraryNewLocation: ";
			cout << libraryNewLocation;
			pl();
		}
		
		
	}//End of giant while loop for searching library.
	
	
	printLibrary(library, letterCount, wordCount);
	

	
	
	//Just experimenting with cin.getline, should be commented out.
	/*
	char * test = &testWord[0];
	cin.getline(test, 50);
	cout << '\n';
	cout << "---Yet more debug";
	cout << '\n';
	cout << testWord;
	cout << '\n';
	*/ 
	return 0;
}


void printLibrary(char library[LibrarySize][WordSize], int letterCount[LibrarySize], int wordCount[LibrarySize]){
	//This function prints the entire library out.
	//Nolonger prints out empty cells.
	//For simplicity sake the entire arrays are passed rather than pointers.
	
	int countA = 0; //Holds position in library.
	int countB = 0; //Hold position in word.
	void outspam(char tobespammed, int howmuchspam);
	
	while (countA < LibrarySize){
		countB = 0;
		while(countB < letterCount[countA]){
			
			cout << library[countA][countB];
			countB++;
			
		}
		if(letterCount[countA] > 0){
			cout << ": ";
			//cout << '\t';  //Replaced by the outspam function.
			//outspam('\t',2);
			outspam(' ', ((WordSize - letterCount[countA])+2));
			cout << wordCount[countA];
			cout << "\n";	
		}
		countB = 0;	
		countA++;
	}
	cout << "\n";
	return;
}




//Going to comment this section out as I totally forgot where I was going with it.
/*
void printLibrary(char[LibrarySize][WordSize] toPrint, int[LibarySize] wordCount, int[LibrarySize] letterCount, int finalLoc){
	int countA = 0; //Holds word location in library
	int countB = 0; //Holds location in word.
	bool moreStuff = true;
	
	while(countA < finalLoc){


		//Justifys words, slopily.
		//TODO: fold into own small function maybe?
		cout << "   ";
		if (wordCount[countA] < 100){
			cout << " ";
			if (wordCount[countA] < 10){
				cout << " ";
			}
		}
		cout << wordCount[countA];
		countB = 0;
		while(countB < letterCount[countA]){
			
			cout << toPrint[countA][countB];
			countB++;					
			
		}
		cout << '\n';
		countA++;
		
	}
	if(OUTPUTLIST){ //Will only run if OUTPUTLIST function is set.  For debug.
		countA = 0;
		while (countA < LibrarySize){
			cout << toPrint[countA];
			countA++;
			
		}
		
	}
}
*/

