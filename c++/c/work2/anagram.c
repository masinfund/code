#include <stdio.h>
#include <ctype.h>

#define N 26

int main(void)

{
	int  a[N] = {0} ,ch ;
	int i ;

	printf("Enter first word :");
	while( (ch = getchar()) != '\n' ){
		
		if( isalpha(ch) ){
			ch = tolower(ch) ;// need to assign a value to ch ,
			a[ch - 'a']++ ;
	    }
	}
	
	printf("Enter second word :") ;
	while( (ch = getchar() ) != '\n' ) {

		if ( isalpha(ch) ) {
			ch = tolower(ch) ;
			a[ch - 'a']-- ;
		}
	}

	for( i = 0 ; i < N ; i++){
		if(a[i] != 0)
			break ;
	}

	if ( i == N )
		printf("Yes") ;
	else
		printf("No") ;

	return 0 ;
}
