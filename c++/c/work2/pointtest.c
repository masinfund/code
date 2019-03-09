#include <stdio.h>


int *f(int *, int *) ;

int main(void)

{
	int i = 3 , j = 5 , *p = &i , *q = &j ;
	int *r ;
	printf("%p,%p\n",&p,&q) ;
	r = f(p,q) ;
	printf("%d,%d,%d,%d,%d\n",i,j,*p,*q,*r) ;
	printf("%p,%p,%p,%p,%p",&i,&j,p,q,r);
	return 0;
}

int *f( int *s , int *t)
{

	int *k ;
	printf("%p,%p\n",&s,&t) ;

	if ( *s < *t){
		k = s;
		s = t ;
		t = k ;
	}
	printf("%p,%p,%p\n",k,s,t);

	return s ;
}
/*  指针是指内存地址，指针变量是存储内存地址的。
	形参中声明的指针，在调用时，系统为其分配内存地址，
	传递的实参是main函数中的指针变量存储的值。
	c中形参的传递是值传递的，无论是指针还是其他类
	型的值，都是传递拷贝的值。指针形参也是传递指针变量中的值。
*/