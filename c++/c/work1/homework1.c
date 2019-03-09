#include <stdio.h>
#define pi 3.141592f
#define SCALE_FACTOR  (4.0f/3.0f)
#define TWENTY 20 
#define TEN    10 
#define FIVE   5
#define ONE    1

int main(void)
{
	 //1

	float volume , radius ;

	scanf("%f ",&radius ) ;

	volume = radius * pi * SCALE_FACTOR ;

	printf("volume is %f\n",volume ) ;
	
	// 2
	float number ;

	printf("Please enter an amount of dollar : ");

	scanf("%f",&number);
	printf("with tax added : $ %.1f\n",number * 1.05f ) ;

	//3 
	float x , sum ; 
	x = 7.1f ;
	sum = x * (x * (x * (x * (x * 3.0f  +2.0f) - 5.0f )- 1.0f ) + 7.0f) - 6.0f  ; 
	printf("horner rule sum : %.1f\n",sum ) ;
	
	//4 
	int number1 ,number2 , number3 , number4 ,amount ;

	printf("Enter a dollar amount : ") ;
	scanf("%d ",&amount) ;
	
	number1 = amount / TWENTY ;
	number2 =amount % TWENTY / TEN ;
	number3 =amount % TWENTY % TEN /FIVE ;
	number4 =amount % TWENTY % TEN % FIVE / ONE ;


	return 0;
}