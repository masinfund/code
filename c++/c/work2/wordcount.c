#include <stdio.h>

#define IN  1 
#define OUT 0 
#define N 10


int main(void)
{
	int c , nl , nw ,nc , state ;

	char *word[N] ;
	char ch[N + 1] ;

	for( c = 0 ; c  < N  ; c++){

		scanf("%s",ch) ; //不能直接向指针中读入字符串，因为没有为指针分配足够的内存。

		word[c] = ch ;

	printf("%s\n",word[c]) ;

	}

	state = OUT ;
	nl = nw = nc = 0 ;

	while( (c = getchar() ) != EOF ){

		++nc ;

		if ( c == '\n') 

			++nl ;

		if ( c == ' ' || c == '\n' || c == '\t' )

			state = OUT ;

		else if ( state == OUT ) {

			state = IN ;

			++nw ;
		}

	}

	return 0 ;
}