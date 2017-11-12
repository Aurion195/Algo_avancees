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
noeud * arbre::Maxi()
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

noeud * arbre::successeur(int x)
{
	noeud * tmp = trouve(x,root) ;
	noeud * tmp_bis ;

	if(tmp && tmp->fd) ;
	{
		return Mini(tmp->fd) ;
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


noeud * arbre::predecesseur(int x)
{
	noeud * tmp = Maxi() ;
	noeud * r = root ;

	while(r != NULL)
	{
		if(r->cle >= x)
		{
			if(r->fd == tmp)
			{
				return r ;
			}

			r = r->fd ;
		}
		else
		{
			if(r->fg == tmp)
			{
				return r ;
			}

			r = r->fg ;
		}
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

	return NULL ;
}