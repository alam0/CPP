#ifndef C4Board_H
#define C4Board_H
#include "C4Col.h"

class C4Board{

	public:
	
		C4Board();
		~C4Board();
		void display(); //display the current board insimple text
		void play(); // allows two players to play a game
		
	private:
	
		int numCols;
		C4Col *board;
		void win();
		
};

#endif
