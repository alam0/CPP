//CreditCardComp.h Class Definition
//Author: Aron Lam

#ifndef CREDITCARDCOMP_H
#define CREDITCARDCOMP_H

#include <iostream>
#include <math.h>
#include <string>
#include "BankAcctComp.h"
using namespace std;

class CreditCardComp { //CreditCard inherits from BankAccount

	public:
		CreditCardComp(); //Constructor
		void print(); //to print details of a card
		
	private:
		string CardNumber; 
		bool TrackingChip; //has tracking chip?
		BankAcctComp card; //create instance of BankAcctComp 
		
};
#endif
