#include <stdio.h>

/*  Calculates a broker's commission*/

int main(void)
{
	float value , commission ;

	value = 1.0 ;

	while ( value != 0 ) {

		printf("Please enter value of trade : ");
		scanf("%f",&value);

		if (value <2500.00f) {

			commission = value * .017f + 30.00f ;

			if (commission <=39.00f) commission = 39.00f ;
		}

		else if ( value < 6250.00f ) 

			commission = 56.00f + value * .0066f ;

		else if ( value < 20000.00f )

			commission = 76.00f + value * .0034f ;

		else if (value < 50000.00f )

			commission = 100.00f + value * .0022f ;

		else if (value < 500000.00f )

			commission = 155.00f + value * .0011f ;

		else 

			commission = 255.00f + value * .0009f ;


		printf("Commission : $ %.2f\n",commission);
	}

	// 条件表达式

	int i = 1, j = 2 ,k ;

	k = (i >= 0 ? i : 0) + j ;

	printf("%d %d %d\n",i,j,k);





	int grade ;


	printf("Please enter value of score : ") ;

	scanf("%d",&grade);

	switch (grade) {

		case 4 : printf("Excellent\n");			break ;

		case 3 : printf("Good \n") ; 			break ;

		case 2 : printf("Average\n") ; 			break ; 

		case 1 : printf("Poor \n") ;  			break ;

		case 0 : printf("Failing\n") ; 			break ;

		default : printf("Illegal grade\n") ;   break ;


	}




	return 0 ;

}
