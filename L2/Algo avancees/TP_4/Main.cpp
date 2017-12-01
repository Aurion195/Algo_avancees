#include "Tris.cpp"
#include <iostream>

using namespace std ;

int main()
{
	int T[5] = {1, 20 , 8, 15, 10} ;

	afficher(T, 5) ;
	cout << endl ;

	/*cout << "Tris bulle" << endl ;
	Tri_bulle(T, 5) ;
	afficher(T,5) ;*/

	/*cout << endl << "Tri par insertion" << endl ;
	Tri_insertion(T, 5) ;
	afficher(T, 5) ;*/

	cout << endl << "Tri par fusion" << endl ;
	int Z[6] = {1, 20 , 8, 15, 10 ,25} ;
	int * A = Tri_fusion(Z,0,5,6) ;
	afficher(A,6) ;

	return 0 ;
}