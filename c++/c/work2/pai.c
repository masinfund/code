#include <stdio.h>

int main(void)
{

	int i , s  ;

	double sum , n , d ,eps , pai ;

	sum = n = d = 1.0 ;

	i = s =  1 ;

	eps = n / d ;

	do {

		i += 2 ;

		d *= i ;

		eps = n / d ;

		sum += n / d ;

		s++ ;

		n *= s ;

	} while ( eps >= 0.00005 ) ;

	pai = sum * 2 ;

	printf("%f\n",pai) ;


	return 0 ;

}