#include <stdio.h>
#include <sdlib.h>


int my_atoi(const char *str)
{
	int i = 0 , flag = 1 ;
	if(!str){
		return 0 ;
	}
}



int main(int argc, char const *argv[])
{
	FILE *source_fp , *dest_fp ;
	int ch ;

	if(argc != 3){
		fprintf(stderr,"usage : fcopy source dest\n") ;
		exit(EXIT_FAILURE);
	}
	if((source_fp = fopen(argv[1] ,"rb") == NULL)) {
		fprintf(stderr,"Can't open %s\n",argv[1]) ;
		exit(EXIT_FAILURE) ;
	} 
	if((dest_fp = fopen(argv[2],"wb") ) == NULL){
		fprintf(stderr,"Can't open %s\n",argv[2]) ;
		fclose(source_fp) ;// close file before return 
		exit(EXIT_FAILURE) ;
	}

	while((ch = getc(source_fp)) != EOF){
		fputc(ch,dest_fp) ;
	}
	fclose(source_fp) ;
	fclose(dest_fp) ;

	return 0;
}