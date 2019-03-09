#include <stdio.h>
int main(void)
{
	int ch , flag = 0 ;
	/*
		while ( (ch = getchar() ) != EOF ){
	
			if ( ch == ' ' ){
	
				putchar(ch) ;

				while( (ch = getchar() ) == ' ' )
					;
				putchar(ch) ;

			}
			else
				putchar(ch) ;

		}

	*/
	while( (ch = getchar() ) != EOF){

		if ( ch == ' ' ) {

			if ( flag == 0)
			{

				flag = 1 ;
				putchar(ch);

			}
		}

		else{

			flag = 0 ;
			putchar(ch) ;

		}

		
	}
	return 0 ;
}