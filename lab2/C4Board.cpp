#include <iostream>
#include <string>
#include "C4Col.h"
#include "C4Board.h"
using namespace std;

ostream &operator<<(ostream &output, C4Board &board){
	for(int i = board.board[0].getMaxDiscs() - 1; i >= 0; i--){ //loops through entire board
		for(int j = 0; j < board.numCols; j++){
			output << "|" << board.board[j].getDisc(i);
		}
		output << endl; //next line
	}
	output << " 1 2 3 4 5 6 7 " << endl; //column numbers
	return(output);  //enables cascading of the "<<" operator by returning the output stream given to the friend function of type ostream
}

C4Board::C4Board(){ //constructor
	numCols = 7;	
}

void C4Board::play(){
	int play = 1; //for while loop
	int turn = 1;
	while(play){
		int choice;
		cout << *this << endl;
		if(turn % 2){ //if "turn" is odd, it is player 1's turn
			cout << "Player 1 please enter a column choice: ";
		} else {
			cout << "Player 2 please enter a column choice: ";
		}
		cin >> choice;
		if(choice == -1){ //exit loop if choice is -1
			break;
		}
		choice--; //columns range from 0 to 6 
		
		if(board[choice].isFull() || choice > 6){ //if the column of choice is full, the player must pick another
			continue;
		}
		if(turn % 2){
			board[choice]+='X'; //Player 1 is X
		} else {
			board[choice]+='O'; //Player 2 is O
		}
		turn++; //change turn
	}	
}

void C4Board::win(){
	int i; //for iteration
	for(i = 0;i < 5;i++){
		if(board[i].getDisc(i) == 'X'){
		}
	}
}
