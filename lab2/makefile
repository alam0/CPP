all:	C4game Ration

rmain.o: rmain.cpp
			g++ -c rmain.cpp
			
Ration: rmain.o rational.o 
			g++ rmain.o rational.o -o Ration
			
rational.o: rational.cpp
			g++ -c rational.cpp		

main.o:	main.cpp
			g++ -c main.cpp
			
C4game:	main.o C4Col.o C4Board.o
			g++ main.o C4Col.o C4Board.o -o C4game
			
C4Col.o:	C4Col.cpp
			g++ -c C4Col.cpp
			
C4Board.o: C4Board.cpp
			g++ -c C4Board.cpp
			
clean:
			rm -f *.o C4game Ration
