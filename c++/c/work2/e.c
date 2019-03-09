#include <stdio.h>

int main(void) 
{

	float e , i , fact ;

	int n ;
	
	scanf("%d",&n) ;


	for ( i = 1.0 ,fact = 1.0 , e = 1.0 ; i <= n ; i++) {

		fact *= i  ;

		e += 1.0f / fact ;

	}


	printf("%f",e) ;
	
	printf("%lu",(unsigned long ) sizeof(long)) ;
	

	return 0 ;

}
