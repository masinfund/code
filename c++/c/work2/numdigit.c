#include <stdio.h>
#include <string.h>

size_t mestrlen(const char *s);

char *mestrcat( char *s1, const char *s2) ;

int f( char *s , char *t ) 
{
	char *p1, *p2 ;

	for( p1 = s ; *p1 ;p1++){
		for( p2 = t ; *p2 ; p2++)

			if ( *p1 == *p2 ) 
				break ;
		if ( *p2 == '\0' ) 

			break ;
	}

	return p1 - s ;

	
}

int count_space( char *s ) 

{

	int count = 0  ;

/*	for ( i = 0 ; s[i] != '\0' ; i++ )

		if ( s[i] == ' ' )

			count++ ;

		return count ;

	*/
	while( *s != '\0' ){

		if( *s == ' ' )
			count++ ;
		s++ ;
	}
	return count ;


}

int main(void)
{
	int a [10][10] , (*p) [10] , i = 0 ;

	char ch[6] ="abc\0d"  , *px = "def\0d" ;// 字符串变量可以在声明时初始化。
	
	char str[7] ={'a','b','c','\0'} ;
	
	char s[] = "Hsjodi" , *q ;

	printf("%d",f("abcd","babc")) ;
	for( q = s ; *q  ; q++) 
		
		--*q ;

	puts(s) ;

	strcat(str,px) ;
	printf("%s\n", str) ;

	//strnpy(ch,px,sizeof(ch) - 1) ;
	// ch[sizeof(ch) - 1 ] = '\0' ;

	puts(px) ;

	printf("\n%d",ch[4]) ; //字符串可以是"abc\0d\0"
	printf("\n%s\n",ch ) ;//但是printf函数会把ch[3]作为字符串结束标志
	/*
		声明为数组时，可以修改存储在其中的字符。数组
		名作为指针不能改变。
		声明为指针时，不能修改字符串字面量，但是可以
		指向其他字符串。
		修改字符串，要建立字符数组存储字符串，并且使用p
		作为字符串之前，必须把p指向字符数组。或者字符串变量。
		char str[N] , *p ;
		p = str ;
	
	*/
	printf("%d %d",sizeof(ch) ,sizeof("abc\0d")) ;
	printf("\n%c",px[4]) ;


	for ( p = &a[0] ; p < &a[0] + 10  ; p++ )

		(*p)[i] = 3 ;

	for ( p = a ; p < a + 10 ; p++ )

		printf("%2d\n",(*p)[i] ) ;

	printf("%2d\n",**a) ;// 二维数组名，指向指针的指针


	return 0 ;
}

size_t mestrlen(const char *s)
{
	size_t  n = 0 ;

	while ( *s++)
		n++ ;
	/*
	const char *p = s ; 

	while(*s)
		s++;

  return s - p ;

  */
	return n ;

}

char *mestrcat(char *s1,const char *s2)

{
	char *p = s1 ;

	while(*p++ != '\0')
		;

	while( *p++ = *s2++) 
		/*
			while(*s2 != '\0'){
				*p = *s2 ;
				p++ ;
				s2++ ;
			}
		*/
		  ;
	return s1 ;

}