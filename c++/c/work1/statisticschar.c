#include <stdio.h>


/* ͳ�������ַ������֡��հ׷��Լ������ַ�*/

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
