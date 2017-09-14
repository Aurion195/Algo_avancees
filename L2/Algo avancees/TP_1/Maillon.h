#ifndef DEF_MAILLON_H
#define DEF_MAILLON_H

class maillon
{	
	friend class liste ;
	
	public :
		int val ;
		maillon * pred ;
		maillon * succ ;
		//~maillon() ;
} ;

#endif 