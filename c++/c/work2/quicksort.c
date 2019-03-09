#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 17
#define MOD 100
void quicksort(int a[] , int low , int high  );
int split(int a[] ,int low , int high) ;
//static int a[N] ;

int main()
{
	int a[N] ;
 	srand((unsigned)time(NULL)) ;
    for(int i = 0 ; i != N ; i++){
        a[i] = rand() % MOD + 1 ;
        printf("%d  ",a[i]) ;
    }
    puts("") ;

    quicksort(a, 0 , N - 1 ) ;
    for(int i = 0 ; i != N ; ++i){
        printf("%d  ",a[i]) ;
    }
    puts("") ;
    char *ts[10] = {'\0'} ;
    for(int i = 0 ; i != 10 ; ++i){
    	printf(" %c ",ts[i]) ;
    }
	return 0 ;
}

void quicksort( int *a , int low , int high )
{
	int pivot;
	
	if ( low >= high )
	
	// > 是因为最终总是1个元素的排序
	
		return ;
	
	pivot= split(a,low,high);

	quicksort(a,low,pivot - 1);
	
	// low and high point to the same element ,low > middle(high) - 1
	
	quicksort(a,pivot+ 1 , high) ;

}

int split(int a[] , int low , int high)
{
	int part_element = a[low] ;
	// 此一步，相当于空出了low位,以part_element为标尺。
	for( ; ; ){
		while( low < high && part_element <= a[high] )
			high-- ;
		if (low == high )  // >=
			break ;
		a[low++] = a[high] ;
		while( low < high && part_element >= a[low] )
			low++ ;
		if ( low == high )
			break ;
		a[high--] = a[low] ;

	}
	a[high] = part_element ;
	return high ;
}
/*
    while ( low < high ) {

		while ( low < high && x <= a[high] ) 

			high-- ;

		if ( low < high ) 
			
			a[low++] = a[high] ;

		while ( low < high && a[low] <= x  )

			low++ ;
		
		if ( low < high ) 
			
			a[high--] = a[low] ;
	}     


select sort 
	int i , mediant , j  , a[N] ;
	for( i = 0 ; i < N - 1 ; i++){

		for( j = i + 1 ; j < N ; j++ ){

			if (a[i] >= a[j]){

				mediant = a[i] ;
				a[i] = a[j] ;
				a[j] = mediant ;
			}
		}
	}
}

bubbling sort

int i , j  , mediant ;
	bool flag ;
	for( i = 0 ; i < N - 1; i++){
		
		flag = true ;
		
		for( j = 0 ; j < N - 1 - i ; j++){

			if( a[j] > a[j + 1] ){
				mediant = a[j] ;
				a[j] = a[j + 1] ;
				a[j + 1] = mediant ;
				flag = false;
			}
		}

		if( flag )	break ;
	}
void InsertSort(int *a , int n) 
{
    int idx , tmp ;
    for(int i = 1 ; i != n ; ++i){
        tmp = a[i] ;
        idx = i - 1 ;
        while(idx >= 0 && a[idx] > tmp){
            a[idx + 1] = a[idx] ;
            idx-- ;
        }
        a[idx + 1] = tmp ;
    }
}
*/
