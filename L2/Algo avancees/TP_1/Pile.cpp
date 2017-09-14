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
	if(debut == 0) return true ;
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
		debut += 1 ;
		tab[debut] = x ;
	}
	else
	{
		return ;
	}

}

void pile::depiler()
{
	if(vide())
	{
		cout << "La pile est vide ! " << endl ;
		return ;
	}
	else
	{
		debut -= 1 ;
	}
}

void pile::afficher_pile()
{
	for(int i = 0 ; i <= debut ; i++)
	{
		cout << i << "	|	" << tab[i] << endl ;
	}
}