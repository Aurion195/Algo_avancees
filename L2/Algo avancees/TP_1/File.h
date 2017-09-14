#ifndef DEF_FILE_H
#define DEF_FILE_H

class file
{
	int debut ;
	int queu ;
	int * tab ;
	int max ;

	public :
		file() ;
		file(int N) ;
		~file() ;
		bool vide() ;
		bool pleine() ;
		void enfiler(int x) ;
		void defiler() ;
		void afficher_file() ;
} ;

#endif 