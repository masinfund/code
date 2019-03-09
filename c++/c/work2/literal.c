#include <stdio.h>

#define STR_LEN  10

int count_spaces( const char *s ) ;


char *mestrcat(char *s1 ,const char *s2) ;


int main(void)

{
	int i , len ;

	i = 2 , 3 , 5 ;
	printf("%d\n",i) ;

	len = ( 2,3 ,6) ;

	printf("%d\n",len) ;

	return 0 ;
	
}

int count_spaces ( const char *s ) 
{

	int count = 0 ; 

	while ( *s != '\0' ){

		if ( *s == ' ' )

			count++ ;

		s++ ;

	}

	return count ; 

}


char *mestrcat (char *s1, const char *s2) 
{

	char *p = s1 ;

	/* while ( *p )
		
		p++ ;

	while( *p++ = *s2++ )
		;

		retrun s1;
	*/

	while( *p != '\0')

		p++ ;

	while( *s2 != '\0'){

		*p = *s2 ;

		s2++ ;

		p++ ;


	}

	*p = '\0' ;

	return s1 ;

}