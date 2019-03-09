/* UPC  Universal Product Code   
numeral  0 13800 15173 5 
(大部分商品用0 或 7 表示， 2 表示需要称量的商品，3表示药品或与健康相关的商品，而5表示赠品）。
13800 用来标识生产商
15173 标识产品
5   “校验位”，帮助识别前面数字中的错误。
Computes a Universal Product Code check digit
x = 0 + 3 + 0 + 1 + 1 + 3 ;
	y = 9 - ( x * 3 + 1 + 8 + 0 + 5 + 7 -1 ) % 10 ;

*/
#include<stdio.h>
int main(void)
{
	int d ,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,first_sum ,second_sum,total;

	printf("Enter the first (single) digit: ");
	scanf("%1d",&d);   //使之匹配一位整数

	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5);

	printf("Enter second group of five digits : ");
	scanf("%1d%1d%1d%1d%1d",&j1,&j2,&j3,&j4,&j5);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4 ;

	total = 3 * first_sum + second_sum ;

	printf("Check digit : %d\n",9 - (( total - 1 ) % 10 )) ;


	

	return 0 ;

}