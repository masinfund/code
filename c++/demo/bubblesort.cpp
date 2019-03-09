#include <iostream>
#include <ctime>
using namespace std ;
void BubbleSort(int *a , int n)
{
	for(int i = 0 ; i != n - 1; ++i){
		int flag = 0 ;
		for(int j = 0 ; j != n - i ; ++j){
			int tmp ;
			if(a[j] > a[j + 1]){
				tmp = a[j + 1] ;
				a[j + 1] = a[j] ;
				a[j] = tmp ;
				flag = 1 ;
			}
		}
			if(!flag){
			break ;
		}
	}
}
int main()
{
	int a[100] ;
	srand((unsigned)time(nullptr)) ;
	for(int i = 0 ;i != 100 ; ++i){
		a[i] = rand() % 1000 + 1 ;
	}
	BubbleSort(a,100) ;
	for(int i = 0 ;i != 100 ; ++i){
		cout << a[i] << "  " ;
	}
	cout << endl ;
	return  0 ;
}