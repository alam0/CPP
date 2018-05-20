all:	clean	Boats	Shipping BoatsComp

#Part 1: BlackBeard 

main.o: main.cpp
	g++ -c main.cpp
			
BankAccount.o:	BankAccount.cpp
	g++ -c BankAccount.cpp
					
BoatLoan.o:	BoatLoan.cpp
	g++ -c BoatLoan.cpp
				
CreditCard.o:	CreditCard.cpp
	g++ -c CreditCard.cpp
	
Boats: main.o BankAccount.o BoatLoan.o CreditCard.o 
	g++ main.o BankAccount.o BoatLoan.o CreditCard.o -o Boats

#Part 2: Amazon	

pmain.o:	pmain.cpp
	g++ -c pmain.cpp
	
Package.o:	Package.cpp
	g++ -c Package.cpp

TwoDayPackage.o: TwoDayPackage.cpp
	g++ -c TwoDayPackage.cpp

OvernightPackage.o: OvernightPackage.cpp
	g++ -c OvernightPackage.cpp
	
Shipping: pmain.o Package.o TwoDayPackage.o OvernightPackage.o
	g++ pmain.o Package.o TwoDayPackage.o OvernightPackage.o -o Shipping
	
#Part 3: Composition (BankAcctComp, BoatLoanComp, CreditCardComp)

maincomp.o: maincomp.cpp
	g++ -c maincomp.cpp

BankAcctComp.o: BankAcctComp.cpp
	g++ -c BankAcctComp.cpp
	
	

CreditCardComp.o: CreditCardComp.cpp
	g++ -c CreditCardComp.cpp

BoatsComp: maincomp.o BankAcctComp.o CreditCardComp.o
	g++ maincomp.o BankAcctComp.o CreditCardComp.o -o BoatsComp

#Clean:
clean:
	rm -f *.o *~ Boats	Shipping BoatsComp

