//Puzzle.h 
//Templated Class for Sudoku/Wordoku
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
	    Puzzle(int = 9, string filename = "test.txt");
	
	    void printBoard(); //display 2D board
	    int checkEntryValidity(int entry, int rowNum, int colNum);
	    void addEntry(int entry, int rowNum, int colNum);
	    int isBoardFull(); //checks if sudoku board is full
	    void playsudoku(); //main gameplay function
	
	private:
		int size; //size of board (9) in this case so rows and cols go (0-8)
		vector<vector <T> > board; //2D vector called board
	
}; //end class Puzzle


//Constructor
template <typename T>
Puzzle<T>::Puzzle(int boardSize, string filename){
	size = boardSize; //establish private variable size
	
	//create a board of 0's
	vector<T> tmp; //1D vector to be filled with 0's
	for(int k = 0;k < size; k++){
		tmp.push_back(0);
	} 
	//fill 2D vector board with 1D vector of 0's 
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

//Check validity of an entry, ensures correct entries all the way to end of game
template <typename T>
int Puzzle<T>::checkEntryValidity(int entry, int rowNum, int colNum){
	//check if entry is in desinated row and column
	for(int i = 0;i < size;i++){
			if(entry == board[i][colNum] || entry == board[rowNum][i]){
				cout << "Entry already present in row/column" << endl;
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
				cout << "Entry already present in minigrid" << endl;
				return 0;
			}
		}
	}
	
}
//Add entry into designated spot on board
template <typename T>
void Puzzle<T>::addEntry(int entry, int rowNum, int colNum){
	board[rowNum][colNum] = entry;
}

//Checks if 2D sudoku board is full
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
void Puzzle<T>::playsudoku(){ //called in main and interacts with user
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
			break;
		}
	}
}
#endif 
