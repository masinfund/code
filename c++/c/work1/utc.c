#include <stdio.h>
int main(void)
{

	int  number ;

	
	scanf("%d",&number);

	if (number <=2359 && number >= 0){
		if (number % 100 >= 60) 	;

		else {

			if ( number / 100 >= 8)			printf("%d",number - 800);

			else 							printf("%d",number + 1600);
		}
	}
	
	else  ;
	
		
	return 0 ;

}
