//CreditCard.h Class Definition
//Author: Aron Lam

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <math.h>
#include <string>
#include "BankAccount.h"
using namespace std;

class CreditCard : public BankAccount { //CreditCard inherits from BankAccount

	public:
		CreditCard(string = "empty", string = "empty", string = "empty"); //Constructor
		void print(); //to print details of a card
		
	private:
		string CardNumber;
		bool TrackingChip;
		
};
#endif
