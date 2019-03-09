#include <stdio.h>

int find_largest( int a[] , int n ) 


void max_min( int a[] , int n , int *max , int *min ) ;

//主函数

int main(void)
{
	float x = 1.0 ,  number , max = 0 ;

	int a[10] , big , small , i ;

	

	printf("Enter %d numbers :",10 ) ;

	for ( i = 0 ; i < 10 ; i++ ) 

		scanf("%d",&a[i] ) ;

	max_min( a,10, &big , &small ) ;

	printf("Largest : %d \nSmallest : %d\n" , small) ;

	// 未传递big, 显示4199392


	while (x > 0){

		printf("Enter a number :");

		scanf("%f",&number);
		
		x = number ;

		if ( x > max ) 	max = x ;
		
	}
	
	printf("%.2f\n",max) ;
	

	 /* for (x = 1.0 , max = 0 ; x > 0 ;	x = number ) {

	  	printf("Enter a number : ") ;

	  	scanf("%f",&number ) ;

	  	
	  	if ( number > max ) 	max = number ;


	  }
	printf("%.2f",max) ;
	*/
	
	return 0 ;

}

void max_min( int a[] , int n , int *max , int *min ) 

{
	int i ;

	*max = *min = a[0] ;


	for ( i = 1 ; i < n ; i++ ){

		if ( a[i] > *max ) 

			*max = a[i] ;

		else if ( a[i] < *min)

			*min = a[i] ;

	}

}

int find_largest( int a[] , int n ) 

{


	int i , max ;

	max = a[0] ;

	for ( i = 1 ; i < n ; i++) 

		if (a[i] > max )

			max = a[i] ;

	retrun max ;
}
