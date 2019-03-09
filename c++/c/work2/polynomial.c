#include <stdio.h>

int main(void) 
{
// count a0 + a1 * x + a2 * x^2 + ... + an * x ^ n ;
	
	double x , sum ;
	int n , i ;

	scanf("%lf%d",&x,&n) ;

	int a[n]  ;

	for( i = 0 ; i < n ; i++)
		scanf("%d",&a[i] ) ;

	sum = a[n - 1] ;

	for( i = n - 1 ; i > 0 ; i--)
		sum = x * sum + a[i - 1] ;

	printf("%.2f",sum) ;

	return 0 ;
	
}
