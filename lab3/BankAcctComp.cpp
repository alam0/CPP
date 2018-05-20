//BankAcctComp.cpp
//Author: Aron Lam

#include <iostream>
#include <math.h>
#include <string>
#include "BankAcctComp.h"
using namespace std;

//Base class 
BankAcctComp::BankAcctComp(string NameVal, string DateVal, string TypeVal) {
	Name = NameVal;
	Date = DateVal;
	Type = TypeVal;
}

//Accessor Function Definitions
string BankAcctComp::getName() {
	return(Name);
}

string BankAcctComp::getDate() {
	return(Date);
}

string BankAcctComp::getType() {
	return(Type);
}

//Print function
void BankAcctComp::print() {
	cout << "BankAccount name: " << Name << endl;
	cout << "BankAccount initialization date: " << Date << endl;
	cout << "BankAccount type: " << Type << endl; 
	cout << endl;
}
