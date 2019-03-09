#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp ;
	if((fp = fopen("test.c","r")) == NULL){
		fprintf(stderr,"Can't open class file\n") ;
		exit(EXIT_FAILURE) ;
	}
	char ch ;
	while((ch = fgetc(fp)) != EOF){
		putchar(ch) ;
	}
	fclose(fp) ;
	fp = NULL ;

	return  0  ;
	
}
