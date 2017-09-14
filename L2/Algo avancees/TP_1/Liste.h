#ifndef DEF_LISTE_H
#define DEF_LISTE_H

#include "Maillon.h"

class Liste
{
	maillon * tete ;
	maillon * queu ;

	public :
		Liste() ;
		~Liste() ;
		bool vide() ;
		void Insertiontete(maillon *x) ;
		void InsertionT(int x) ;
		void Insertionqueu(maillon * x) ;
		void InsertionQ(int x) ;
		maillon * recherche(int x) ;
		void supprime(maillon * tmp) ;
		void afficher() ;
} ;

#endif 