//BankAccount.cpp
//Author: Aron Lam

#include <iostream>
#include <math.h>
#include <string>
#include "BankAccount.h"
using namespace std;

//Base class 
BankAccount::BankAccount(string NameVal, string DateVal, string TypeVal) {
	Name = NameVal;
	Date = DateVal;
	Type = TypeVal;
}

//Accessor Function Definitions
string BankAccount::getName() {
	return(Name);
}

string BankAccount::getDate() {
	return(Date);
}

string BankAccount::getType() {
	return(Type);
}

//Print function
void BankAccount::print() {
	cout << "BankAccount name: " << Name << endl;
	cout << "BankAccount initialization date: " << Date << endl;
	cout << "BankAccount type: " << Type << endl; 
	cout << endl;
}
