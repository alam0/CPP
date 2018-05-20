all: clean Card

Card: Cardmain.o CardDeck.o
	g++ Cardmain.o CardDeck.o -o Card
	
Cardmain.o:
	g++ -c Cardmain.cpp
	
CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

clean: 
	rm -f *.o *~ Card

