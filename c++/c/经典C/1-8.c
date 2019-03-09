#include <stdio.h>
int main(void)
{
	int ch , nl,nw,nc,nb = 0 , nt = 0 , flag = 0 ;

	nl = nw = nc = 0 ;

	while( ( ch = getchar() ) != EOF ){
		++nc ;
		if ( ch == '\n')
			++nl ;
		else if ( ch == ' ' )
			nb++ ;
		else if ( ch == '\t')
			nt++ ;
		else if ( flag == 0 ){

			flag = 1 ;
			nw++ ;
		}

	}
	printf("%d\t%d\t%d\t%d\t%d\n",nl,nw,nc,nb,nt) ;

	return 0 ;
}