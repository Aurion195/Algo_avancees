#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std ;

const int taille = 4 ;
const int a = 0 ;
const int b = taille - 1 ;

int * RamdomArray(int taille)
{
	srand(time(NULL)) ;

	int * T = new int[taille] ;
	for(int i =0 ; i < taille ; i++)
	{
		int x = 0 ;
		x = rand()%50 + 1 ;
		T[i] = x ;
	}

	return T ;
}


void afficher(int * T, int taille)
{
	for(int i = 0 ; i < taille ; i++)
	{
		cout << T[i] << " / " ;
	}
}

void Tri_bulle(int * T, int taille, double& x1)
{
	clock_t temps ;

	for(int i = 0 ; i < taille-1 ; i++)
	{
		for(int j = taille-1 ; j > i ; j--)
		{
			if(T[j] < T[j-1])
			{
				swap(T[j-1], T[j]);							//Permet de faire comme les lignes précédentes
			}
		}
	}

	temps = clock() ;
	x1 = (double)temps/CLOCKS_PER_SEC ;
}


void Tri_insertion(int * T, int taille, double& x2)
{
	clock_t temps ;
	if(taille > 0) 
	{
		Tri_insertion(T, taille-1, x2) ;
		int k = taille ;
		while((k > 0) && (T[k-1] > T[k]))
		{
			swap(T[k-1], T[k]);
			k-- ;
		}
	}
	temps = clock() ;
	x2 = (double)temps/CLOCKS_PER_SEC ;
}

void Tri_fusion(int * t, int n, double& x3)
{ 
	clock_t temps ;
	int tmp = 0 ; 

	/* le tri de la premiere partie du tableau*/
	for(int i = 0 ; i < (n-1)/2 ; i++)
  	{
  		for(int j= (i+1) ; j <= (n-1)/2 ; j++)
     	{
     		if(t[i] >= t[j])
       		{
       			swap(t[i],t[j]) ;
       		}    
     	}
  	}
  
	/*le tri d la deuxieme partie du tableau*/
 	for(int i = ((n-1)/2)+1 ; i < n-1 ; i++)
  	{
  		for(int j = (i+1) ; j < n; j++)
	    {
	    	if(t[i] >= t[j])
     		{ 
     			swap(t[i],t[j]) ;  
     		}
    	}
  	}

	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = n-1 ; j > i ; j--)
		{
			if(t[j] < t[j-1])
			{
				swap(t[j-1], t[j]);							//Permet de faire comme les lignes précédentes
			}
		}
	}

	temps = clock() ;
	x3 = (double)temps/CLOCKS_PER_SEC ;
}

int rapide(int* T,int deb,int fin)
{
	int k = T[deb];
	int i = deb+1;
	int j = fin;
	
	while (i <= j)
	{
		while (T[i] <= k)
		{
			i++;
		}
		while (T[j] > k)
		{		
			j--;
		}
		if (i < j)
		{
			swap(T[i++],T[j--]);
		}	
	}

	if (T[j] < T[deb])
	{
		swap(T[deb],T[j]);
	}

	return j ;
}

void Tri_rapide(int * T, int deb, int fin, double& x4)
{
	clock_t temps ;
	int tmp;
	if (deb < fin) {
		tmp= rapide(T,deb,fin);
		Tri_rapide(T,deb,tmp-1,x4);
		Tri_rapide(T,tmp+1,fin,x4);
	}
	temps = clock() ;
	x4 = (double)temps/CLOCKS_PER_SEC ;
}

void tamiser(int * T, int i, int taille)
{
	int k = i ;
	int j = 2*k ;

	while(j < taille)
	{
		if(j < taille && T[j] < T[j+1])
		{
			j += 1 ;
		}

		if(T[k] < T[j])
		{
			swap(T[k], T[j]) ;
			k = j ;
			j = 2*k ;
		}
		else
		{
			j = taille + 1 ;
		}
	}
}

void Tri_tas(int * T, int taille, double& x5)
{
	clock_t temps ;
	for(int i = taille/2 ; i > 0 ; i--)
	{
		tamiser(T,i,taille) ;
	}

	for(int i = taille ; i > 0 ; i--)
	{
		swap(T[i],T[0]) ;
		tamiser(T,0,i-1) ;
	}

	temps = clock() ;
	x5 = (double)temps/CLOCKS_PER_SEC ;
}