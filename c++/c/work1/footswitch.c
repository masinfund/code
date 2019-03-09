#include <stdio.h>
int main(void)
{

	printf("please  enter your height size ,such as \"5 7\" show 5 feet and 7 inches\n");
	int foot ;
	int inch ;

	scanf("%d%d",&foot ,&inch);
	printf("your height is %f miles \n",((foot + inch / 12.0 ) * 0.3048) );
	printf("%f\n",10/3*3.0);

	return 0 ;

}