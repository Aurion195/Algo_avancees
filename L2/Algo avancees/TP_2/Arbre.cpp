#include "Noeud.h"

#include <iostream>
#include <cstring>


using namespace std ;


//-------------- Renvoi un noeud, qui permet de créer l'arbre

noeud * NN(char * nom,noeud * x)
{
    noeud * tmp = new noeud ;

    tmp->name = nom ;
    tmp->pere = x ;
    tmp->fg = NULL ;
    tmp->frd = NULL ;

   return tmp;
}

//------------- Céer un arbre dont la racine est "/", est current pointe sur root
arbre::arbre()													
{
	char * t = (char*)"/"  ;
	root = NN(t,NULL) ;											
	current = root ;				
}

//------------ Supprime l'arbre de manière récursive
void arbre::del(noeud * r)
{
	if(r == NULL) return ;
	else
	{
		del(r->fg) ;
		del(r->frd) ;
	}
	
	delete [] r ;
}

//------------- Destructeur de l'arbre
arbre::~arbre()
{
	if(root) 
	{
		del(root) ;
	}
}

//------------- Renvoi le nom du répertoire courrant
void arbre::pwd()
{
	afficher(current) ;
	cout << endl ;
	cout << "Le répertoire courrant est : " << current->name << endl ;
}

//------------ Renvoi un booléen si le nom est dedans
bool arbre::find(char * nom)
{
	noeud * tmp = current ;

	if(tmp == NULL) return false ;

	tmp = tmp->fg ;

	while(tmp != NULL)
	{
		tmp = tmp->frd ;
		if(tmp->name == nom) return true ;
	}

	return false ;
}

//------------ Renvoi l'adresse du noeud contenant le nom
noeud * arbre::Find(char * nom)
{
	noeud * tmp = current ;

	if(current->fg == NULL) return current ;

	current = current->fg ;

	while(tmp != NULL)
	{
		if(strcmp(tmp->name,nom) == 0) return tmp ;
		tmp = tmp->frd ;
	}

	return current ;
}

//------------- Permet d'insérer un noeud
void arbre::Insertion(noeud * x, noeud * y)
{
	if(x != NULL && y != NULL)
	{
		x->frd = y->fg ;
		y->fg = x ;
		x->pere = y ;
	}
}

//------------- Permet de créer des sous-dossiers dans le répertoire courrant
void arbre::mkdir(char * nom)
{
	int l = strlen(nom) ;
	char * tab = new char[l] ;
	strcpy(tab,nom) ;

	char * tmp ;
	noeud * x = current ;

	if(tab[0] == '/')
	{
		current = root ;
		tab = tab + 1 ;
	}

	tmp = tab ;

	while((*tmp) != '\0')
	{
		if((*tmp) == '/')
		{
			tmp[0] = '\0' ;

			if ((tmp-tab) >= 1)
			{
				current = Find(tab) ;
			}

			tab = tmp + 1 ;
		}

		tmp = tmp + 1 ;
	}

	if((tmp-tab) >= 1)
	{	
		Insertion(NN(tab,current),current) ;
		current = Find(tab) ;
	}
}

//------------- Pointe sur current le noeud contenant le nom
void arbre::cd(char * nom)
{	
	if(nom == "..") current = current->pere ;
	if(nom == ".") current = root ;
	if(nom != "." && nom != "..") current = Find(nom) ;
}

//------------ Permet d'afficher un noeud contenu dans l'arbre
void arbre::afficher(noeud * tmp)
{
	if(tmp == NULL) return ;

	afficher(tmp->pere) ;
	if(tmp->name == "/") cout << "/-> " ;
	else 
	{
		cout << "/" << tmp->name ;
	}
}

void arbre::Afficher(char * nom)
{
	noeud * tmp = root ;
	noeud * save = root ;
	bool in = false ; ;
	recherche(nom,tmp,save,in) ;
	if(in == true) afficher(save) ;
	else cout << "Pas de fichier" << endl ;
	cout << endl ;
}

void arbre::recherche(char * nom, noeud * tmp,noeud * &save, bool& in)
{
	if(tmp == NULL) return ;
	else
	{
		if(tmp->name == nom) 
		{
			save = tmp ;
			in = true ;
			return ;
		}
			recherche(nom,tmp->fg,save,in) ;
			recherche(nom,tmp->frd,save,in) ;
	}
}