#include "stdafx.h"

class Myexception : public exception{
	virtual const char* what() const throw() {
		return "MY exception" ;
	}
};


int main()
{



// 大数加法

	int test  , count = 1 ;
	cin >> test ;
	while(test--){
		string a , b ;
		cin >> a >> b ;

		int s1 = a.size() , s2 = b.size() ;
		int max = s1 > s2 ? s1 : s2 ;
		int *arr = new int[max + 1]() , k = 0 ;
		int i , j ;
		for( i = s1 - 1  , j = s2 - 1 ; i >= 0  && j >= 0 ; --j , --i){
			arr[k++] = a[i] + b[j] - 2 * '0' ;
		}
		while(i >= 0){
			arr[k++] = a[i--] - '0' ;
		}
		while(j >= 0){
			arr[k++] = b[j--] - '0' ;
		}
		for(i = 0 ; i < max ; ++i){
			if(arr[i] / 10){
				arr[i + 1] += arr[i] / 10 ;
			}
			arr[i] %= 10 ;
		}

		cout << "Case " << count++ << ":" << endl;
		cout << a << " + " << b << " = " ;
		for( i = max ; i >= 0 ; --i){
			if(arr[i] == 0 && i == max )
				continue ;
			cout << arr[i] ;
		}
		cout << "\n\n" ;
		delete []arr ;
	}
	return 0 ;
}