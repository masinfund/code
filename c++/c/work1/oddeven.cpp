#include <stdio.h>
int main(void)
{

	int number = 0 , odd = 0 , even = -1 ;

	while(number != -1){
		
		if (number % 2 == 0) 
			even++ ;
		else 
			odd++ ;
		scanf("%d",&number) ;

	}

	printf("%d\n%d\n",odd ,even);
	
	


	return 0 ;
}