#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 100000


int main(void)
{	
	long  a[N] , i ;
	double start , end , p , duration ;
	for( i = 0 ; i < N ; i++)
		a[i] = i + 1 ;
	p = a[0] ;
	 //p = a[N - 1] ;
	start = clock() ;
	
	for( i = 1 ; i < N ; i++ )
		p += (double) a[i] * pow(1.1 , i ) ;



	//for( i = N - 1; i > 0 ; i--)
	//p = a[i - 1]  + p * 1.1 ;
	
	end = clock() ;

	duration = (end - start) / (double) CLK_TCK ;
	printf("%f",duration ) ;

	return 0 ;
}
