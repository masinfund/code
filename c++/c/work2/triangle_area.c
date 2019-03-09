#include <stdio.h>

double triangle_area( double base , double height ) ;


int main(void)
{
	double  b , h  ;
	b = h = 0 ;
	scanf("%lf%lf",&b,&h) ; 
	//忘记加了& ，出现以下错误。
	// warning C4700: local variable 'h' used without having been initialized

	printf("%.2f\n",triangle_area(b,h) ) ;

	return 0 ;

}

double triangle_area( double base , double height ) 

{
	double product ;
	
	product = base * height ;

	return product / 2 ;

}

