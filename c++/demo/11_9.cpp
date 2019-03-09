#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>

// #include <utility>
using namespace std ;

void patient()
{
	string id ;
	int num ;
	int age ;
	//multimap<int , string > ms ;
	vector<pair<int , string> > v , v_young;
	cin >> num ;
	while(num--){
		cin >> id >> age ;
		if(age >= 60)
			v.push_back(make_pair(age , id));
		else
			v_young.push_back(make_pair(age,id));
	}
	stable_sort(v.begin() , v.end() , [](const pair<int , string> &a , const pair<int,string>&b){
		return a.first > b.first ;
	});
	
	for(auto it = v.begin() ; it != v.end() ; ++it)
		cout << it->second << endl;
	for(auto &x : v_young)
		cout << x.second << endl;

}



// mysort(void *arr , int num , int size , (*compare)(const void *a , const void *b))
// {

// }

class Base{
public:
	virtual void f(){
		cout << "B" << endl;
	}
	void fx() { cout << "Bx" << endl;}
};
class Derived : public Base{
public:
	virtual void f() { cout << "D" << endl;}
	void fx() {cout << "fx" << endl;}
};

string  dec2bin(int x)
{
	string tmp("") ;
	while(x){
		if(x % 2)
			tmp.insert(0,"1") ;
		else 
			tmp.insert(0,"0");
		x /= 2;
	}
	if(tmp.size() != 31)
		tmp.insert(0,(string(31 - tmp.size() , '0'))) ;
	return tmp;
}

struct Animal{
	Animal() { ++number ;}
	virtual ~Animal() { --number ; }
	static int number ;
};

struct Dog : public Animal{
	Dog() { ++number ;}
	~Dog() {--number ;}
	static int number ;
};
struct Cat : public Animal{
	Cat() { ++number;}
	~Cat() { --number ; }
	static int number ;
};

int Animal::number = 0 ;
int Dog::number = 0 ;
int Cat::number = 0 ;
/*
cout << Animal::number << " " <<  Dog::number  << "  " << Cat::number << endl;
	
	Dog d1 , d2 ;
	Cat c1 ;
	cout << Animal::number << " " <<  Dog::number  << "  " << Cat::number << endl;
	
	Dog *d3 = new Dog() ;
	Animal *c2 = new Cat ;
	Cat *c3 = new Cat ;
	cout << Animal::number << " " <<  Dog::number  << "  " << Cat::number << endl;
	
	delete c3 ;
	delete c2 ;
	delete d3 ;
	cout << Animal::number << " " <<  Dog::number  << "  " << Cat::number << endl;
	
*/


//计算

template <class T>
class Add{
public:
	Add(const T& x) : n(x) {} 
	T operator()(T a , T b){ return a + b - n;}
private:
	T n ;
};

template <class T>
class CMyClass{
public:
		vector< T> b  ;
		CMyClass(T * x , int m){
			for(int i = 0 ;i < m ; ++i)
				b.push_back(x[i]) ;
		}
		T operator[](int i){return b[i] ;}
};

// 在此处补充你的代码
template < class T , int sz >
class A{
public:
	T a[sz] ;
	T *ms ;
	A(const T *x){
		ms = new T() ;
		for(int i = 0 ;i < sz ; ++i)
			a[i] = x[i] ;
	}
	~A() { delete ms ;}
	T sum(){
		for(int i = 0 ;i < sz ; ++i){
			*ms += a[i] ;
		}
		return *ms ;
	}
	T& operator [](int idx){
		return a[idx] ;
	}

};

#include<iomanip>

double GetDoubleFromString(char * str)
{
	static char* p;
	if(str)
	    p = str;
	double num = 0 ;
	while(*p && !(*p>='0'&&*p<= '9'))  
		++p;
	if(*p == 0)
    	return -1;
	while(*p>='0' && *p<='9'){    
		num = num*10+*p-'0';
		++p;}

	if(*p == '.'){    
		++p;    
		double i = 10;   
 		while(*p>='0' && *p<='9') {        
 			num += (*p-'0')/i; 
 	       	++p;
 	        i *= 10;
 	    }
 	}
 	return num;

}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}
 

/*

please 121a1 stand 0.7 9.2 1010.3983 0.00001 black stand what 1324.3
12.34 45 78ab78.34
please 121a1 stand 0.7e9.2 1010.39f83 0.00001 black stand what 1324.3
2.5 2.5 2.5



2
1
1
0
fasfsdf
0 animals in the zoo, 0 of them are dogs, 0 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
6 animals in the zoo, 3 of them are dogs, 3 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats

2
1 2 3 4 5 6 7 8 9 10
4.2 0.0 3.1 2.7 5.2
Hello , world !
10 9 8 7 6 5 4 3 2 1
9.2 0.0 3.1 2.7 6.2
This is a cat

3
15.2
Hello,world!
8
21.2
Thisisacat



12
1
3773
8
2147483647
2147483646
1073741823
0
20
4
16
268435456
1073741824

0000000000000000000000000000001
0000000000000000000111010111101
0000000000000000000000000001000
1111111111111111111111111111111
1111111111111111111111111111110
0111111111111111111111111111111
0000000000000000000000000000000
0000000000000000000000000010100
0000000000000000000000000000100
0000000000000000000000000010000
0010000000000000000000000000000
1000000000000000000000000000000

0000000000000000000000000000001



43
4094882 65
5517115 43
7614232 83
1685761 39
9279543 12
2334113 69
7427793 42
9865028 7
0248650 30
0061389 24
4460661 9
4963788 83
9135984 31
7636154 73
0973726 91
1657541 53
0014607 92
7777335 10
9818266 31
3801250 60
4783512 51
1640618 100
8414398 39
0877838 84
7107349 17
5109968 4
4849925 86
3337438 1
8806819 99
9722828 80
0781586 12
2425862 87
5392461 99
2119762 90
5200391 89
1953252 86
8677229 55
1969825 56
4912508 54
9396799 38
6935766 6
8254416 72
6335532 9

1640618
8806819
5392461
0014607
0973726
2119762
5200391
2425862
4849925
1953252
0877838
7614232
4963788
9722828
7636154
8254416
2334113
4094882
3801250

5517115
1685761
9279543
7427793
9865028
0248650
0061389
4460661
9135984
1657541
7777335
9818266
4783512
8414398
7107349
5109968
3337438
0781586
8677229
1969825
4912508
9396799
6935766
6335532

*/