#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 100 

int secret_number ;

void initialize_number_generator(void) ;

void read_guesses(void) ;

int main(void)

{
	char command ;

	printf("Guess the secret number between 1 and %d .\n\n",MAX_NUMBER) ;

	printf("Please press Y (or y ) begin the game :") ;

	scanf("%c",&command);

	while ( command == 'Y' || command == 'y' ){

		initialize_number_generator() ;

		printf("A new number has been chosen .\n") ;

		read_guesses() ;

		printf("Play again ? (Y/N) \n") ;

		scanf(" %c",&command) ;

	}

	return 0 ;

}

void initialize_number_generator(void) 
{
	srand( (unsigned) time(NULL) ) ;

	secret_number = rand() % MAX_NUMBER + 1 ;


}

void read_guesses(void)

{
	int guess , num_guess = 0 ;

	for( ; ; ){

		printf("Enter a guess number :") ;

		num_guess++ ;

		scanf("%d",&guess) ;

		if ( guess == secret_number ) {

			printf("Excellent ! You won in %d guesses!\n\n",num_guess) ;

			return ;
		}

		else if ( guess > secret_number )

			printf("To high , try again .\n") ;

		else 

			printf("To low , try again  . \n") ;

	}


}