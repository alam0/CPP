#ifndef C4Col_H
#define C4Col_H
#include <iostream>
#include <string>

using namespace std;

class C4Col{
	public:
		C4Col();
		int isFull(); //determines if column is full
		char getDisc(int); //returns the requested element of the private character array
		int getMaxDiscs(); //returns maximum number of discs (i.e. number of rows)
		void addDisc(char); // adds the character representing a disc to the next open slot in the Disc array (i.e., Discs[numDiscs++] = newDisc)
		C4Col operator+=(char); //doesnt need &operator because just passing a variable value can be done by reference
	private:
		int numDiscs;
		int maxDiscs;
		char Discs[6]; //number of rows
};

#endif
