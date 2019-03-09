#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 8 
int chess[N] ;
int count = 0 ;

void print() ;
bool valid( int row ) ;
int trial(int row) ;


int main(void)
{
	trial(0) ;

	return 0 ;
}
void print()
{
	for(int i = 0 ; i != N ; ++i){
		for(int j = 0 ; j != N ; ++j){
			if(chess[i] == j)
				printf(" queen ") ;
			else 
				printf(" 0     ") ;
		}
		printf("	<%d , %d>\n",i , chess[i]) ;

	}
	printf("\n\n") ;
}

bool valid(int row)
{
	for(int i = 0 ; i != row ; ++i){
		//if(chess[i] == chess[row] || abs(chess[i] - chess[row]) == abs(i - row)) 
		if(chess[i] == chess[row] || chess[i] - chess[row] == i - row || chess[i] - chess[row] == row - i)
			return false ;
	}
	return true ;
}
int trial(int row )
{
	if(row == N ){
		count++ ;
		print() ;
		return 0 ;
	}
	for(int i = 0 ; i != N ; ++i){
		chess[row] = i ;
		if(valid(row))
			trial(row + 1) ;
	}
}
