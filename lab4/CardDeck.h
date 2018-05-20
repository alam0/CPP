//CardDeck.h
//Author: Aron Lam

#ifndef CARDDECK_h
#define CARDDECK_h

#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <iterator>
using namespace std;


class CardDeck {
	friend ostream &operator<<(ostream &, CardDeck &);
	public:
	//Constructor
	CardDeck(int = 52); //52 as fall-back value
	
	//Member Functions
	int getSize(); //returns size of current deck using size() member function of deque
	
	//Utility Function
	void shuffle(); //shuffles elements of deck
	int inOrder(); //returns 1 if elements of deck are in order, 0 otherwise
	
	void printReverse(); //displays cards in deque in reverse order
	//deque<int> getdata();
	
	int monkeySort(); //shuffles cards and checks if they are in order
	int Deal();
	void BlackJack();
	int Win();
	void checkForWin();
	int hitDealer();
	void initialDeal();
	void printHands();
	void showWins();
	
	
	private:
	int n; //num of cards
	deque<int> data;
	int dealer; //amount dealer has 
	int player; //amount player has
	int playerwins; //amount of player wins
	int dealerwins; //amount of dealer wins
	int hitplayer;
	int play;


};


#endif
