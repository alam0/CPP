//estimatingpi.cpp
//Author: Aron Lam
//Prelab
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function Prototype
double calcPiValue(double );

//Main
int main(){
	double numerator = 4, pi;
	int i, terms = 0;
	while(terms < 2){
		cout << "Error! Provided value must be >= 2!" << endl;
		cout << "Please enter the number of terms in the series: ";
		cin >> terms;
	};
	for(i = 1;i <= terms;i++){
		pi = calcPiValue(i);
		cout << "Estimate after " << i << "term(s): " << pi << endl;
	};
	return 0;
}

//Function Definition
double calcPiValue(double terms){
	double value = 0;
	double i; //i for incrementing
	double d;//d relates the term number to its correct odd denominator
	double sign = 1; // sign changes
	d = 2*terms - 1; 
	for(i = 1;i <= d;i+=2){
		value+= 4/(i*sign);
		sign*=-1; //change sign with each term
	};
	return value;
};
