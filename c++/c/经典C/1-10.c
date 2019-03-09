#include <stdio.h>

#define ESC_CHAR '\\'

int main(void)
{
	int ch  ;
	while((ch = getchar() ) != EOF){
		switch(ch) {
			case '\b' :
				putchar(ESC_CHAR) ;
				putchar('b') ;
				break ;
			case '\t' :
				putchar(ESC_CHAR);
				putchar('t') ;
				break ;
			case ESC_CHAR :
				putchar(ESC_CHAR) ;
				putchar(ESC_CHAR) ;
				break ;
			default :
				putchar(ch) ;
				break ;

		}
	}

	
	return 0 ; 

}