#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 800
void max_min(int a[] , int n , int *max , int *min);
char * concat(const char* s1, const char * s2) ;
int HelixNum( int n ) ;



int main(int argc , const char **argv) 
{ 
	FILE *fp ;
	if(argc != 2){
		printf("usage: canopen filename \n") ;
		exit(EXIT_FAILURE) ;
	}
	for(int i = 0 ; i != argc ; ++i){
		printf("%s\n",argv[i]) ;
	}
	 printf("Compiled on %s at %s\n",__DATE__ ,__TIME__) ;
	 HelixNum(7) ;

	return 0 ;
}




/***********************************
* printhelix(螺旋)  number         *
*Sample output :                   *
*please enter data rows : 3        *
*1 2 3                             *
*8 9 4                             *
*7 6 5                             *
*15                                *
************************************/

int HelixNum( int n ) 
{
	int **p = NULL ;  // better choice 
	int i,j , k = 1 , row ,column , sum = 0 ;

	p = (int**)malloc(sizeof(int**) *n ) ; // Test whether memory is allocated for Pointers.
	if (!p) {
		printf("Error : malloc failed in printfnum") ;
		return -1 ;
	}

	for ( i = 0 ; i < n ; i++){
		p[i] = (int *) malloc(sizeof(int*) * n ) ;
		/*
		*sizeof(int *) 与 sizeof(int) 分配的都是整型，
		但是前一种需要自己释放内存。
		*/
		if(!p[i]){
			printf("Error :malloc failed in printfnum")  ;
			return -1 ;
		}
	}

	for ( i = 0 , j = 0 ; k <= n * n ; i++,j++){

		for(column = j ; column < n - j ; column++) {
			p[i][column] = k++ ;
		}
		for(row = i + 1; row < n - i ; row++){
			p[row][n - j - 1] = k++ ;
		}
		for(column = n - j - 2 ; column >= j ; column--){
			p[n - i - 1][column] = k++ ;
		}
		for(row = n - i - 2; row > i ; row--){
			p[row][j] = k++ ;
		}
		
	}

	for ( i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			printf("%-6d",p[i][j]) ;
			if(i == j)
				sum += p[i][j] ;
		}
		puts("") ;
	}

	printf("%d\n",sum) ;
	for( i = 0 ; i < n ; i++){
		free(p[i]) ;  // important step
		p[i] = NULL ;  // avoid dangling pointers
	}
	free(p) ;
	p = NULL ;

	return 0 ;
}









char* concat(const char * s1, const char * s2) 
{

	char * result = NULL  ;
	result = (char *) malloc(strlen(s1) + strlen(s2) + 1) ;
	if(!result ){
		printf("Error: malloc failed in cocat \n") ;
		exit(EXIT_FAILURE) ;
	}
	strcpy(result,s1) ;
	strcpy(result,s2) ;
	return result ;








}
void max_min(int a[] , int n , int *max, int *min)
{
	int i ;

	*max = *min = a[0] ;
	for ( i = 0 ; i < n ;i++){

		if(a[i] > *max)
			*max = a[i] ;
		else if (a[i] < *min) 
			*min = a[i] ;
	}
}
