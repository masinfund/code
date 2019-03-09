#include <iostream>

using namespace std ;




bool symm(unsigned n) {
 // 判断回文数
	unsigned i = n ; 
	unsigned m = 0 ; 
	while(i > 0) {
		m = m * 10 + i % 10 ;
		i /= 10 ;
	}
	return m == n ;
}


long long hanoi(int n , char src , char medium , char dest)
{
	static long long cnt = 0 ;
	cnt++ ;
	if( n == 1)
		cout << src << " --> " << dest << endl ;
	else {
		hanoi(n - 1 , src , dest , medium) ;
		cout << src << " --> " << dest << endl ;
		hanoi(n - 1,medium ,src , dest) ;
	}
	return cnt ;
}


int main()
{





	return 0 ;
}