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

		scanf("%s",ch) ; //����ֱ����ָ���ж����ַ�������Ϊû��Ϊָ������㹻���ڴ档

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