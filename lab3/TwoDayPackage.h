//TwoDayPackage.h Class Definition
//Author: Aron Lam

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include <math.h>
#include <string>
#include "Package.h"
using namespace std;

//TwoDayPackage inherits from Package
class TwoDayPackage : public Package {

	public:
		//constructor
		TwoDayPackage(string = "empty", string = "empty", double Weight = 15, double CostPerOunce = 0.3, double TwoDayCost = 5); //fallback values for variable
		
		double getTwoDayCost();
		double CalculateCost();
		void print(); //to print details of 
		
	private:
		double TwoDayCost; //flat fee for Two-day Shipping
		
};

#endif
