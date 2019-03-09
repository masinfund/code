#include <stdio.h>
int gcd( int m , int n) ;
int gcd1( int m , int n) ;

int main(void)
{

	int  m , n   ; 

	printf("Enter two integers:" ) ;

	scanf("%d%d",&m,&n);

	printf("%d",gcd(m,n) ) ;

	printf("\n%d",gcd1(m,n)) ;


	return 0 ;

}
/*
若x,y均为偶数，f(x,y) = 2 * f(x/2,y/2);
若只x均为偶数，f(x,y) = f(x/2,y);
若只y均为偶数，f(x,y) =  f(x,y/2);
若x,y均为奇数，f(x,y) = f(y, x- y);(两个奇数相减，必得偶数)

public static int gcd(int x, int y) {
		if (x < y) {
			return gcd(y, x);
		}

		if (y == 0) {
			return x;
		} else {
			if (isEven(x)) {
				if (isEven(y)) {
					return (gcd(x >> 1, y >> 1) << 1);
				} else {
					return gcd(x >> 1, y);
				}
			} else {
				if (isEven(y)) {
					return gcd(x, y >> 1);
				} else {
					return gcd(y, x - y);
				}
			}
		}
	}

	// 判断一个数是否为偶数
	public static boolean isEven(int x) {
		// 只需要让这个数与1相与即可，因为任何一个数，只要是偶数，那这个数的二进制的第一位，必定是0
		if ((x & 1) == 0) {
			return true;
		} else {
			return false;
		}
	}
	*/

// 辗转相除法 

int  gcd( int m , int n )
{
	int r ;

	r = m % n ;
	m = n ;
	n = r;
	if( r == 0 )
		return m ;
	else
		return gcd(m,n);

}

//整数检测法 


int gcd1( int m , int n) 
{
	int i ,ans ;

	if ( m < n ) 

		gcd1(n,m) ;

	for( i = 1 ; i <= n ; i++ ) {
	
		if ( n % i == 0 && m % i == 0 )

			ans = i ;
		
	}

	return ans ;
}