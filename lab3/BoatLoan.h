//BoatLoan.h Class Definition
//Author: Aron Lam

#ifndef BOATLOAN_H
#define BOATLOAN_H

#include <iostream>
#include <math.h>
#include <string>
#include "BankAccount.h"
using namespace std;

class BoatLoan : public BankAccount { //BoatLoan inherits from BankAccount

	public:
		BoatLoan(string = "empty", string = "empty", string = "empty"); //constructor
		void print(); //to print details of a boatloan
		
	private:
		string maxLootStorage;
		string numberofMonths;
};

#endif
