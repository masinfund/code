#include <stdio.h>
#include <ctype.h>
# define SIZE 100

int main(void)

{
	int ch , m[SIZE] = {0} , i = 0  , amount ;

	printf("Enter message :  ");

	// ctrl + z   回车键  ctrl + z  要不然会读入'\n'

	while( ( ch = getchar() ) != EOF ) {
	
		ch = toupper(ch) ;

		m[i] = ch ;

		i++ ;
	
	}

	amount = i ;

	printf("In B1FF-speak : ") ;

	for ( i = 0 ;  i < amount ; i++ ){
		
		switch( m[i] ){
		
			case 'A' :

				printf("4");

				break ;

			case 'B' :

				printf("8");

				break ;

			case 'E' :

				printf("3") ;

				break ;

			case 'I' :

				printf("1") ;

				break ;

			case 'O' :

				printf("0") ;

				break ;

			case 'S' :

				printf("5") ;

				break ;

			default :

				printf("%c",m[i] ) ;

				break ;
		
		}

	
	}

	printf("!!!!!!!!!!\n") ;


	return 0 ;
}