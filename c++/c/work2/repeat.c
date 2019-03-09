#include <stdio.h>
#define bool int 
#define TRUE 1
#define FALSE 0
#define N 10 


int main(void) 

{
	bool signal = FALSE ;
	


	int digit ,i ,number[N] ={0} ;

	long n  ; // max n == 2147483647

	printf("Please enter numbers : ") ;

	scanf("%1ld",&n);

	for ( digit = 0 ; digit < N ; digit++ ){

		number[n]++ ;

		if ( number[n] >= 2 )

			signal = TRUE ;

		scanf("%1ld",&n) ;

	}

	if ( signal == FALSE ) 

		printf("No repeated digit .\n") ;

	else

		printf("digit :       ") ;

	for ( i = 0 ; i < N ; i++)

		printf("%d  ",i);

	printf("\nOccurrences:  ") ;

	for( i = 0 ; i < N ; i++ ) {

		printf("%d  ",number[i]) ;

	}

	printf("\n");


	return 0 ;


}
