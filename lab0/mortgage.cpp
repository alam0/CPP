//mortgage.cpp
//Author: Aron Lam
#include <iostream>
#include <iomanip>
#include "mortgage.h"

using namespace std;

mortgage::mortgage(){
	principal = 100000;
	rate =  10.0;
	payment = 800;
}
mortgage::mortgage(double p, double r, double pay){
	principal = p;
	if(rate <= 0.0){
		cout << "The interest rate provided is negative!" << endl;
	};
	rate = r;
	if(pay < ((r/100)/12)*p){
		cout << "The payment provided is too small!" << endl;
	};
	payment = pay;
}
//Function Definitions

//deducts value from current principal
void mortgage::credit(double value){ 
	principal = getPrincipal() - value;
}

//returns the current principal remaining
double mortgage::getPrincipal(){ 
	return principal;
}
	
//calculates and displays a correct and clean amortization table
void mortgage::amortize(){ 
	int month = 1;
	double temprate, interest;
	double balance = principal;
	temprate = rate/100;
	temprate = temprate/12; //since we are using months
	cout << "Month \t Payment \t Interest \t Balance" << endl;
	while(payment < balance){ //all payments other than last
		interest = temprate*balance;
		balance -= payment; 
		balance += interest; //update balance
		cout << month << "\t " << setprecision(5) << payment << "\t\t " << setprecision(4) << interest << "\t\t " << setprecision(6) << balance << endl; //tabs to clearly display data
		month++;
		if(payment > balance){ //last payment special
			payment = balance;
			balance -= payment;
			cout << month << "\t " << setprecision(5) << payment << "\t\t " << setprecision(4) << interest << "\t\t " << setprecision(6) << balance << endl; //print one last time for last payment
		};
	};	
}

