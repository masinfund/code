#include <stdio.h>
#define N 75

int main(void)
{	
/*
ex :  in :Hello , This my world.   out : world my Thil , Hello.

*/


	char a[N] , ch ;
	int i , end ,k ,ind , j ;


	for( i = 0 ; i < N ; i++){
		scanf("%c",&a[i] ) ;
		if( a[i] == '!' || a[i] == '?' || a[i] == '.' ){
			 end = i ;
			 ch = a[i] ;
			break ;
		}
	
	}
	while( end != 0 ){
		for( k = end - 1 ; k >=  0 ; k--){
			if( a[k - 1] == ' ' ){
				ind = k ;
				j  = end ;
				end = k - 1;
				break ;
			}
		}

		if (k == -1 ){
			ind = 0 ;
			j = end ;
			end = 0 ;
		}

		for( k = ind ; k < j ; k++){
			printf("%c",a[k] ) ;
		}
		printf(" ") ;

	}

	printf("\b%c",ch) ;

	return 0 ;
}