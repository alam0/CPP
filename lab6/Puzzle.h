//Puzzle.h for Lab6
//Templated Class for Sudoku/Wordoku
//Including Sudoku Solver Portion
#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

//Puzzle class definition
template <typename T>

class Puzzle {

	public:
	Puzzle(int = 9, string filename = "test.txt"); //default constructor
	//~Puzzle(); //deconstructor
	
	void printBoard(); //display sudoku
	void print3Dboard(); //display 3D board of solutions
	int checkEntryValidity(int entry, int rowNum, int colNum);
	void addEntry(int entry, int rowNum, int colNum);
	void updateSolutions(); //update 3D vector of possible solutions
	void singlePossibility(); //fills in board if there is only a single possibility for a square
	void singletonRow();
	void singletonCol();
	void singletonGrid();
	int isBoardFull(); //checks if sudoku board is full
	void playSudoku(); //main gameplay function
	void sudokuSolver();
	
	private:
		int size; //size of board (9) in this case so rows and cols go (0-8)
		vector<vector <T> > board; //2D vector called board
		vector<vector<vector <T> > > solutions;//3D vector of possible solutions
		
	
}; //end class Puzzle


//Constructor
template <typename T>
Puzzle<T>::Puzzle(int boardSize, string filename){
	size = boardSize; //establish private variable size
	
	//Fill 2D board with 0's
	vector<T> tmp;
	for(int k = 0;k < size; k++){
		tmp.push_back(0);
	}
	for(int l = 0;l < size; l++){
		board.push_back(tmp);
	}
	
	//reading txt file into data stream and >> temp, and finally board
	ifstream data (filename.c_str());
	T temp;
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
			data >> temp;
			board[i][j] = temp;
		}	
	}
	
	//Fill 3D vector(solutions) with 0's
	vector <T> tmp1; //1D vector to be filled with 0's
	vector<vector <T> > tmp2; //2D vector to be filled with 1D vectors of 0's
	for(int a = 0;a < size;a++){
		tmp1.push_back(0);
	}
	for(int b = 0;b < size;b++){
		tmp2.push_back(tmp1);
	}
	//fill 3D vector with 2D vectors of 0's
	for(int c = 0;c < size;c++){
		solutions.push_back(tmp2);
	}	
}

