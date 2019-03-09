#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
	/*
	char *planets[] = {"Mercury","Venus","Earth",
						"Mars","Jupiter","Saturn",
						"Uranus","Neptune","Pluto"} ;
	int i , j ;

	for ( i = 1 ;  i < argc  ; i++) {

		for( j = 0 ; j < NUM_PLANETS ; j++){

			if ( strcmp(argv[i] , planets[j] ) == 0 ){
				printf("%s is planet %d\n",argv[i],j + 1) ;
				break ;
			}
		}
			if ( j == NUM_PLANETS )
				printf("%s is not a planet\n",argv[i]) ;
	}

	*/
	FILE *fp ;
	if ( argc != 2 ){
		printf("usage:canopen filename \n") ;
		exit (EXIT_FAILURE) ;
	}
	if (( fp = fopen(argv[1],"r"))  == NULL ) {
		printf("%s can't be opened \n",argv[1] ) ;
		exit (EXIT_FAILURE) ;
	}
	printf("%s can be opened \n",argv[1] ) ;
	printf("%s",argv[0]) ; // D:\code\c\work2\a.exe
	fclose(fp) ;
	
	return 0;
}