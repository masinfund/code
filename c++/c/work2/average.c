#include <stdio.h>
#define Bool int 
#define N 17

int main()
{
	Bool flag ;

	int x ,sum ,i ,average ;


	int number[N];

	sum = i = 0 ;


	scanf("%d",&x) ;

	while(x != -1 ){

		number[i] = x ;

		sum += x ;

		scanf("%d",&x) ;

		i++ ;

	}

	average = sum / (i+1) ;
	
	for ( i = 0 ; i < N ; i++) {

		if (number[i] > average ) 

			printf("%d",number[i]) ;

	}

	return 0 ;


}