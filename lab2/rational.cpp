//Rational.cpp
//Author: Aron Lam
#include <iostream>
#include <math.h>
#include "rational.h"
using namespace std;

//Overloading <<
ostream &operator<<(ostream &output, Rational &R){
	output << (float)R.numerator/R.denominator << endl; //casting as float due to integer division resulting in 0
	return (output); //enables cascading of the "<<" operator by returning the output stream given to the friend function of type ostream
}

//Constructors
Rational::Rational(){
	numerator = 1; //default rational = 1
	denominator = 1;
}
Rational::Rational(int a, int b){ //nondefault
	if(isdenominator0(b)){
	b = 1; //if user entered denominator is 0, set denominator = to 1
	}
	numerator = a;
	denominator = b;
	simplify(); //simplify in the constructor
}

int Rational::isdenominator0(int denominator){
	if(denominator == 0){
		cout << "Error! Denominator is 0!" << endl;
		return 1; //if denom = 0, print message 
	} else {
		return 0;
	}
}

int Rational::gcd(int x, int y){ //private gcd function
	int temp;
	while(y != 0){//tested this gcd by printing numerator and denominator in the simplify function
		temp = y;
		y = x%temp;
		x = temp;
	}
	return x;
}

void Rational::simplify(){ //uses private gcd function
	int divisor = gcd(numerator, denominator);
	numerator = numerator/divisor;
	denominator = denominator/divisor;
	//cout << numerator << endl;// used to see if gcd worked correctly
	//cout << denominator << endl;
};
//These 4 operators take in a Rational R and return Rational as well
Rational Rational::operator+(Rational R){
	Rational Rplus;
	Rplus.numerator = (numerator*R.denominator) + (R.numerator*denominator);
	Rplus.denominator = denominator * R.denominator;
	return(Rplus);
}

Rational Rational::operator-(Rational R){
	Rational Rsub;
	Rsub.numerator = (numerator*R.denominator) - (R.numerator*denominator);
	Rsub.denominator = denominator * R.denominator;
	return(Rsub);
}

Rational Rational::operator/(Rational R){
	Rational Rdivide;
	Rdivide.numerator = numerator * R.denominator;
	Rdivide.denominator = denominator * R.numerator;
	return(Rdivide);
}

Rational Rational::operator*(Rational R){
	Rational Rmultiply;
	Rmultiply.numerator = numerator * R.numerator;
	Rmultiply.denominator = denominator * R.denominator;
	return(Rmultiply);
}

int Rational::operator==(Rational R){ //returns 1 if true, 0 if false
	if(numerator == R.numerator && denominator == R.denominator){
		return(1);
	} else {
		return(0);
	}
}

Rational Rational::operator^(double power){ // takes in a double for power raised to
	Rational Rsquared;
	Rsquared.numerator = pow(numerator, power);
	Rsquared.denominator = pow(denominator, power);
	return(Rsquared);
}




