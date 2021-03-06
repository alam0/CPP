//Main File for Rational
//Author: Aron Lam
#include <iostream>
#include <math.h>
#include "rational.h"
using namespace std;

int main(){
	int a, b, c, d, e, f, ask = 1, choice; //ask for while loop
	//int totalfractions = 2; //desired number of fractions 
	//for(int i = 0; i < totalfractions;i++){
	cout << "Please enter numerator1: ";
	cin >> a;
	cout << "Please enter denominator1: ";
	cin >> b;
	Rational r1(a, b);
	cout << "Please enter numerator2: ";
	cin >> c;
	cout << "Please enter denominator2: ";
	cin >> d;
	Rational r2(c, d);
	cout << "Please enter numerator3: ";
	cin >> e;
	cout << "Please enter denominator3: ";
	cin >> f;
	Rational r3(e, f);
	//cout << r1 << endl;
	//cout << r2 << endl;
	Rational r4, r5, r6, r7, r8, r9, r10, r11, r12; //instances of Rational for operations and functions
	while(ask){ //ask user to enter choice
		cout << "What would you like to do with your Rationals? Enter a choice number: " << endl 
		<< "1. Addition (r1+r2)" << endl 
		<< "2. Subtraction (r1-r2)"<< endl 
		<<"3. Multiplication (r1*r2)" << endl 
		<< "4. Division (r1/r2)" << endl 
		<< "5. Check Equality (r1 == r2)?" << endl 
		<< "6. Raise r1 to Power of 4 (r1^2)"<< endl 
		<< "7.Co-op: r1 + r2^3" << endl 
		<< "8.Difference between (product of r2 and r3) and r1" << endl 
		<< "9.(Quotient of r3 and r1)^2" << endl 
		<<"0. Quit" << endl;
		cin >> choice;
		switch(choice){
			case 1: //add
				r4 = r1+r2; 
				cout << "The sum of r1 and r2 is: " << r4 << endl;
				break;
			case 2:
				r5 = r1-r2;
				cout << "The difference between r1 and r2 is: " << r5 << endl;
			case 3: //multiply
				r6 = r1*r2;
				cout << "The product of r1 and r2 is: " <<r6 << endl;
				break;
			case 4: //divide
				r7 = r1/r2;
				cout << "The quotient of r1 and r2 is: " << r7 << endl;
				break;
			case 5: //check equality
				if(r1==r2){
					cout << "The two fractions are equal" << endl;
				} else {
					cout << "The two fractions are not equal" << endl;
				}
				break;
			case 6: //power
				r8 = r1^4.0;
				cout << "r1 raised to a power of 4 is: " << r8 << endl;
				break;
			case 7: //co-op + and ^
				r9 = r1+(r2^3.0);
				cout << "r1 + r2^3 is: " << r9 << endl;
				break;
			case 8:
				r10 = (r2*r3)-r1;
				cout << "The difference between the (product of r2 and r3) and r1 is: " << r10 << endl;
				break;
			case 9:
				r11 = (r3/r1)^2.0;
				cout << "The quotient of (r3 and r1)^2 is: " << r11 << endl;
				break;
			case 0: //quit
				ask = 0;
				break;
		}
	} 
	return 0;
};
