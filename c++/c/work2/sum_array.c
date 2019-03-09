#include <stdio.h>
#define N 10 
#define TRUE 1
#define FALSE 0

typedef int Bool ;

Bool search(const int *a , int n , int key );

int sum_array(const int *a , int n ) ;

int find_largest(int *a , int n );

void find_two_largest( const int *a , int n , int *largest , int *second_largest);


int main(void)
{
	int ident[N][N] ;

	int *p , i ;

	int row , col ;

	for ( row = 0 ; row < N ; row++ )

		for ( col = 0 ; col < N ; col++ ){

			if ( row == col )

				ident[row][col] = 1 ;
			
			else

				ident[row][col] = 0 ;
		}

		for( p = &ident[0][0] , i = 0 ; p <= &ident[N -1][N - 1]  ; p++ ){
			
			if( *p != 1)

				i++ ;

			if( i % 10 == 0 && i != 0 )

				*( p + 1) = 2 ; // 反映了能对单位矩阵进行操作
		}


	printf("%d\n",ident[1][1]);
		


	return 0 ;

}

int sum_array(const int *a , int n )

{
	int *p , sum ;

	for( p = a ; p < a + n  ; p++  )

		sum += *p ;
	
	return  0 ;

}

Bool search( const int *a, int n , int key )

{	
	int *p ;

	for ( p = a ; p < a + n ; p++ ){

		if ( *p == key )

			return TRUE ;

		else 

			return FALSE ;

	}

}

int find_largest(int *a , int n ) 

{
	int *p , max ;

	for ( p = a , max = *p ; p < a + n ; p++ )

		if ( *p > max )

			max = *p ;

		return max ;

}

void find_two_largest(const int *a , int n , int *largest , int *second_largest)

{

	int *p ;

	for ( p = a ,largest = a ; p < a + n ; p++ )

		if ( *p > *largest )

			*largest = *p ;

	for ( p = a ,second_largest = a ; p < a + n ; p++ )

		if ( *p > *second_largest && *p != *largest )

			*second_largest = *p ;

}
