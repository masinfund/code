#include <stdio.h>
#include <math.h>


unsigned int reverse_bit(unsigned int value ) ;


int main()
{

// 打印数字的二进制位	
	unsigned int x = 1 ;
	x = reverse_bit(x) ;
	for(int i = 1 ;i <= 32 ; ++i){
		if(x & 1)
			printf("1") ;
		else
			printf("0") ;
		x >>= 1 ;
		if(i % 4 == 0)
			printf(" ") ;
	}

	return 0 ;

}

unsigned int reverse_bit(unsigned int value )
{
	unsigned sum = 0 ;
	int bit = 0 ;
	for(int i = 0 ; i <= 31 ; ++i){
		bit = value & 1 ;
		sum += bit * pow(2 , (31 - i)) ;
		value >>= 1 ;
	}
	return sum ;
/*

	unsigned ans = 0 ; 
	for(int i = 1 ; i != 0 ; i <<= 1){
		ans <<= 1 ;
		if(value & 1){
			ans |= 1 ;
		}
		value >>= 1 ;
	}
	return ans ;


*/


}