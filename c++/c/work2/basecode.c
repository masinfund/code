#include <stdio.h>
int main(void)
{
	//narcissus

	int num, i ,j  ,x , max  ;

	int ptr[10][10] ;


	int a[10] = { 32, 45 , 62 , 10 , 55, 30 , 70 , 83 , 56, 7} ;

	printf("Please enter a number : ") ;

	scanf("%d",&num) ;

	i = num % 10  ;

	j = num / 10 % 10  ;

	x = num / 100  ;

	if ( num == i * i * i  +  j * j * j +  x * x * x) 

		printf("%d is narcissus\n",num) ;

	//matrix

	for ( i = 1 ; i <= 5 ; i++) {

		for ( j = 1 ; j <= 5 ; j++ ){

			printf("%4d", i * j ) ;
		}

		printf("\n") ;
	}
		
	//
	printf("Enter two number :") ;

	scanf("%d%d",&i,&j) ;

	max = i * j ;

	while( (x = i % j ) != 0 ){

	i = j ;

	j = x ;

}

	printf("gcd = %d\nlcm = %d \n", j , max / j ) ;


//bubble sort
	for ( i = 1 ; i < 10 ; i++ ){

		for ( j = 0 ; j < 10 - i ; j++ )

			if ( a[j] > a[j + 1] ){

				max = a[j] ;

				a[j] = a[j + 1] ;

				a[j + 1] = max ;
			}

	}

	for ( i = 0 ; i < 10 ; i++)

		printf("%4d",a[i] ) ;

// selection

	printf("\n\n");

	for ( j = 0 ; j <= 9 ; j++ ){

		max = a[j] ;

		num = j ;

		for ( i = j + 1 ; i < 10 ; i++ ){

			if ( a[i] > max ){

				max = a[i] ;

				num = i ;

			}

		}

		a[num] = a[j] ;

		a[j] = max ;

	}

	for ( j = 0 ; j < 10 ; j++)

		printf("%4d",a[j] ) ;

	printf("\n\n");
// insertsort
void insertSort(int *arr , int num) 
{
    int i , j, tm ;
    for(i = 1 ; i != num  ; ++i){
        tm = arr[i] ;
        j = i - 1 ;
       while(j >= 0 && tm <= arr[j]){
        arr[j + 1] = arr[j] ;
        --j;
       }
       arr[j + 1] = tm ;
    }
}

//seek

	printf("enter the value you seek :");

	scanf("%d",&num) ;

	i = 0 ;

	j = 9 ;

	while ( a[ x = ( i + j ) / 2 ] !=  num ){

		if ( num > a[x] ) 

			j = x - 1 ;

		else 

			i = x + 1 ;

		if ( i > j ){ 

			printf("not find .\n") ;

			break ;
		}

	}

	if ( i <=  j ) 

		printf("place the serial number %d , seek value %d\n",x,a[x] ) ;

	// binormal array 

	ptr[0][0] = 1 ;

	ptr[1][0] = ptr[1][1] = 1 ;

	for ( i = 2 ; i < 10 ; i++){

		ptr[i][0] = ptr[ i][i] = 1 ;

		for ( j = 1 ; j <= i - 1 ; j++ )

			ptr[i][j] = ptr[i - 1][j - 1] + ptr[ i - 1][ j ] ;
	
	}

	for ( i = 0 ; i < 10 ; i++){

		for ( j = 0 ; j <=  i ; j++ )

			printf("%  6d",ptr[i][j] ) ;

		printf("\n") ;


	}

	return 0 ;
}
