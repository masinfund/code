#include <stdio.h>

void decompose( double x  , long *int_part , double *frac_part ) ;

int main(void)

{

	long i  ;

	double x , frac ;

	printf("Enter a float number :") ;

	scanf("%lf",&x ) ;

	decompose( x , &i , &frac ) ;


	printf("floating number %.2f    int_part %ld    frac_part %.2f    \n",x , i , frac ) ;


	return 0 ;

}

void decompose ( double x , long *int_part , double *frac_part )

{

	*int_part = (long) x ;

	*frac_part = x - *int_part ;

}