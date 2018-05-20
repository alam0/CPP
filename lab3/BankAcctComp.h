//BankAcctComp.h Base Class Definition	
//Author: Aron Lam
#ifndef BANKACCTCOMP_H
#define BANKACCTCOMP_H

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class BankAcctComp{
	
	public:
		//Constructor
		BankAcctComp(string = "empty", string = "empty", string = "empty");
		
		void print(); //virtual so that derived classes may have their own void print(); functions
		
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
