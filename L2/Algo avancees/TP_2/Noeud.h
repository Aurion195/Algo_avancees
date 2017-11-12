#ifndef DEF_ARBRE_H
#define DEF_ARBRE_H

#include <iostream>

struct noeud
{
	char * name ;
	noeud * pere ;
	noeud * fg ;
	noeud * frd ;
} ;

class arbre
{
	noeud *root ;
	noeud *current ;

	public : 
		arbre() ;
		~arbre() ;
		void del(noeud * tmp) ;
		bool find(char * nom) ;
		noeud * Find(char * nom) ;
		void Insertion(noeud* x, noeud *y) ;
		void recherche(char * nom, noeud * tmp, noeud * &save,bool &in) ;
		void afficher(noeud * tmp) ;
		void Afficher(char * nom) ;
		void mkdir(char * nom) ;
		void cd(char * nom) ;
		void pwd() ;
} ;
#endif