#include <stdio.h>

#define N 80

void encrypt( char a[] , int number , int key) ;

int main()
{	int i = 0 ,key ;
	char a[N] , ch ;
	printf("Enter message to be encrypted :") ;
	
	while((ch = getchar() ) != '\n' ){
		a[i++] = ch ; 
	
	}

	printf("Enter shift amount(1 - 25): ");
	scanf("%d",&key) ;
	
	printf("encrypted message : ") ;

	encrypt(a,i,key) ;

	return 0 ;
}
void encrypt( char a[] , int number , int key) 
{
	for(  int i = 0 ; i < number ; i++ ){

		if(a[i] >= 'a' && a[i] <= 'z')
			printf("%c",((a[i] - 'a') + key ) % 26 + 'a') ;
		else if( a[i] >= 'A' && a[i] <= 'Z' )
			printf("%c",((a[i] - 'A') + key ) % 26 + 'A') ;
		else
			printf("%c",a[i] ) ;	
	}
}

