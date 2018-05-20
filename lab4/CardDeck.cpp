//CardDeck.cpp
//Author: Aron Lam

#include "CardDeck.h"
#include <math.h>
#include <iostream>
#include <string>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>
using namespace std;

//display contents of card array with for loop
/*ostream &operator<<(ostream &output, CardDeck &card){ //overloading operator << so that it displays elements of card array separated by ', '
	for(int i = 1; i < card.getSize(); i++){
		output << card.data[i];
		if(i < card.getSize() - 1){
			output << ", ";
		}
	}
	output << endl;
	return(output);//enables cascading of the "<<" operator by returning the output stream given to the friend function of type ostream
}*/


//display contents of deque using copy and an ostream_iterator
ostream &operator<<(ostream &output, CardDeck &card){ //overloading operator << so that it displays elements of card array separated by ', '
	ostream_iterator<int> out(output, ", ");
	copy (card.data.begin(), card.data.end(), out);
	output << endl;
	return(output);
}

//display deque elements using a forward iterator, ++i used to avoid a temp variable
/*ostream &operator<<(ostream &output, CardDeck &card){ //overloading operator << so that it displays elements of card array separated by ', '
	deque<int>::const_iterator i;
	for(i = card.data.begin(); i != card.data.end(); ++i){
		output << *i;
		if(i < card.data.end() - 1){
			output  << ", ";
		}
	}
	output << endl;
	return(output);
} 
*/


//Non-default Constructor
CardDeck::CardDeck(int numCards){
	n = numCards;
	for(int i = 0; i < n; i++){ //places the integers from 0 to n-1 into the deque
		data.push_back(i); //add to back of vector
	}
	playerwins = 0;
	dealerwins = 0;
}

//returns size of current deck using size() member function of deque
int CardDeck::getSize(){
	int s;
	s = data.size();
	return(s);
}

//Shuffle Card Deck
void CardDeck::shuffle(){
	
	random_shuffle(data.begin(), data.end() );
	
}

//returns 1 if deque is in order from lowest to highest, returns 0 otherwise
int CardDeck::inOrder(){
	for(int i = 0; i < data.size() - 1; i++){
		if(data[i] > data[i+1]){
			return(0);
		}
	} 
	return(1);
}

//Display card array in reverse order

void CardDeck::printReverse(){
	deque<int>::const_reverse_iterator r;
	deque<int>::const_reverse_iterator end = data.rend();
	for(r = data.rbegin(); r!= end; ++r){
		cout << *r;
		if(r < end - 1){
			cout << ", ";
		}
	}	
	cout << endl;
} 

//Monkey Sort
int CardDeck::monkeySort(){
	shuffle(); //mess up card order
	int scrambled = 1; //for while loop
	int shufflecount = 0; 
	
	while(scrambled){ //while scrambled, keep shuffling until inOrder
		if(inOrder()){ 
		scrambled = 0;
		}
		shuffle();
		shufflecount++;
	}
	return(shufflecount);
} 



//BLACKJACK
//Deal pops off a card from the deck and adds it to player/dealer amount
int CardDeck::Deal(){
	//if number of cards is < 16, push in 52 more cards
	if(n <= 15){
		for(int i = 0; i < 52; i++){
			data.push_back(i); 
		}
		n = 52;
	}
	shuffle();
	int top = data.back() + 2; //0 becomes 2, there is no 1 since Ace is always 11. 
	if(top==12 || top==13 ||top==14){ //Face cards are 10s
		top = 10;
	}
	data.pop_back();
	n--;
	
	return(top);
}

//Play Function for BlackJack
void CardDeck::BlackJack(){
	shuffle();
	//Change 0 - 51 into 0 - 12
	for(int i = 0; i < 52; i++){
		data[i] = (data[i] + 1) % 13;
	}
	
	initialDeal();
	
	//Gameplay
	play = 1;
	while(play){
		checkForWin();
		
		//playerchoice
		cout << "Player: Hit(1) or Stand(0)?" << endl;
		cin >> hitplayer;
		if(hitplayer){
			player += Deal(); 
		}
		checkForWin();
		
		if(hitDealer()){
			dealer += Deal();
		}
		printHands();
		checkForWin();
		
		//if both stand, check for winner
		
	}
}

//Checks for Winner
int CardDeck::Win(){
	
	if(player == 21 || dealer > 21){
		printHands();
		cout << "player wins" << endl;
		playerwins++;
		return(1);
	}
	if(dealer == 21 || player > 21){
		printHands();
		cout << "player loses" << endl;
		dealerwins++;
		return(1);
	}
	if(dealer > 16 && hitplayer == 0){
		if(player > dealer){
			cout << "player wins" << endl;
			playerwins++;
			return(1);
		} else if(player < dealer){
			cout << "dealer wins" << endl;
			dealerwins++;
			return(1);
		} else {
			cout << "Hands Equal" << endl;
			if(hitplayer== 0)
				return(1);
		}
	}
	
	return(0);	
}
void CardDeck::checkForWin(){
	if(Win()){
		int playagain;
		showWins();
		cout << "Do you want to play again? Yes(1) or No(0)"<< endl;
		cin >> playagain;
		if(playagain){
			initialDeal();
		} else {
			play = 0;
		}
	}

}

//Dealer stands if value is greater than 16
int CardDeck::hitDealer(){
	if(dealer >= 17){
		return(0);
	}
	return(1);
}
//Deal player 2 cards, and dealer 1 cards
void CardDeck::initialDeal(){ 
	player = 0;
	dealer = 0;
	player += Deal();
	dealer += Deal();
	printHands();
	player += Deal();
	checkForWin();
	printHands();
}
//Shows Current Hands of Player and Dealer
void CardDeck::printHands(){ 
	cout << endl;
	cout << "Current Hands: " << endl;
	cout << "Player: " << player << endl;
	cout << "Dealer: " << dealer << endl;
	cout << "Cards Left: " << n << endl;
}

//Show Amount of Wins for Player and Dealer
void CardDeck:: showWins(){
	cout << "Player wins: " << playerwins << endl;
	cout << "Dealer wins: " << dealerwins << endl;
	 
}
