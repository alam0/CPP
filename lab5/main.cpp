//main.cpp
//simple driver that reads in provided Sudoku or Wordoku

#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//Wordoku instance
	Puzzle<char> word(9, "worduku.txt");
	cout << "Worduku!" << endl;
	word.printBoard();
	
	//Sudoku Instance and Gameplay
	Puzzle<int> a(9, "test.txt");
	cout << "Sudoku!" << endl;
	a.playsudoku();
	
	//Puzzle<int> finishup(9, "almostfullboard.txt"); a board with one empty spot, enter 7 in row 8, column 8 to finish up
	//finishup.playsudoku();
	return(0);
}
