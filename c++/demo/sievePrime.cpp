#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <typeinfo>


#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1 << 30)

using namespace std;



void sievePrime(int n)
{
	// 筛法求素数
	int *arr = new int[n + 1]();
	for(int i = 2 ;i <= n ; ++i)
		if(!arr[i])
			for(int j = 2 * i ; j <= n ; j += i)
				arr[j] = 1 ;

	for(int i = 2 ; i <= n ; ++i)
		if(!arr[i])
			cout << i << '\t' ;
	cout << endl ;

		

	delete []arr ;
}

void debugPara(const int *a , size_t size)
{
	#ifndef NDEBUG 
	cerr << __func__ << ": array size is " 
		 << size << endl ;
	cerr << __FILE__ << '\n'
		 << __LINE__ << '\n'
		 << __TIME__ << '\n' 
		 << __DATE__ << endl ;
	#endif 

}





int main(int argc, char const *argv[])
{



    return 0;
}
