//Rational Class Definition
//Author: Aron Lam
#ifndef Rational_H
#define Rational_H
#include <iostream>
#include <math.h>
using namespace std;

class Rational{
	friend ostream &operator<<(ostream &, Rational &);
	public:
		Rational();
		Rational(int, int);
		int isdenominator0(int);
		void simplify();
		//overloading
		Rational operator+(Rational R);
		Rational operator-(Rational R);
		Rational operator/(Rational R);
		Rational operator*(Rational R);
		int operator==(Rational R);
		Rational operator^(double power);
	private:
		int numerator;
		int denominator;
		int gcd(int, int);
};
#endif
