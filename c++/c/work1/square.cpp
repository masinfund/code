#include <stdio.h>
int main(void)
{
	
	// 1 、 4 、 9 、16 ...  n ^2 ;

	int i , n ;

	printf("This program prints a table of squares.\n");

	printf("Enter number of entries in table : ");

	scanf("%d ",&n);
	i = 1 ;

	int odd = 3 ,squares = 1;
	do {
		printf("%10d%10d\n",i,squares);
		squares += odd ;
		odd += 2 ;
		++i ;

	
	} while(i <= n);

	// even number squared 

	for ( even = 2 ; even * even < number ; even += 2 ) 
	printf("%d",even * even ) ;

	/*
	for ( ; i < 0 ; )
		printf("T minus %d and counting \n",i--);
	equaivalence
	while (i < 0 )
		printf("T minus %d and counting \n",i--);
	*/
	
	long x , sum ;
	printf("Enter integers (0 to terminate ) :");


	sum = -1 ;  // scanf("%ld",&x) 
	x = 1 ;


	while (x != 0){

		sum += x ;
		scanf("%ld ",&x);

	}

	printf("The sum is : %ld\n",sum);

	return 0;
	
}
