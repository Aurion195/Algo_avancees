#ifndef DEF_ARBRE_H
#define DEF_ARBRE_H

struct noeud
{
	int cle ;
	noeud * fg ;
	noeud * fd ;
	noeud * pere ;
} ;

class arbre
{
	noeud * root ;
	noeud * current ;

	public :
	//Fonction de la classe arbre
		arbre() ;
		~arbre() ;
		void suppression(noeud * r) ;
		void Insertion(int x) ;
		void ajouter(int x, noeud * r) ;
		void afficher() ;
		void print(noeud * r) ;
		bool recherche(int x) ;
		int hauteur() ;
		int haut(noeud * r) ;
		void supprimer(int x) ;
		void del(noeud * r, noeud * x) ;
		void deplacer(noeud * r, noeud * u, noeud * y) ;

	//Fonction de la structure noeud
		void Maximum() ;
		void Minimum() ;

		noeud * Maxi(noeud * tmp) ;
		noeud * Mini(noeud * tmp) ;
		noeud * successeur(noeud * x) ;
		noeud * predecesseur(noeud * x) ;
		noeud * trouve(int x, noeud * r) ;
} ;

#endif