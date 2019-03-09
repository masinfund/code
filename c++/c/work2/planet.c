#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[] )
{	
	int i ,  j ;
	char *planets[] = { "Mercury", //指向字符串的指针的数组，指针数组。
						"Verus", //数组指针 （*p)[x] ;
						"Eart",
						"Mars", 
						"Jupiter",
						"Saturn",
						"Uranus",
						"Neptune",
						"Pluto"} ;
// .\planet Jupiter venus Earth fred 
	for(i = 1 ; i < argc ; i++){
		for(j = 0 ; j < NUM_PLANETS ; j++){
			if( strcmp(argv[i],planets[j]) == 0 ){
				printf("%s is planet %d\n",argv[i],j + 1) ;
				break ;
			}
		}
			if( j == NUM_PLANETS )
				printf("%s is not a planet \n",argv[i]) ;

	}
	return 0 ;
}