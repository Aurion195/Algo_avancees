#include "Liste.cpp"
#include "Pile.cpp"
#include "File.cpp"

#include <iostream>
#include <cstdlib>

using namespace std ;

int main()
{
	//-----------------------------------------------	Liste de Maillon

	/*Liste L ;

	L.InsertionT(5) ;
	L.InsertionT(8) ;
	L.InsertionT(10) ;
	L.InsertionQ(20) ; 

	cout << "Liste avant modification ! " << endl ;
	L.afficher() ; 

	maillon * tmp = L.recherche(8) ;
	L.supprime(tmp) ;

	cout << "\n" << "\n" << "Liste après modification ! " << endl ;
	L.afficher() ;

	//system("clear") ;*/

	
	//-----------------------------------------------	Pile

	pile P(10) ;

	P.empiler(5) ;
	P.empiler(10) ;
	P.empiler(15) ;

	cout << "Pile avant modification ! " << endl ;

	P.afficher_pile() ;

	int a = P.depiler() ;
	int b = P.depiler() ;
	
	P.empiler(50) ;

	cout << "\n" << "Pile après modification ! " << endl ;
	P.afficher_pile() ;

	system("clear") ;
	
	//----------------------------------------------	File

	/*file F(5) ;

	F.enfiler(1) ; 
	F.enfiler(2) ; 
	F.enfiler(3) ;

	cout << "File avant modification ! 	" << endl ;
	F.afficher_file() ;

	F.defiler() ;
	F.defiler() ;
	F.enfiler(4) ;

	cout << "\n" << "\n" << "File après modification ! " << endl ;
	F.afficher_file() ;
	*/

	return 0;
}