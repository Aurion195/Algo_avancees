#include "Arbre.h"

#include <iostream>

using namespace std ;


//------------------------------------------------------------------------------------------------
//-------------------Fonction de la structure noeud ----------------------------------------------
//------------------------------------------------------------------------------------------------

noeud * NN(int x, noeud * r)
{
	noeud * tmp = new noeud ;

	tmp->cle = x ;
	tmp->fg = NULL ;
	tmp->fd = NULL ;
	tmp->pere = r ;

	return tmp ;
}

//Retourne l'addresse de la valeur minimum dans tous l'arbre
void arbre::Minimum()
{
	noeud * tmp = root ;

	while(tmp && tmp->fg)
	{
		tmp = tmp->fg ;
	}

	cout << "La plus petite valeur " << tmp->cle << " est contenu dans le noeud " << tmp << endl ;
}

void arbre::Maximum()
{
	noeud * tmp = root ;

	while(tmp && tmp->fd)
	{
		tmp = tmp->fd ;
	}

	cout << "La plus grande valeur " << tmp->cle << " est contenu dans le noeud " << tmp << endl ;
}

//Retourne le successeur et le prédécesseur d'un noeud
noeud * arbre::Maxi(noeud * tmp)
{
	noeud * r = root ;

	while(r->fd != NULL)
	{
		r = r->fd ;
	}

	return r ;
}

noeud * arbre::Mini(noeud * tmp)
{
	noeud * r = tmp ;

	while(r->fg != NULL)
	{
		r = r->fg ;
	}

	return r ;
}


noeud * arbre::successeur(noeud * x)
{
	noeud * tmp = x ;
	noeud * tmp_bis = NULL ;

	if(tmp && tmp->fd)
	{
		noeud * z = Mini(tmp->fd) ;
		return z ;
	}
	else
	{
		if(tmp)
		{
			tmp_bis = tmp->pere ;
			while((tmp_bis) && (tmp == tmp_bis->fd))
			{
				tmp = tmp_bis ;
				tmp_bis = tmp_bis->pere ;
			}
		}

		return tmp_bis ;
	}
}


noeud * arbre::predecesseur(noeud  * x)
{
	noeud * tmp = x ;
	noeud * tmp_bis ;

	if(tmp && tmp->fg)
	{
		return Maxi(tmp->fg) ;
	}
	else
	{
		if(tmp)
		{
			tmp_bis = tmp->pere ;
			while((tmp_bis) && (tmp == tmp_bis->fg))
			{
				tmp = tmp_bis ;
				tmp_bis = tmp_bis->pere ;
			}
		}
		return tmp_bis ;
	}
}


//Permet de renvoyer l'adresse du neoud
noeud * arbre::trouve(int x, noeud * r)
{
	if(r == NULL) return NULL ;
	else
	{
		if(r->cle == x) return r ;
		if(x > r->cle) trouve(x, r->fd) ;
		else trouve(x, r->fg) ;
	}
}