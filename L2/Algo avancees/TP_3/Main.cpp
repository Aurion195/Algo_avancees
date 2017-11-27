#include "Arbre.cpp" 

#include <iostream>

using namespace std ;

int main()
{
	cout << "------------ Initialisation de l'arbre ------------" << endl ;

	arbre A ;

	A.Insertion(5) ;
	A.Insertion(10) ;
	A.Insertion(4) ;
	A.Insertion(2) ;
	A.Insertion(3) ;
	A.Insertion(15) ;
	A.Insertion(14) ;
	A.Insertion(13) ;
	A.Insertion(20) ;
	
	
	A.supprimer(5) ;

	A.afficher() ;

	cout << "\n" << "------------------- Exercices -------------------" << endl ;

	A.Maximum() ;
	A.Minimum() ;

	int x = A.hauteur() ;
	cout << "La hauteur de l'arbre est " << x << endl ;


	return 0 ;
}