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

void arbre::ajouter(int x, noeud * r)							//Ajouter un noeud dans une feuille de l'arbre
{
	if(r->cle == x) return ;
	else
	{
		if(r->cle < x)											//Si la valeur est plus petite on dans le fd
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
        else													//Sinon on va dans le fg
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

void arbre::print(noeud * r)						//Affichage récursif et croissant
{
	if(r)
	{
		print(r->fg) ;
		cout << r->cle << " " ;
		print(r->fd) ;
	}
}

bool arbre::recherche(int x)						//renvoi vrai ou faux si la valeur est contenu dans l'arbre
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

int arbre::haut(noeud * n)						//Renvoi la hauteur d'un arbre
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
	if(root == NULL) cout << "L'arbre est vide." << endl ;
	noeud * tmp = trouve(x,root) ;						//On trouve le noeud dans l'arbre
	del(root, tmp) ;
}

void arbre::del(noeud * r, noeud * x)
{
	if(x->fg == NULL && x->fd == NULL)					//1er cas, le noeud est une feuille
	{
		if(x->pere->fg != NULL && x->pere->fg == x )
		{
			x->pere->fg = NULL ;
		}
		else
		{
			x->pere->fd = NULL ;
		}
	}
	else if((x->fg != NULL && x->fd == NULL) || (x->fd != NULL && x->fg == NULL))	//2eme cas, le neoud est une suite de fils droit ou gauche
	{
		if(x->fg != NULL)
		{
			x->pere->fg = x->fg ;
		}
		else
		{
			x->pere->fd = x->fd ;
		}
	}
	else		//3eme cas, le noeud a deux fils
	{
		noeud * tmp = successeur(x) ;				//On trouve son prédecesseur
		cout << "Le successeur de " << x->cle << " est  : " << tmp->cle << endl ;

		if(tmp->pere != x)							//Si le noeud predecesseur n'est pas son fils direct
		{
			deplacer(r,tmp,tmp->fd) ;				//On déplace le sous arbres dans la racine
			tmp->fd = x->fd ;						//On fais le lien
			tmp->fd->pere = tmp ;
			if(root == x) root = tmp ;
		}
		
		deplacer(r, x, tmp) ;
		tmp->fg = x->fg ;
		tmp->fg->pere = tmp ;
		if(root == x) root = tmp ;
	}

	delete [] x ;
}

void arbre::deplacer(noeud * r, noeud * u, noeud * v)		//u est le noeud contenant la valeur, r est la racine
{
	if(u->pere == NULL)
	{
		r = v ;
	}
	else
	{
		if(u == u->pere->fd)
		{
			u->pere->fd = v ;
		}
		else
		{
			u->pere->fg = v ;
		}
	}

	if(v != NULL)
	{
		v->pere = u->pere ;
	}
}