#include "Maillon.h"
#include "Liste.h"
#include "Pile.h"
#include "File.h"

#include "Liste.cpp"

#include <iostream>

using namespace std ;

int main()
{
	Liste L ;

	L.InsertionT(5) ;
	L.InsertionT(10) ;
	L.InsertionT(15) ;

	//maillon * tmp = L.recherche(15) ;

	//L.supprime(tmp) ;

	L.afficher() ;

	return 0;
}