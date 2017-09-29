#include "Pile.h"

#include <iostream>

using namespace std ;

//-------------------------------------------------------		Pile

pile::pile()
{
	max = 0 ;
	debut = 0 ;

	tab = new int[max] ; 
}

pile::pile(int N)
{
	cout << "Une pile de " << N << " places vient d'être crées" << endl ;
	max = N ;
	debut = -1 ;

	tab = new int[max] ;
}

pile::~pile()
{
	delete [] tab ;
	cout << "Le destructeur est arrivée !!! " << endl ;
}

bool pile::vide()
{
	if(debut == -1) return true ;
	return false ;
}

bool pile::pleine()
{
	if(debut == max) return true ;
	return false ;
}

void pile::empiler(int x)
{

	if(!pleine())
	{
		debut++ ;
		tab[debut] = x ;
	}
	else
	{
		return ;
	}

}

int pile::depiler()
{
	if(vide())
	{
		cout << "La pile est vide ! " << endl ;
	}
	else
	{
		int x = 0 ;
		x = tab[debut] ;
		debut -= 1 ;

		return x ;
	}
}

void pile::afficher_pile()
{
	if(vide() == false)
	{
		for(int i = debut ; i >= 0 ; i--)
		{
			cout << i << "	|	" << tab[i] << endl ;
		}
	}
	else
	{
		cout << "La pile est vide, il n'y a rien à afficher ! " << endl ;
	}
}