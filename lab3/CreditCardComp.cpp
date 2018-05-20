//CreditCard.cpp
//Author: Aron Lam
#include <iostream>
#include <math.h>
#include <string>
#include "BankAcctComp.h"
#include "CreditCardComp.h"
using namespace std;

CreditCardComp::CreditCardComp() 
	//setting variables
	: card("Notre Dame", "Feb 7, 2016", "Gold"){ 
	CardNumber = "20212016";
	TrackingChip = 1;
	
}

void CreditCardComp::print(){

	cout <<"Name: "<< card.getName() << endl;
	cout <<"Date: "<< card.getDate() << endl; 
	cout <<"Type: "<< card.getType() << endl;
	cout <<"Card Number: "<< CardNumber << endl;
	if(TrackingChip){
		cout <<"This card has a tracking chip." << endl;
	} else {
		cout <<"This card does not have a tracking chip." << endl;
	}
	cout << endl;
	
}
