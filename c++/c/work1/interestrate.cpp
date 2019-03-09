#include <stdio.h> 
#define NUM_RATES ((int) (sizeof(value) / sizeof(value [0]))) 
#define INITIAL_BANLANCE 100.00
#define N 50

int main(void) 

{
	int i , max_rate , num_years ,rate  ;

	double value[N] ;


	printf("Enter interest rate :") ;
	
	scanf("%d",&max_rate) ;
	
	printf("Enter number of years :") ;
	
	scanf("%d",&num_years) ;


	printf("\nrate(unit : %%)") ;

	for (i= 0 ; i < num_years ; i++ ) {

		printf("%7d", i + 1 ); 
		
		value[i] = INITIAL_BANLANCE ;

	}

	printf("\n") ;

	for ( rate = 5; rate <= max_rate ; rate++ ) {

		printf("%d             ",rate) ;

		for ( i = 0 ; i < num_years ; i++) {

			value[i] += value[i] * rate / 100.00f ; 

			printf("%7.1f",value[i]) ;
			
		}

		printf("\n") ;

	}
	return 0 ;

}
