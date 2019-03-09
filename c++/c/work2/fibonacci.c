#include <stdio.h>

int main(void)

{

	int a[8][8] =

	{

		{ 'r','n','b','q','k','b','n','r'},

		{ 'p','p','p','p','p','p','p','p'},

		{ ' ','.',' ','.',' ','.',' ','.'},

		{ '.',' ','.',' ','.',' ','.',' '},

		{0},

		{0},

		{'P'},

		{'R','N','B','Q','K','B','N','R'} 

	} ,

	 fib_number[40] , i ,j ;

	fib_number[0] = 0 ;

	fib_number[1] = 1 ;


	for ( i = 2 ;  i < 40 ; i++ ){

		fib_number[i] = fib_number[i - 1] + fib_number[i - 2] ;

	}
	
	for ( i = 0 ; i < 40 ; i++ ) {


		printf("%7d\n",fib_number[i] ) ;

	}





	for ( i =0 ; i < 8 ; i++ ) {

		for ( j = 0 ; j < 8 ; j++){

			printf("%c",a[i][j] ) ;


		}

		printf("\n") ;


	}
	return 0 ;

}