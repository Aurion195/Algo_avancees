#include "Tris.cpp"

#include <iostream>

using namespace std ; 

void Test()
{
	bool complet = false ;
	int cpt = 1 ;
	double x1 = 0.0 ;
	double x2 = 0.0 ;
	double x3 = 0.0 ;
	double x4 = 0.0 ;
	double x5 = 0.0 ;
	double max = 0.0 ;

	while(complet == false)
	{
		int * T = RamdomArray(taille) ;
		cout << "Voici le Tableau  d'entier non trier" << endl ;
		afficher(T,taille) ;
		cout << endl << endl << endl ;

		if(cpt == 1)
		{
			cout << "Tri bulle" << endl ;
			Tri_bulle(T,taille,x1) ;
			afficher(T,taille) ;
			cout << endl << "Le temps d'éxecution du Tri bulle est de " << x1 << endl ; 
			cpt++ ;
			cout << endl <<"---------------------------------------------------------------------------------" << endl ;
		}
		else if(cpt == 2)
		{
			cout << "Tri insertion" << endl ;
			int N = taille - 1 ;
			Tri_insertion(T,N,x2) ;
			afficher(T,taille) ;
			cout << endl << "Le temps d'éxecution du Tri insertion est de " << x2 << endl ;
			cpt++ ;
			cout << endl <<"---------------------------------------------------------------------------------" << endl ;
		}
		else if(cpt == 3)
		{
			cout << "Tri fusion" << endl ;
			Tri_fusion(T,taille,x3) ;
			afficher(T,taille) ;
			cout << endl << "Le temps d'éxecution du Tri fusion est de " << x3 << endl ;
			cpt++ ;
			cout << endl <<"---------------------------------------------------------------------------------" << endl ;
		}
		else if(cpt == 4)
		{
			cout << "Tri rapide" << endl ;
			Tri_rapide(T,a,b,x4) ;
			afficher(T,taille) ;
			cout << endl << "Le temps d'éxecution du Tri rapide est de " << x4 << endl ;
			cpt++ ;
			cout << endl <<"---------------------------------------------------------------------------------" << endl ;
		}
		else if(cpt == 5)
		{
			cout << "Tris tas" << endl ;
			int N = taille-1 ;
			Tri_tas(T,taille,x5) ;
			afficher(T,taille) ;
			cout << endl << "Le temps d'éxecution du Tri tas est de " << x5 << endl ;
			cout << endl <<"---------------------------------------------------------------------------------" << endl ;

			complet = true ;
		}
	}
}