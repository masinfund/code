#include <stdio.h>
#include <stdbool.h>
#define N 40 
//#define SIZE ((int ) (sizeof(a) / sizeof(a[0])))
/*
variable-length array VLA
变长数组没有初始化式，没有静态存储期限。
数组复制 #include <string.h> memcpy(a,b,sizeof(a)) ;
不允许goto语句绕过VLA

数组名指代实体是一种数据结构，即数组；数组名（指针常量）可以转换为指向其实体的指针；
数组名作为形参传递时，退化为普通的指针，可以对其进行自增自减和修改操作。
*/
void arrayTest( int *str ) ;

int main(void)

{
	int  a[N]  , i ;
	for( i = 0 ; i < N ; i++)
		a[i] = i ;
	printf("%lu\n",(unsigned long ) sizeof(a) ) ;
	arrayTest(a) ;
	printf("%d",nullptr) ;


	return 0 ;
}
void arrayTest( int  *str )
{
	printf("%lu",(unsigned long ) sizeof(str) ) ;
	str++ ;
	printf("%d\n",*str) ;

}
