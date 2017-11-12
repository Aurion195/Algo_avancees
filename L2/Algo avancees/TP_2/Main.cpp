#include "Noeud.h"
#include "Arbre.cpp"

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
	arbre A ;


	cout << "Initialisation de l'Arbre ! " << endl ;

	A.mkdir((char*)"/A") ;
	A.mkdir((char*)"A/B") ;
	A.mkdir((char*)"/C") ;
	A.cd(".") ;
	A.mkdir((char*)"C/D") ;


/*	//------------------Consignes !-------------------------
	//-----mkdir = permet de créer des dossiers dans le ----
	//-----dossier que pointe current ! --------------------
	//-----cd = Permet de mettre a current le dossier ------
	//-----dans lequel on veut qu'il pointe !---------------
	//-----"." = remonter au pere du noeud -----------------
	//-----".." = remonter à la racine du noeud ------------


	//------------1er niveau de l'arbre !--------------------
	A.mkdir((char*)"A") ;
	A.mkdir((char*)"B") ;
	A.mkdir((char*)"C") ;

	cout << "Création dans le réportoire B, de 3 sous répertoires." << endl ;
	//------Changement de répertoire de l'arbre--------------
	
	A.cd((char*)"B") ;
	A.mkdir((char*)"D") ;
	A.mkdir((char*)"E") ; 
	A.mkdir((char*)"F") ;

	cout << "Création dans le réportoire E, un sous répertoire G." << endl ;
	//-------Changement d'un autre réportoire----------------
	
	A.cd((char*)"E") ;
	A.mkdir((char*)"G") ;

	A.Afficher((char*)"G") ;

	A.cd("..") ;**/

	//A.Afficher("F") ;
	A.pwd() ;
}