//BoatLoan.cpp
//Author: Aron Lam
#include <iostream>
#include <math.h>
#include <string>
#include "BankAccount.h"
#include "BoatLoan.h"
using namespace std;

BoatLoan::BoatLoan(string NameVal, string DateVal, string TypeVal) : numberofMonths("3"), maxLootStorage("500"), BankAccount(NameVal, DateVal, TypeVal) {
}

void BoatLoan::print(){
	cout <<"Name: "<< getName() << endl;
	cout <<"Date: "<< getDate() << endl; 
	cout <<"Type: "<< getType() << endl;
	cout << "You only have " << numberofMonths << " months until your galleon is your own!" << endl;
	cout << "Please fill up your " << maxLootStorage << " sqft responsibly." << endl;
	cout << endl;
}
