//OvernightPackage.h Class Definition
//Author: Aron Lam

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <iostream>
#include <math.h>
#include <string>
#include "Package.h"
using namespace std;

//Overnight Package inherits from Package
class OvernightPackage : public Package { 

	public:
		//constructor
		OvernightPackage(string = "empty", string = "empty", double Weight = 10, double CostPerOunce = 0.5, double OvernightCost = 10, double extraCostPerOunce = 0.25); //fallback values
		
		
		void print(); //to print details of 
		double getextraCostPerOunce();
		double getOvernightCost();
		double CalculateCost();
		
	private:
		double OvernightCost; //flat fee for overnight shipping
		double extraCostPerOunce; //extracost/ounce for overnight shipping
	
	
};

#endif
