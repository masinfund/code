#include <stdio.h>
#include <math.h>
#define N 4 
void InsertSort(int *a, int n ) ;
int MathBlackHole(int *a) ;

int main(void)
{
	int num , i , j = 0 ;
	int a[N] ;
	printf("Please enter a four-digit number(can't be repeats ) ") ;
	scanf("%4d",&num) ;
	do{
		for(i = 0 ; i != N ; ++i){
		a[i] = num % 10 ;
		num /= 10 ;
		}
		InsertSort(a,N) ;
		num = MathBlackHole(a) ;
		printf("%d\n",num) ;
		++j ;
		if (num == 6174)
			break ;
	}while(j != 18) ;
	if(j == 8 ){
		printf("Wrong") ;
	}
	else 
		printf("6174") ;

	return 0 ;
}
int MathBlackHole(int *a)
{
	float max = 0 , min = 0 ;
	for(int i = N ; i != 0 ; --i){
		max += a[i - 1] * pow(10 , i - 1) ;
		min += a[N - i] * pow(10,i - 1) ;
	}
	printf("%04g - %04g = ",max , min) ; 
	// g transformation won't show trailing 0 . 
	return max - min ;
}
void InsertSort(int *a, int n )
{
	int tmp , idx ;
	for( int i = 1 ; i != n ; ++i){
		tmp = a[i] ;
		idx = i - 1 ;
		while( idx >= 0 && tmp < a[idx]){
			a[idx + 1] = a[idx] ;
			--idx ;
		}
		a[idx + 1] = tmp ;
	}
}