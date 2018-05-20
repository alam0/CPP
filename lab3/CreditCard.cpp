//CreditCard.cpp
//Author: Aron Lam
#include <iostream>
#include <math.h>
#include <string>
#include "BankAccount.h"
#include "CreditCard.h"
using namespace std;

CreditCard::CreditCard(string NameVal, string DateVal, string TypeVal) : CardNumber("20212016"), BankAccount(NameVal, DateVal, TypeVal) {
	
	CardNumber = "20212016";
	TrackingChip = 1;
}

void CreditCard::print(){
	cout <<"Name: "<< getName() << endl;
	cout <<"Date: "<< getDate() << endl; 
	cout <<"Type: "<< getType() << endl;
	cout <<"Card Number: "<< CardNumber << endl;
	if(TrackingChip){
		cout <<"This card has a tracking chip." << endl;
	} else {
		cout <<"This card does not have a tracking chip." << endl;
	}
	cout << endl;
}
