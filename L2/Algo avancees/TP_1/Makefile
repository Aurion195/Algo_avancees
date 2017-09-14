Fonction : Liste.o Pile.o File.o
	g++ main.cpp -o Fonction

Liste.o : Liste.h Maillon.h Liste.cpp
	g++ -c Liste.cpp -o Liste.o

Pile.o : Pile.h Pile.cpp
	g++ -c Pile.cpp -o Pile.o

File.o : File.h File.cpp
	g++ -c File.cpp -o File.o

.Phony clean : 
	rm *.o Fonction