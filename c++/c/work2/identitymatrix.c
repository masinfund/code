#include <stdio.h>
#define N 10 

int main(void) 
{

	double ident[N][N] ;

	int row , col , m[5][9] ;

	/*  使用指针运算初始化identity matrix
	int *p , a[N][N] = {0} ;

	for( p = a[0] ; p <= a[N - 1] + N - 1 ; p += N + 1 )
		*p = 1 ;

	for( p = a[0] ; p <= a[N - 1] + N - 1; p++ ){

		printf("%d ",*p) ;

		if ( ( p - a[0] + 1) % N == 0 )
			printf("\n") ;
	}

	*/
	for ( row = 0 ; row < N ; row++) {

		for ( col = 0 ; col < N ; col++)  {

			if ( row == col ) 

				ident[row][col] = 1.0 ;
			
			else 

				ident[row][col] = 0.0 ;

		}

	}
	   
	return 0 ;

}