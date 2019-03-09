#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define N 10 

int main(void)
{
	int number ,revnumber,n1,n2,n3 ;

	
	scanf("%1d%1d%1d",&n1,&n2,&n3);


	revnumber = n1 * 1 + n2 * 10 + n3 * 100 ;
	
	printf("%d\n",revnumber );


	printf("Enter a number between 0 and 32767 ;");

	scanf("%i",&number);
	printf(" In octal ,your number is : %i\n",number);


	
	int a[N] , i ;

	printf("Enter %d numbers :",N) ;

	for ( i = 0 ; i < N ; i++ ) {

		scanf("%d",&a[i])  ;

	}

	printf("In reverse order:") ;

	for ( i = N - 1 ; i >= 0 ; i--) {

		printf(" %d",a[i]) ;

	}
	printf("\n") ;
	
	return 0 ;

}
