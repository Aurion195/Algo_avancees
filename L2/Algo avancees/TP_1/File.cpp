#include "File.h"

#include <iostream>

using namespace std ;

//-------------------------------------------------------		File

file::file()
{
	max = 0 ;
	debut = 0 ;
	queu = 0 ; 

	tab = new int[max] ;
}

file::file(int N)
{	
	cout << "Une file de " << max << " places vient d'être créer ! rgujrgrhgu" << endl ;
	max = N ;
	debut = queu = 0 ;

	tab = new int[max] ;
}

file::~file()
{
	delete [] tab ;
}

bool file::vide()
{
	if(debut == queu) return true ;
	return false ;
}

bool file::pleine()
{
	if(queu == max) return true ;
	return false ;
}

void file::enfiler(int x)
{
	if(!pleine())
	{
		tab[queu] = x ;

		queu++ ;
	}
	else cout << "Pile pleine !!" << endl ;
}

void file::defiler()
{
	int tmp = 0 ;

	if(!vide())
	{
		tmp = tab[0] ;
		
		for(int i = 0 ; i < queu ; i++)
		{
			tab[i] = tab[i+1] ;
		}

		queu-- ;

		cout << "La valeur " << tmp << " vient de sortir de la file ! " << endl ;
	}
	else
	{
		cout << "Erreur : file vide il n'y a rien a enlever ! " << endl ;
	}
}

void file::afficher_file()
{
	for(int i = debut ; i < queu ; i++)
	{
		cout << i << "	|	" << tab[i] << endl ;
	}
}