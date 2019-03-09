#include "stdafx.h"


// template class A 

template<class T> class A ;
template<class T> 
ostream& operator<<(ostream& os , const A<T>& a) ;

template <class T>
class A{
public:
	A(T a , T b){
		x = a ;
		y = b ;
	}
	void Show();
	static int k ;


	//template<class T> vs下可通过编译
	friend ostream& operator<< <T>(ostream& os , const A<T>& a) ;

private:
	T x , y ;

};

template<class T>
ostream& operator<<(ostream& os  , const A<T>& a)
{
	os << a.x << " " << a.y ;
	return os ;
}

template<class T>
void A<T>::Show(){
	cout << x << y << endl;
}

//类外初始化
template<class T>	int A<T>::k = 0 ;
//静态类模板成员会为每一类对象初始化一个静态成员








// template class Person 

template<class T , class T1>
class Person{
public:
	T name ;
	T1 age ;

	Person(T n , T1 a) : name(n) , age(a) { }
	void Show();


	//friend ostream& operator<< <T,T1>(ostream& os , const Person<T,T1>& p) ; // 友元
};

template<class T  , class T1 >
void Person<T,T1>::Show() {
		cout << "Name : " << name << " Age: " << age << endl;
}



/*
模板类的头文件与模板实现机制

编译
	对每一个cpp文件独立编译，当发现一个函数调用是，在当前文件找不到的话，会
	在函数位置生成符号
函数模板是二次编译
并没有生成具体函数

Person.h
	... //模板声明
Person.hpp
	#include "Person.h"
	.. //模板实现.

main.cpp
	#include "Person.hpp" //引用模板



*/






static int* get(){
	return new int() ;
}

class B{
	public:
		int x ;
		B(int c) : x(c) { } 
		~B(){f() ;}
	virtual void f(){ cout << "D B" << endl;}
};

class C : public B{
	public:
		~C() { f() ;}
	void f() {cout << "D C" << endl;}
};


void test(){


	//  数组移位  输入k，然后将数组移动k位

	int k = 14 ;
	//cin >> k ;
	const int n = 15 ;

	int arr[] = {1 ,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int j = k % n ;
	if(!j){
		for(auto &x : arr)
			cout << x << endl;
		return ;
	}
	while(j--){
		int i ;
		int x = arr[0] ;
		for(int i = 1 ;i < n ; ++i){
			int tmp = arr[i] ;
			arr[i] = x ;
			x = tmp ;
		}
		arr[0] = x ;

	}
	for(auto &x : arr)
		cout << x << "   " ;
}


void test02()
{
	clock_t start ,end; // 毫秒级
	start = clock() ;
	const int N = 1000001 ;
	char a[N] = {0};
	for(int i = 4 ; i < N ; i += 2)
		a[i] = 1 ;
	
	for(int i = 3 ; i * i < N ; i += 2){
		for(int j = 2 ; i * j < N ; j++){
			a[j * i] = 1 ;
		}
	}
	for(int i = 2 ; i < N ; ++i)
		if(!a[i])
			cout << i << '\t' ;


	end = clock() ;

	memset(a,0,N);

	cout << "Use time is " << end - start << "(ms)" << endl ;
	start = end ;


	for(int i = 2 ; i < N ; ++i){
		int j ;
		for( j = 2 ; j * j <= i ; ++j){
			if(i % j == 0){
				break ;
			}
		}
		if(j * j <= i)
			a[i] = 1 ;
	}
	cout << "\n\n\n" << endl;
	for(int i = 2 ; i < N ; ++i)
		if(!a[i])
			cout << i << '\t' ;

	end = clock() ;
	cout << "Use time is " << end - start << "(ms)" << endl ;

}

int fibn(int num )
{
	int a = 1 , b = 1 ; 
	int s = 0 ;
	// cin >> num ;  

	if(num < 0)
		return -1 ;
	if(num == 0 || num == 1){
		s = 1 ;
		return s ;
	}
	for(int i = 2 ;i <= num ; ++i){
		s = a + b ;
		a = b ;
		b = s ;
	}
	return s ;
}

typedef struct _node{
	int val;
	string name ;
}Node ;


int main()
{
	
	std::ios::sync_with_stdio(false);
	//关闭同步stdio
	std::cin.tie(nullptr);
	//关掉cin 和iostream中的输出流的关联

	return 0 ;
}