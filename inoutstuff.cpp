/*
Student ID: 4903077
Name: Matthew McAlpine
CS2010 Fall 2014
Lab Assignment 4
* 
* Figured there were some things that annoyed me about how cout works.
* Thought I'd start writing a set of functions arround that.
 */
#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;

void pl(){
	//got sick of typing cout << '\n' a bunch.  made a function that does just that.
	cout << '\n';
	return;
}

void outspam(char tobespammed, int howmuchspam){
	//accepts a char and int, sents the char to cout as many times as indicated by the int.
	int count = 0;
	
	while(count < howmuchspam){
		cout << tobespammed;
		count++;
	}
	
	return;
	
}
