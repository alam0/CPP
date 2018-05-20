//TwoDayPackage.cpp
//Author: Aron Lam

#include <iostream>
#include <math.h>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage(string NameVal, string ZipcodeVal, double WeightVal, double CostPerOunceVal, double TwoDayCostVal) : Package(NameVal, ZipcodeVal, WeightVal, CostPerOunceVal){
	
	TwoDayCost = TwoDayCostVal;
	
}
double TwoDayPackage::getTwoDayCost(){
	return(TwoDayCost);
}

double TwoDayPackage::CalculateCost(){
	double Cost = getWeight()*getCostPerOunce() + getTwoDayCost(); //additional twodaycost
	return(Cost);	
}

void TwoDayPackage::print(){
	cout <<"Name: "<< getName() << endl;
	cout <<"Zipcode: "<< getZipcode() << endl; 
	cout <<"Weight: "<< getWeight() << endl;
	cout << "Cost: " << CalculateCost() << endl;
	cout << endl;
}
