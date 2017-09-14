#include "Liste.h"
#include "Maillon.h"

#include <iostream>

using namespace std ;

//-----------------------------------------------		Mailon

/*maillon::~maillon()
{
	delete [] succ ;
}*/


//-----------------------------------------------		Liste

Liste::Liste()
{
	cout << "---------------------------" << endl ;
	cout << "Une liste est née !!" << "\n" << endl ;
	tete = NULL ;
	queu = NULL ;
}

Liste::~Liste()
{
	delete [] tete ;
	cout << "\n" << "La liste est détruite !!! :D" << endl ;
	cout << "----------------------------" << endl ;
}

bool Liste::vide()
{
	if(tete == NULL) return true ; 	return false ;
}

void Liste::Insertiontete(maillon *x)
{
	if(!vide())
	{	
		x->succ = tete ;
		tete->pred = x ;
	}
	else
	{
		queu = x ;
	}

	tete = x ;
	tete->pred = NULL ;

}

void Liste::Insertionqueu(maillon *x)
{
	if(tete == NULL)
	{
		Insertiontete(x) ;
		return ;
	}

	if(!vide())
	{
		queu->succ = x ;
		x->pred = queu ;
	}

	queu = x ;
}

void Liste::InsertionT(int x)
{
	maillon * tmp = new maillon ;

	tmp->val = x ;
	Insertiontete(tmp) ;
}

void Liste::InsertionQ(int x)
{
	maillon * tmp = new maillon ;

	tmp->val = x ;
	Insertionqueu(tmp) ;
}

void Liste::supprime(maillon * tmp)
{
	if(tmp->pred == NULL)
	{
		tete = tmp->succ ;
	}
	else
	{
		(tmp->pred)->succ = tmp->succ ;
	}

	if(tmp->succ != NULL)
	{
		(tmp->succ)->pred = tmp->pred ;
	}
}

void Liste::afficher()
{
	maillon * tmp = tete ;

	int i =0 ;

	while(tmp != NULL)
	{
		cout << "Le maillon n° " << i << " contient la valeur : " << tmp->val << " a l'adresse suivante : " << tmp << endl ;
		i++ ;
		tmp = tmp->succ ;
	}
}

maillon *  Liste::recherche(int x)
{
	maillon * tmp = tete ;

	while(tmp != NULL)
	{
		if(tmp->val == x) return tmp ;
		tmp = tmp->succ ;
	}

}


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
	debut = 0 ;

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
		tab[debut] = x ;
		debut += 1 ;
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
	for(int i = 0 ; i < debut ; i++)
	{
		cout << i << "	|	" << tab[i] << endl ;
	}
}