/* FOR PART 2, pmain.cpp: Driver program  that  will  display  the  contents  of derived classes 
TwoDayPackage and an OvernightPackage
Author: Aron Lam
*/

#include <iostream>
#include <string>
#include <math.h>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main(){ //example values may be changed

	//Package(Name, Zipcode, Weight, CostPerOunce)
	Package p("Aron", "11365", 24.0, 0.25); 
	
	//TwoDayPackage(Name, Zipcode, Weight, CostPerOunce, TwoDayCost)
	TwoDayPackage tdp("Sam", "12345", 35.0, 0.50, 5.00);
	
	//OvernightPackage(Name, Zipcode, Weight(Ounces), CostPerOunce, OvernightCost, extraCostPerOunce)
	OvernightPackage op("Bobbit", "46556", 50.0, .7, 10.00, 0.3); 
	
	//print results w/ virtual print function
	p.print();
	tdp.print(); 
	op.print();
	
	//PART 3
	int numTwoDayPackages = 3;
	int numOvernightPackages = 3;
	int totalPackages = numTwoDayPackages + numOvernightPackages;
	double todayCost = 0;
	Package *today[totalPackages];
	
	today[0] = new TwoDayPackage ("Lam", "12345", 55.0, 0.50, 5.00);
	today[1] = new TwoDayPackage ("Zam", "12345", 15.0, 0.50, 5.00);
	today[2] = new TwoDayPackage ("Yam", "12345", 95.0, 0.50, 5.00);
	
	today[3] = new OvernightPackage ("Gobbit", "46556", 50.0, .7, 10.00, 0.3); 
	today[4] = new OvernightPackage ("Hobbit", "46556", 80.0, .7, 10.00, 0.3); 
	today[5] = new OvernightPackage ("Wobbit", "46556", 20.0, .7, 10.00, 0.3); 
	
	//Calculate Total Cost and Print
	for(int i = 0; i < totalPackages; i++){
		todayCost += today[i]->CalculateCost();
	}

	cout <<"Today's Cost of Shipping is: "<< todayCost << endl;
	
	return(0);
}
