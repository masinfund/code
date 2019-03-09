#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10 


int main(void)

{	
	int i , j ,random , _row , _col ,letternum ;

	char a[N][N] ;

	for ( i = 0  ; i < N ;  i++ ){

		for ( j = 0 ; j < N ; j++){

			a[i][j] = '.' ;

		}
	}

	 i = j = 0 ; 

	 a[i][j] = 'A' ;

	srand( (unsigned ) time(NULL) ) ;

	random = rand() % 4 ;

	for ( letternum = 0 ; letternum < 25 ; ){
		
		random = rand() % 4 ;

		switch ( random ){

			case 0 :

				if ( i- 1 > 0 && a[i-1][j] == '.' ) {

					a[i-1][j] = a[i][j] + 1 ;

					i = i - 1 ;

					letternum += 1 ;
				}

				break ;

			case 1 :

				if ( j + 1 < 10 && a[i][j+1] =='.' ) {

					a[i][j+1] = a[i][j] + 1 ;

					j = j + 1 ;

					letternum += 1 ;
				}

				break ;

			case 2 : 

				if ( i + 1 < 10 && a[i + 1][j] == '.' ){

					a[i + 1 ][j] = a[i][j] + 1 ;

					i = i + 1 ;

					letternum += 1 ;
				}

				break ;

			case 3 :

				if ( j -1 > 0 && a[i][j-1] == '.'){

					a[i][j - 1] = a[i][j] + 1 ;

					j = j -1 ;

					letternum += 1 ;

				}

				break ;

		}

		if ( a[i-1][j] != '.' && a[i][j+1] != '.' && a[i+1][j] != '.' && a[i][j-1] != '.')

			break ;

	}

	for ( i = 0 ; i < N ; i++){

		for ( j = 0 ; j < N ; j++)

			printf("%c  ",a[i][j]) ;
		
		printf("\n");
	
	}
	
	// haha 

	return  0 ;

}