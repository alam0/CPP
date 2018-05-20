//main.cpp
//Author: Aron Lam

#include <iostream>
#include <string>
#include <math.h>
#include "BankAccount.h"
#include "BoatLoan.h"
#include "CreditCard.h"

int main(){

	BankAccount chase("Link", "July 4, 1776", "Dude "); //instance of base class
	BoatLoan sub("Mario", "Feb 7, 1996", "Fire "); //derived class
	CreditCard platinum("Yoshi", "Nov 16, 2016", "Egg "); //derived class
	
	chase.print();
	sub.print(); // print boatloan info
	platinum.print(); //print card info
	
	return 0;
}
