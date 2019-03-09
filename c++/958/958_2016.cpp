#include <iostream>
#include <Windows.h>

using namespace std ;


int main()
{
	int x = 10 ;
	while(x > 0){
		cout << x << endl;
		x = x - 1 ;
	}
	int n = 5 ;
	while(--n > 0){
		if(n == 2)
			;//	exit(EXIT_SUCCESS);
		cout << n << " " ;
	}
	cout << "End. " ;

	int arr_size = 10 ;
	int *a ;
	a = new int[arr_size] ;
	int i ;
	for(i = 0 ;i < arr_size ; i++)
		*(a + i) = i ;
	for(i = 0 ; i < arr_size ; i++)
		cout << a[i] << " " ;
	delete []a ;

	return 0 ;
}