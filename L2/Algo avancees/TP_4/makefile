all : Tris
	./Tris > Texte/Resultat.txt

Tris : Main.cpp Tris.o
	g++ Main.cpp -o Tris

Tri.o : Test.cpp Tris.cpp
	g++ -c Tris.cpp -o Tri.o
	
clean : 
	rm -rf *.o

Mrpropper : clean
	rm -rf Tris

Destructeur : 
	rm Texte/Resultat.txt
