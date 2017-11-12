#include "Arbre.cpp" 

#include <iostream>

using namespace std ;

int main()
{
	cout << "------------ Initialisation de l'arbre ------------" << endl ;

	arbre A ;

	A.Insertion(5) ;
	A.Insertion(10) ;
	A.Insertion(15) ;
	A.Insertion(4) ;
	A.Insertion(3) ;
	//A.supprimer(3) ;

	A.afficher() ;

	cout << "\n" << "------------------- Exercices -------------------" << endl ;

	A.Maximum() ;
	A.Minimum() ;

	int x = A.hauteur() ;
	cout << "La hauteur de l'arbre est " << x << endl ;

	return 0 ;
}