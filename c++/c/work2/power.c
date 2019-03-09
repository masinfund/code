#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double  power( double  x ,int n);

//�������� �� ����ԭ�� (function prototype ) �붨��һ��

int main(void)
{
	int n ;
	double x ;

	scanf("%lf%d",&x,&n) ;

	printf("%.2f",power(x, n) ) ;

	
	return 0 ;
}

double  power(double  x ,int n)

{
	if ( n == 0 ) 
		return 1 ;

	if ( n % 2 == 0 )
		return  power( x , n / 2)  * power( x , n / 2) ;
	else
		return  x * power( x, n - 1) ;
}