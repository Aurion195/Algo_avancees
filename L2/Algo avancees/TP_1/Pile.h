#ifndef DEF_PILE_H
#define DEF_PILE_H

class pile
{
	int debut ;
	int * tab ;
	int max ;

	public : 
		pile() ;
		pile(int N) ;
		~pile() ;
		bool vide() ;
		bool pleine() ;
		void empiler(int x) ;
		int depiler() ;
		void afficher_pile() ;
} ;

#endif 