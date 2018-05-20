//BankAccount.h Base Class Definition	
//Author: Aron Lam
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class BankAccount {
	
	public:
		//Constructor
		BankAccount(string = "empty", string = "empty", string = "empty");
		
		virtual void print(); //virtual so that derived classes may have their own void print(); functions
		
		//Accessor Functions
		string getName(); 
		string getDate();
		string getType();

	private: //so inherited classes may access them directly
		//3 Data Members
		string Name;
		string Date;
		string Type;
		
};
#endif
