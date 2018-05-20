//Package.cpp
//Author: Aron Lam

#include <iostream>
#include <math.h>
#include <string>
#include "Package.h"
using namespace std;

//Base class 
Package::Package(string NameVal, string ZipcodeVal, double WeightVal, double CostPerOunceVal) {
	//Set Values
	Name = NameVal;
	Zipcode = ZipcodeVal;
	Weight = WeightVal;
	CostPerOunce = CostPerOunceVal;
	
}

//Accessor Functions
string Package::getName() {
	return(Name);
}

string Package::getZipcode() {
	return(Zipcode);
}

double Package::getWeight() {
	return(Weight);
}

double Package::getCostPerOunce(){
	return(CostPerOunce);
}

//Calculate Cost Function
double Package::CalculateCost() {
	double cost = Weight*CostPerOunce; 
	return(cost);
}

//Print Function
void Package::print() {

	cout << "Package Name: " << Name << endl;
	cout << "Package Zipcode: " << Zipcode << endl;
	cout << "Package Weight: " << Weight << endl; 
	cout << "Package Cost Per Ounce: " << CostPerOunce << endl; 
	cout << "Cost: " << CalculateCost() << endl;
	cout << endl;
	
}



