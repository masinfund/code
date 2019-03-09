#include <stdio.h>


/* 统计输入字符中数字、空白符以及其他字符*/

int main(void)
{
	int c , i , nwhite = 0 , nother = 0 , ndigit[10] = {0} ;
	
	while ( (c = getchar()) != EOF ){
	
		if ( c >= '0' && c <= '9')
	
			++ndigit[c-'0'];

	
		else if ( c ==' ' || c=='\n' || c=='\t')
	
			++nwhite;
	
		else 
	
			++nother;
	
	}

	printf("ndigit = ");
	
	for (i = 0 ; i < 10 ; ++i)
	
		printf("  %d",ndigit[i]);
	
	printf(" ,white space = %d ,other = %d \n",nwhite,nother);
	
	return 0 ;
}
