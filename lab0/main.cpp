#include <iostream>
#include <string>
#include "mortgage.h"
using namespace std;

int main(){
	mortgage first(10000, 5.0, 500); //uses non-default initialization
	mortgage second; //uses default constructor, mortgage of $100k; 
	
	//Demonstrate Functions requested
	second.credit(10000.00);
	cout << "Current balance after crediting second mortgage 10K: " << second.getPrincipal() << endl;
	
	cout << "Amortization schedule for first mortgage: " << endl;
	first.amortize();
	
	return 0;
};
