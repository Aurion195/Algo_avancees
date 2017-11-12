#include "Arbre.h"
#include "Noeud.cpp"

#include <iostream>

using namespace std ;


//------------------------------------------------------------------------------------------------
//-------------------Fonction de la classe Arbres ------------------------------------------------
//------------------------------------------------------------------------------------------------

arbre::arbre()
{
	root = NULL;
	current = root ;
}

arbre::~arbre()
{
	suppression(root) ;
}

void arbre::suppression(noeud * r)
{
	if(r == NULL) return ;
	else
	{
		suppression(r->fg) ;
		suppression(r->fd) ;
	}

	delete [] r ;
}

void arbre::Insertion(int x)
{
	if(root == NULL)
	{
		root = NN(x,NULL) ;
	}
	else
	{
		ajouter(x,root) ;
	}
}

void arbre::ajouter(int x, noeud * r)
{
	if(r->cle == x) return ;
	else
	{
		if(r->cle < x)
        {
                if(r->fd == NULL)
                {
                	r->fd = NN(x,r) ;
                }
                else
                {
                        return ajouter(x, r->fd);
                }
        }
        else
        {
                if(r->fg == NULL)
                {        
                	r->fg = NN(x,r) ;
				}
				else
				{
					return ajouter(x, r->fg) ;
				}
		}
	}
}

void arbre::afficher()
{
    if(root) print(root);
}

void arbre::print(noeud * r)
{
	if(r)
	{
		print(r->fg) ;
		cout << r->cle << " " ;
		print(r->fd) ;
	}
}

bool arbre::recherche(int x)
{
	noeud * r = root ;

	while(r != NULL && r->cle != x)
	{
		if(r->cle == x) return true ;

		if(r->cle <= x) r = r->fg ;
		if(r->cle >= x) r = r->fd ;
	}

	return false ;
}

int arbre::hauteur()
{
	haut(root) ;
}

int arbre::haut(noeud * n)
{
	int V1,V2 = 0 ;
	if(n == NULL) return 0 ;

	V1 = haut(n->fg) ;
	V2 = haut(n->fd) ;

	if(V1 > V2) return V1 + 1 ;
	else return V2 + 1 ;
}

void arbre::supprimer(int x)
{
	noeud * r = root ;
	if(r == NULL) cout << "L'arbre est vide." << endl ;
	noeud * tmp = trouve(x,r) ;
	deplacer(tmp,r) ;
}

void arbre::deplacer(noeud * u, noeud * r)		//u est le noeud contenant la valeur, r est la racine
{
	if(r == NULL) return ;

	if(r->fg == u)
	{
		r->fd = u->fd ; 
		r->fg = u->fg ;

		delete [] u ;
	}
	
	if(r->fd == u)
	{
		r->fd = u->fd ;
		r->fg = u->fg ;
		delete [] u ;
	}

	if(u->cle > r->cle) deplacer(u,r->fd) ;
	else deplacer(u,r->fg) ;
}