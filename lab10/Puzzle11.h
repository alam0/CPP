//Puzzle10.h for Lab10
//Templated Class for Sudoku/Wordoku
//Including Sudoku Solver Portion
#ifndef PUZZLE10_H
#define PUZZLE10_H

#include <vector>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
using namespace std;

//Puzzle class definition
template <typename T>

class Puzzle {
	public:
		Puzzle(int = 9, string filename = "test.txt"); //default constructor
		//~Puzzle(); //deconstructor
	
		void printBoard(); //display sudoku
		auto checkEntryValidity(int entry, int rowNum, int colNum);
		void addEntry(int entry, int rowNum, int colNum);
		void updateSolutions(); //update 3D vector of possible solutions
		void singlePossibility(); //fills in board if there is only a single possibility for a square
		auto isBoardFull(); //checks if sudoku board is full
		void sudokuSolver();
	
	private:
		int size; //size of board (9) in this case so rows and cols go (0-8)
		vector<vector <T > > board; //2D vector called board
		vector<vector<set <T > > > solutions;//2D vector of sets: possible solutions
}; //end class Puzzle


//Constructor
template <typename T>
Puzzle<T>::Puzzle(int boardSize, string filename){
	size = boardSize; //establish private variable size
	
	//Fill 2D board with 0's
	vector<T> tmp;
	for(auto k = 0;k < size; k++){
		tmp.push_back(0);
	}
	for(auto l = 0;l < size; l++){
		board.push_back(tmp);
	}
	
	//reading txt file into data stream and >> temp, and finally board
	ifstream data (filename.c_str());
	T temp;
	for(auto i = 0;i < size;i++){
		for(auto j = 0;j < size;j++){
			data >> temp;
			board[i][j] = temp;
		}	
	}
	
	//Initialize 2D vector of sets of auto
	for(auto j = 0;j < size; j++){
		solutions.push_back(vector<set<T > > (9));
	}
	
}

//Print out sudoku board
template <typename T>
void Puzzle<T>::printBoard(){
	cout << "Column"; //Nicer Formatting: show Column Numbers
	for(auto h = 0;h < size;h++){
		cout << "|" << h; //Column Dividers
	}
	cout << endl << "Row 0. "; //print out first row, (This is only for Nicer Formatting)
	for(auto l = 0; l < size; l++){
		cout << board[0][l] << " ";
	} 
	cout << endl; 
	for(auto i = 1;i < size;i++){ //print out rest of the rows
	cout << "____" << i << ". "; //show row #'s
		for(auto j = 0; j < size; j++){
			cout << board[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}


//Check validity of an entry, ensures correct entries all the way to end of game
template <typename T>
auto Puzzle<T>::checkEntryValidity(auto entry, auto rowNum, auto colNum){

	//check if entry is in desinated row and column
	for(auto i = 0;i < size;i++){
			if(entry == board[i][colNum] || entry == board[rowNum][i]){
				//cout << "Entry already present in row/column" << endl;
				return 0;
			}
	}
	//check if entry is in designated minigrid
	int gridSize = 3, gridRow, gridCol, gridTotal;
	//grab top left corner of minigrid that [rowNum][colNum] is in through integer division
	gridRow = rowNum/gridSize;
	gridRow *= gridSize;
	gridCol = colNum/gridSize;
	gridCol *= gridSize;
	//check through from top left corner of minigrid
	for(auto a = gridRow; a < gridRow + 3; a++){
		for(auto b = gridCol; b < gridCol + 3; b++){
			if(entry == board[a][b]){
				//cout << "Entry already present in minigrid" << endl;
				return 0;
			}
		}
	}
	return 1;
}

//Add entry into designated spot on board
template <typename T>
void Puzzle<T>::addEntry(auto entry, auto rowNum, auto colNum){
	board[rowNum][colNum] = entry;
}

//Updates Solutions
template <typename T>
void Puzzle<T>::updateSolutions(){
	for(auto row = 0;row < 9;row++){
		for(auto col = 0;col < 9;col++){
			if(board[row][col] == 0){ //for 0 spots
				for(auto value = 1;value < size + 1;value++){
					if(checkEntryValidity(value, row, col)) //if valid, insert to set
						solutions[row][col].insert(value);
					else if(solutions[row][col].find(value) != solutions[row][col].end())
						solutions[row][col].erase(value);
				}
			}
		}
	}
}

//Single Possibility
template <typename T>
void Puzzle <T>::singlePossibility(){
	for(auto row = 0;row < 9;row++){
		for(auto col = 0;col < 9;col++){
			if(board[row][col] == 0 ){ //check only squares of value 0
				if(solutions[row][col].size() == 1){
					auto solution = *solutions[row][col].begin();
					board[row][col] = solution;
					for(auto i = 0; i < size; i++){
							if(solutions[row][i].find(solution) != solutions[row][i].end())
								solutions[row][i].erase(solution);
							if(solutions[i][col].find(solution) != solutions[i][col].end())
								solutions[i][col].erase(solution);
					}
				}	
			}
		}
	}
}

//Checks if sudoku board is full
template <typename T>
auto Puzzle<T>::isBoardFull(){
	for(auto i = 0;i < size;i++){
		for(auto j = 0;j < size;j++){
			if(board[i][j] == 0) //if a spot on the board is = to 0, board is not full, return 0
				return 0;
		}
	}
	return 1; //if no 0's return 1
}


//3D function
template <typename T>
void Puzzle<T>::sudokuSolver(){
	auto unsolved = 1;
	while(unsolved){
		updateSolutions();
		singlePossibility();
		updateSolutions();	
		//printBoard();
		if(isBoardFull()){
			cout << "Game Over! You Win!" << endl;
			unsolved = 0;
			printBoard();
		}
		
	}
}

#endif 
