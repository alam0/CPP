//main.cpp for lab10
//simple driver that reads in provided Sudoku

#include "Puzzle10.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//Wordoku instance
	Puzzle<int> sudoku(9, "easyPuzzle.txt");
	cout << "Sudoku Solver!" << endl;
	sudoku.sudokuSolver();
	
	return(0);
}