//Print out sudoku board
template <typename T>
void Puzzle<T>::printBoard(){
	cout << "Column"; //Nicer Formatting: show Column Numbers
	for(int h = 0;h < size;h++){
		cout << "|" << h; //Column Dividers
	}
	cout << endl << "Row 0. "; //print out first row, (This is only for Nicer Formatting)
	for(int l = 0; l < size; l++){
		cout << board[0][l] << " ";
	} 
	cout << endl; 
	for(int i = 1;i < size;i++){ //print out rest of the rows
	cout << "____" << i << ". "; //show row #'s
		for(int j = 0; j < size; j++){
			cout << board[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}

//Print 3D board of solutions
template <typename T>
void Puzzle<T>::print3Dboard(){
	for(int row = 0;row < size;row++){
		for(int col = 0;col < size;col++){
			cout << "Row: " << row << "Col:"<< col << endl;
			for(int value = 0; value < size;value++){
				cout << solutions[row][col][value];
			}
			cout << endl;
		}
	}
}

//Check validity of an entry, ensures correct entries all the way to end of game
template <typename T>
int Puzzle<T>::checkEntryValidity(int entry, int rowNum, int colNum){

	//check if entry is in desinated row and column
	for(int i = 0;i < size;i++){
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
	for(int a = gridRow; a < gridRow + 3; a++){
		for(int b = gridCol; b < gridCol + 3; b++){
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
void Puzzle<T>::addEntry(int entry, int rowNum, int colNum){
	board[rowNum][colNum] = entry;
}

//Updates Solutions of each spot on board in 3D vector called solutions
template <typename T>
void Puzzle<T>::updateSolutions(){
	for(int row = 0;row < size;row++){
		for(int col = 0;col < size;col++){
			if(board[row][col] == 0){
				for(int value = 1;value < size + 1;value++){
					if(checkEntryValidity(value, row, col)) //if valid, update respective slot in 3D vector to 1
						solutions[row][col][value-1] = 1;
					else 
						solutions[row][col][value-1] = 0;
				}
			}
		}
	}
}

//Single Possibility
template <typename T>
void Puzzle <T>::singlePossibility(){
	int sum;
	for(int row = 0;row < size;row++){
		for(int col = 0;col < size;col++){
			if(board[row][col] == 0){ //check only squares of value 0
				sum = 0;
				for(int value = 0;value < size;value++) //sum up possibilities, if total is 1, the box's solution is found
					sum += solutions[row][col][value];
				if(sum == 1){ //if total is one, find the value that allowed, and fill respective square in sudoku board
					for(int i = 0;i < size;i++)
						if(solutions[row][col][i] == 1){
							solutions[row][col][i] = 0;
							addEntry(i+1, row, col);
						}
				}
			}
		}
	}
}


template <typename T>
void Puzzle<T>::singletonRow(){
	int timesValidRow;
	for(int row = 0;row < size;row++){
		for(int number = 1; number < size+1; number++){
			timesValidRow = 0; //reset for every number (1-9)
			for(int col = 0; col < size; col++){
				if(board[row][col] == 0)
					timesValidRow += checkEntryValidity(number, row, col);
			}		
			if(timesValidRow == 1){ //if number is only valid one time
				for(int i = 0;i < size; i++)
					if(checkEntryValidity(number, row, i)){
						addEntry(number, row, i);
					}
				
			}
		}
	}
}

template <typename T>
void Puzzle<T>::singletonCol(){
	int timesValidCol;
	for(int col = 0; col < size; col++){
		for(int number = 1; number < size+1; number++){
			timesValidCol = 0; //reset for every number (1-9)
			for(int row = 0; row < size; row++)
				if(board[row][col] == 0)
					timesValidCol += solutions[row][col][number];
			//if number is only valid once... singleton
			if(timesValidCol == 1){
				for(int i = 0;i < size; i++){
					if(checkEntryValidity(number,i, col){
						//update solution array
						addEntry(number, i, col); //add into the valid spot
					}
				}
			}
		}
	}
}

template <typename T>
void Puzzle<T>::singletonGrid(){
	int timesValidGrid, gridSize = 3, gridRow, gridCol;
	for(int row = 0; row < size; row++){
		for(int col = 0; col < size; col++){
			//grab top left corner of minigrid that [rowNum][colNum] is in through integer division
			gridRow = row/gridSize;
			gridRow *= gridSize;
			gridCol = col/gridSize;
			gridCol *= gridSize;
			//check all numbers 1-9
			for(int number = 1; number < size+1; number++){
				for(int a = gridRow; a < gridRow + 3; a++){
					for(int b = gridCol; b < gridCol + 3; b++){ //sum up validity
						timesValidGrid += checkEntryValidity(number, a, b);	
					}
				}
				//if the number is only valid once in the grid..
				if(timesValidGrid == 1){
					for(int c = gridRow; c < gridRow + 3; c++){
						for(int d = gridCol; d < gridCol + 3; d++){
							if(checkEntryValidity(number, c, d)){
								addEntry(number, c, d); //add it into the valid spot
							}
						}
					}	
				}
			}		
		}
	}
}

//Checks if sudoku board is full
template <typename T>
int Puzzle<T>::isBoardFull(){
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
		if(board[i][j] == 0) //if a spot on the board is = to 0, board is not full, return 0
			return 0;
		}
	}
	return 1; //if no 0's return 1!
}

//main gameplay driving function
template <typename T>
void Puzzle<T>::playSudoku(){ //called in main and interacts with user
	int play = 1, entry, rowNum, colNum; //necessary variables for user interaction and board entry
	while(play){
		printBoard();
		//get user inputs
		cout << "Please enter a your entry (1-9): " << endl;
		cin >> entry; 
		cout << "Please enter a row number(0-8): " << endl;
		cin >> rowNum;
		cout << "Please enter a column number(0-8): " << endl;
		cin >> colNum;
		//check entry validity
		if(checkEntryValidity(entry, rowNum, colNum)){
			addEntry(entry, rowNum, colNum);
		}
		//the final valid entry will fill the board with correct entries, resulting in game over
		if(isBoardFull()){
			cout << "Game Over! You Win!" << endl;
			printBoard();
			play = 0;
		}
	}
}

//3D function
template <typename T>
void Puzzle<T>::sudokuSolver(){
	int unsolved = 1;
	while(unsolved){
		updateSolutions();
		//print3Dboard();
		//singlePossibility();
		//updateSolutions();
		singletonRow();
		updateSolutions();
		singletonCol();
		updateSolutions();
		singletonGrid();
		//printBoard();
		if(isBoardFull()){
			printBoard();
			cout << "Game Over! You Win!" << endl;
			unsolved = 0;
		}
	}
}

#endif 
