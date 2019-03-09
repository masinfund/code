#include "stdafx.h"
const int N = 5 ;

void MatrixTranspose(int (*a)[N] , int (*b)[N] , int row)
{
	for(int i = 0 ; i != row ; ++i){
		for(int j = 0 ; j != N ; ++j){
			b[i][j] = a[j][i] ;
		}
	}
	
}

int sum_from_to(int first , int last)
{	int sum = 0 ;
	for(int i = first ; i <= last ; ++i)
		sum += i ;
	return sum ;
}

class decFactor{
private:
	int n ;
public:
	decFactor(int x) : n(x) { }
	void solve(vector<int> &v){
		for(int i = 1 ; i <= n ; ++i){
			if(n % i == 0)
				v.push_back(i) ;
		}
	
	}


};

void foo()
{
	while(1){
		int n ; 
		char ch ;
		string badStr ;
		while(1){
			cout << "请输入一个正整数 : " ;
			cin >> n ;
			cout << '\n' ;
			if(cin.fail()){
				cin.clear() ;
				cin >> badStr ;
				cout << badStr << "不是一个正整数" << endl;
				cin.sync() ;
			}
			else if(n <= 0){
				cout << n << " 不是一个正整数."  << endl;
			}
			else {
				cout << "你想尝试另一个整数吗(y / n) ? " ;
				cin >> ch ;
				if(ch == 'n' || ch == 'N')
					break ;
			}
		}
		
		vector<int> v ;
		decFactor f(n) ;
		
		f.solve(v) ;
		for(auto it = v.rbegin() ; it != v.rend() ; ++it){
			cout << *it << endl;
		}

		while(1){
			cout << "你想看另一个整数吗(Y / N ) ? " ;
			cin >> ch ;

			if(ch == 'n' || ch == 'N' || ch == 'Y' || ch == 'y'){
				break ;
			} 
			else {
				cout << "请以Y(或y) 回答是 ， N (或n) 回答为否。" << endl;
			}
		}
		if(ch == 'n' || ch == 'N')
			break ;
	}	
}

class A {
	string s ;
	A(const A& x) : s(x.s) { cout << "copy" << endl;}
public:
	A(const char *x) : s(x) { cout << "constructor" << endl ;}
	virtual ~A(){} ;
};


int main()
{
	A st("def") ;

	A st2 = st ;
	cout << typeid(st2).name() << endl;


	int arr[N][N] = {1 , 3 , 12 , 10 , 1 ,
					 2 , 4 , 24 , 2 , 29 ,
					 3 , 5,  31 , 37 , 3 ,
					 4 , 5 , 4 , 19 , 39 ,
					 5 , 7 , 5 , 9 , 54 } ;
	int Ta[N][N] ;
	int (*pa)[N] = arr ;
	cout << (*pa + 3)[2] << endl ;
	for(int i = 0 ;i < N ; ++i)
		cout << (*pa + i)[0] << endl;
	for(int i = 0 ; i != N ; ++i){
		for(int j = 0 ; j != N ; ++j){
			cout << setw(2) << arr[i][j] << " " ;
				/*code*/
		}
		cout << endl;
	}
	MatrixTranspose(arr, Ta , N) ;
	for(int i = 0 ; i != N ; ++i){
		for(int j = 0 ; j != N ; ++j){
			cout << setw(2) << Ta[i][j] << " " ;
				/*code*/
		}
		cout << endl;
	}
	cout << sum_from_to(4,7) << endl;
	//foo() ;

	return 0 ;
}