#include <iostream>
#include <string>
#include "C4Col.h"
#include "C4Board.h"
using namespace std;

C4Board::C4Board(){ //constructor
	numCols = 7;	
	board = new C4Col[numCols]; 
}

C4Board::~C4Board(){ //destructor
	delete[] board;
}

void C4Board::display(){ 
	for(int i = board[0].getMaxDiscs() - 1; i >= 0; i--){
		for(int j = 0; j < numCols; j++){
			cout << "|" << board[j].getDisc(i);
		};
		cout << endl;
	};
	cout << " 1 2 3 4 5 6 7 " << endl;
}

void C4Board::play(){
	int play = 1; //for while loop
	int turn = 1;
	while(play){
		int choice;
		display();
		if(turn % 2){ //if "turn" is odd, it is player 1's turn
			cout << "Player 1 please enter a column choice: ";
		} else {
			cout << "Player 2 please enter a column choice: ";
		};
		cin >> choice;
		if(choice == -1){ //exit loop if choice is -1
			break;
		};
		choice--; //columns range from 0 to 6 
		
		if(board[choice].isFull() || choice > 6){ //if the column of choice is full, the player must pick another
			continue;
		};
		if(turn % 2){
			board[choice].addDisc('X'); //Player 1 is X
		} else {
			board[choice].addDisc('O'); //Player 2 is O
		};
		turn++; //change turn
	};	
}

void C4Board::win(){
	int i; //for iteration
	for(i = 0;i < 5;i++){
		if(board[i].getDisc(i) == 'X'){
		};
	};
	
}
