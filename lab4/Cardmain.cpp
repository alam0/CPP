//Cardmain.cpp
//simple driver function 

#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "CardDeck.h"
using namespace std;

int main(){ //user may choose to do 
	int mainchoice;
	cout << "MonkeySort(0) or BlackJack(1) ? " << endl;
	cin >> mainchoice;
	if(mainchoice){ //if user chooses blackjack
		srand(time(0));
		CardDeck Black;
		Black.BlackJack();
	} else { //values are different with more than one event of MonkeySort. When there is only one instance of monkeySort with 9 cards, the result is 342,189. 
		//Sort 7 Cards 3 times
		cout << "Sort 7 Cards 3 times: " << endl;
		CardDeck MS71(7); 
		cout << MS71.monkeySort() << endl;
	
		CardDeck MS72(7);
		cout << MS72.monkeySort() << endl;
	
		CardDeck MS73(7);
		cout << MS73.monkeySort() << endl;
	
		//Sort 8 Cards 3 times
		cout << "Sort 8 Cards 3 times: " << endl;
		CardDeck MS81(8);
		cout << MS81.monkeySort() << endl;
	
		CardDeck MS82(8);
		cout << MS82.monkeySort() << endl;
		
		CardDeck MS83(8);
		cout << MS83.monkeySort() << endl;
		
		//Sort 9 Cards 3 times
		cout << "Sort 9 Cards 3 times: " << endl;
		CardDeck MS91(9);
		cout << MS91.monkeySort() << endl;
		
		CardDeck MS92(9);
		cout << MS92.monkeySort() << endl;
		
		CardDeck MS93(9);
		cout << MS93.monkeySort() << endl;
	}
	
	return(0);
}
