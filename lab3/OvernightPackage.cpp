//OvernightPackage.cpp
//Author: Aron Lam

#include <iostream>
#include <math.h>
#include <string>
#include "Package.h"
#include "OvernightPackage.h"
using namespace std;

//constructor
OvernightPackage::OvernightPackage(string NameVal, string ZipcodeVal, double WeightVal, double CostPerOunceVal, double OvernightCostVal, double extraCostPerOunceVal) 
	//set variables
	: Package(NameVal, ZipcodeVal, WeightVal, CostPerOunceVal){
	OvernightCost = OvernightCostVal;
	extraCostPerOunce = extraCostPerOunceVal;
}
double OvernightPackage::getextraCostPerOunce(){
	return(extraCostPerOunce);
}
double OvernightPackage::getOvernightCost(){
	return(OvernightCost);
}

double OvernightPackage::CalculateCost(){
	double cost = getWeight()*(getCostPerOunce() + getextraCostPerOunce()) + getOvernightCost(); //including extraCostPerOunce
	return(cost);	
}

void OvernightPackage::print(){
	cout << "Name: " << getName() << endl;
	cout << "Zipcode: " << getZipcode() << endl; 
	cout << "Weight: " << getWeight() << endl;
	cout << "Cost: " << CalculateCost() << endl;
	cout << endl;
}
