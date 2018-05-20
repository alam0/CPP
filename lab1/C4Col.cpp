#include <iostream>
#include <string>
#include "C4Col.h"

using namespace std;


C4Col::C4Col(){
	numDiscs = 0;
	maxDiscs = 6; //number of rows
	int i;
	for(i = 0;i < maxDiscs; i++){ 
		Discs[i] = ' ';
	};
}

int C4Col::isFull(){ //determines if column is full
	int Full;
	if(numDiscs == maxDiscs){
		Full = 1;
	} else if(numDiscs < maxDiscs){
		Full = 0;
	}
	return Full;
}

char C4Col::getDisc(int i){  //returns the requested element of the private character array
	return Discs[i];
}

int C4Col::getMaxDiscs(){ //returns maximum number of discs (i.e. number of rows)
	return maxDiscs;
}
	
void C4Col::addDisc(char c){ // adds the character representing a disc to the next open slot in the Disc array (i.e., Discs[numDiscs++] = newDisc)
	char newDisc = c;
	Discs[numDiscs] = newDisc;
	numDiscs++;
}
