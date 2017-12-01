#include <iostream>

using namespace std ;

void afficher(int * T, int taille)
{
	for(int i = 0 ; i < taille ; i++)
	{
		cout << T[i] << "	" << endl ;
	}
}

void Tri_bulle(int * T, int taille)
{
	for(int i = 0 ; i < taille-1 ; i++)
	{
		for(int j = taille ; j > i-1 ; j--)
		{
			if(T[j] < T[j-1])
			{
				swap(T[j-1], T[j]);							//Permet de faire comme les lignes précédentes
				/*int tmp = T[j] ;
				T[j]= T[j-1] ;
				T[j-1] = tmp ;*/
			}
		}
	}
}


void Tri_insertion(int * T, int taille)
{
	if(taille > 0) 
	{
		Tri_insertion(T, taille-1) ;
		int k = taille ;
		while((k > 1) && (T[k-1] > T[k]))
		{
			swap(T[k-1], T[k]);
			k-- ;
		}
	}
}

int * Fusion(int * T, int a, int b, int m, int taille)
{
	int * R = new int[taille] ;
	int i = 0 ;
	int j = m+1 ;
	int k = 0 ;

	for(int a = i ; a < j ; a++)
	{
		cout << T[a] << endl ;
	}

	cout << endl ;

	for(int b = j ; b < taille ; b++)
	{
		cout << T[b] << endl ;
	}

	/*while(k <= taille && (i < m || j < taille))
	{
		if(i <= m && T[i] < T[j])
		{
			R[k] = T[i] ;
			i++ ;
		}
		else
		{
				R[k] = T[j] ;
				j++ ;
		}

		k++ ;
	}

	if(i < m)
	{
		while(j <= taille)
		{
			R[k] = T[j] ;
			j++ ;
			k++ ;
		}
	}
	else
	{
		while(i <= m)
		{
			R[k] = T[i] ;
			i++ ;
			k++ ;
		}
	}*/

	return R ;
}

int * Tri_fusion(int * T, int a, int b, int taille)
{
	int * F = new int[taille] ;

	if(a < b)
	{
		int m = (a + b) / 2 ;
		Tri_fusion(T,a,m,taille) ;
		Tri_fusion(T,m+1,b,taille) ;
		F = Fusion(T,a,b,m,taille) ;
	}
	return F ;
}

