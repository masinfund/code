#include <stdio.h>
#define MAXLINE 10

int Mygetline( char line[] , int lim) ;
void copy( char to[] ,char from[] ) ;

int main(void)

{
	int i = 1 , len ;
	char line[MAXLINE] = {0} ;

	while( line[i - 1] != '\n' ) {
		len = Mygetline(line,MAXLINE) ; 
		// need to wait for the signal(ctrl + z ) to stop 
		
        for( i = 0 ; i < len ; i++)
			printf("%c",line[i] ) ;
	}

	return 0 ;
}

int Mygetline( char *s , int lim ) 
{
	int c , i ;

	for ( i = 0 ; i < lim  && ( c = getchar() ) != EOF  ; ++i) 		
		s[i] = c ;

	return i ;
}
void copy ( char to[] , char from [] )
{
	int i = 0 ;

	while ( (to [i] = from[i] ) != '\0' ) 
		++i ;
}