#include <stdio.h>

void pb( int n ) 

{

	if ( n != 0 ) {

		pb( n / 2 ) ;

		putchar('0' + n % 2 ) ;

	// '0' -- '9' Ascii code  48 -- 57 

	// '0' + 1 % 2 = 48 + 1 = 49 = '1'
	}
	
}

int main(void)

{
	int n ; 
	putchar('0' + '1' );

	scanf("%d",&n) ;

	pb(n);


	return 0 ;

}
