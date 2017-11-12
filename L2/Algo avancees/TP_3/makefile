ABR : Main.cpp Arbre.o Noeud.o
	g++ Main.cpp -o ABR

Arbre.o : Arbre.h Arbre.cpp
	g++ -c Arbre.cpp -o Arbre.o

Noeud.o : Arbre.h Noeud.cpp
	g++ -c Noeud.cpp -o Noeud.o

clean : 
	rm * .o 
