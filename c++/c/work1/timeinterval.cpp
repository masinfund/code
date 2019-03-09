#include <stdio.h>
int main()
{
	int h1 , m1 ;
	int h2 , m2 ;

	scanf ("%d %d ",&h1,&m1);
	scanf("%d %d ",&h2,&m2) ;
	int ih = h2 - h1 ;
	int im = m2 - m1 ;
	if (im < 0 )
	{
		im = 60 + im ;
		ih--;

	}

	printf("The time interval is %d : %d  ",ih,im );


	return 0 ;

}