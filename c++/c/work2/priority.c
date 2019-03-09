#include <stdio.h>
int main(void) 
{
	int a , b , c , d , e , f ;

	int i , j , k = 1 ;

	double dx ;

	int *p , *q ;

	i = 5 ; 
	j = 2 ;

	p = &i ;

	q = &j ;
	
	p = q ;

	printf("%p\n",p) ;

	printf("%.1f%.1f%.1f%.1f%.1f%.1f",57.,57.0e0,57E0,5.7e+1,.57e+2,570.e-1);

	scanf("%lf",&dx) ;

	printf("%lf",dx) ;

	i = 7 ; j = 8 ; k = 9 ;
	printf("%d%d%d%d",i - 7 && j++ < k ,i,j,k) ;

	printf("%d%d%d\f",i,j,k);

	scanf("%i",&i) ;
	printf("%i",i) ;


	a = b = c = d = e = f = 3 ;


	a *= b + 1 ;
	//priority  左结合1i--右结合2 --i -i 3* 4+ 5=


	printf("%d %d %d %d %d %d \n",a,b,c,d,e,f) ;
	scanf("%d",&d);
	scanf("%d",&e);

	d += e -= f;
	// The right combination

	j = (i = 6 ) + (j = 3 )  ;

	printf("%d %d \n",d,e);
	printf("%d %d %d \n",i, j , k ) ;
	printf("%d %d %d \n",i++ - j++ + --k ,i,j);  
	// undefined behavior
	printf("%d %d \n",i,j ) ;

	printf("%d %d \n",3 * i-- + 2 ,++j * 3 - 2);
	printf("%d %d \n",i,j);



	return  0 ;

}