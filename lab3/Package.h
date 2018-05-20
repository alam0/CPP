//Package.h Base Class Definition	
//Author: Aron Lam

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Package {
	
	public:
		//Constructor
		Package(string = "empty", string = "empty", double = 16, double = 0.25);
		//Functions
		virtual double CalculateCost();
		
		virtual void print(); //virtual so that derived classes may have their own void print(); functions
		
		//Accessor Functions
		string getName(); 
		string getZipcode();
		double getWeight();
		double getCostPerOunce();

	private: //so inherited classes may access them directly
		//3 Data Members
		string Name;
		string Zipcode; 
		double Weight; //package weight, non-negative
		double CostPerOunce; //cost per ounce to ship the package, non-negative
		
};
#endif
