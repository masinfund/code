#include <iostream>

using namespace std ;



//一 程序阅读题

//-------------------------------1-----------------------------------

/*#include <iomanip>
#include <cmath>

int main()
{
	int a[4] = {25,-2,13,7} ;
	int i ,  y ;
	for(i = 0 ; i < 4 ; ++i){
		if(a[i] <= 0)
			y = sqrt(a[0]) + a[1] ;
		else if(a[i] <= 10 && a[i] > 0) 
			y = ++a[2] * 2 - 1 ;
		else if(a[i] <= 20 && a[i] > 10) 
			y = (a[3] < a[2]) ? a[3] : a[2] ;
		else
			y = a[0] % 10 + a[0] / 10 + 1 ;
		cout << setw(5) << a[i] <<setw(5) << y << endl;
	}

	cout << sqrt(3.4) << endl;
	//output
	//   25    8
	//   -2    3
	//   13    7
	//    7   27


	return 0 ;
}*/



//------------------------2------------------------------------
/*
void print(int , char , int );
int main()
{
	print(3,'*',1) ;
	print(2,'*',3) ;
	print(1,'*',5) ;
	print(2,'#',3) ;
	print(2,'#',3) ;
	return 0 ;
}

void print(int begin , char pzf , int n)
{
	char a[50] ;
	int i ;
	for(i = 0 ;i < begin ; ++i)
		a[i] = ' ' ;
	for(i = 0 ; i < n ; ++i)
		a[begin + i] = pzf ;
	a[begin + i] = '\0' ;
	cout << a << endl;
}*/


//---------------------------------3----------------------------
/*#include <cstring>
void fun(char *p){
	char *p1 ; 
	p1 = p ;
	// while(*p1 != '\0')
	// 	if(*p1 == ' ' && *(p1 + 1) == ' ')
	// 		strcpy(p1,p1 + 1) ;
	// 	else 
	// 		p1++ ;
	while(*p1 != '\0'){
		if(*p1 == ' '){
			int cnt = 0 ;
			char* tmp = p1 ;
			while(*tmp++ != '\0')
				if(*tmp == ' ')
					cnt++ ;
				else 
					break;
			if(cnt)
				strcpy(p1,p1 + cnt) ;
		}
		p1++ ;
	}
}

int main()
{
	char aa[] = "aa bb      cccc    dd  efg   h" ;
	cout << aa << endl;
	fun(aa) ;
	cout << aa << endl;
}*/


//---------------------------4--------------------------------
/*#include <iomanip>

class Time{
public:
	Time() { minute = 0 , sec = 0 ;}
	Time(int m , int s ) : minute(m) , sec(s) {}
	Time fun1() ;
	Time fun2() ;
	void display() { cout << setw(2) << setfill('0')<< minute << ":" << setw(2) << sec << endl;}
private:
	int minute ;
	int sec ;
};


Time Time::fun1(){
	if(++sec >= 60){
		sec -= 60 ;
		++minute ;
	}
	return *this ;
}

Time Time::fun2(){
	Time temp(*this ) ;
	sec++ ;
	if(sec >= 60){
		sec -= 60 ;
		++minute ;
	}
	return temp ;
}

int main()
{
	Time time1(34,59) , time2 ;
	cout << "time1:  " ;
	time1.display() ;
	time1.fun1() ;
	cout << "++time1:  " ; 
	time1.display() ;
	time2 = time1.fun2() ;
	cout << "timel++:  " ;
	time1.display() ;
	cout << "time2:  " ; 
	time2.display() ;
	// output:
	//time1:  34:59 
	//++time1:  35:00
	//tile1++:  35:01
	//time2:  35:00

	return 0 ;
}*/


//--------------------------------5----------------------------

/*class Base{
public:
	Base(int i ){
		x = i ;
		cout << "Constructor of Base." << endl;
	}
	~Base(){cout << "Destructor of Base." << endl;}
	void show(){cout << "x=" << x << endl;}
private:
	int x ;
};

class Derived:public Base{
public:
	Derived(int i ) : Base(i) , d(i) {
		cout << "Constructor of Derived." << endl ;}
	~Derived(){
		cout << "Destructor of Derived." << endl;
	}
private:
	Base d ;
};

int main(){
	Derived obj(5) ;
	obj.show() ;
	//output:
	//Constructor of Base.
	//Constructor of Base.
	//Constructor of Derived.
	//x=5
	//Destructor of Derived.
	//Destructor of Base.
	//Destructor of Base.
	return 0 ;
}*/


//二程序改错题
//---------------------------------1------------------

/*void sort(int * , int ) ; // 4 sort函数声明放在main函数之前
int main()
{
	int i , n ;
	cin >> n ;
	int a[n] ;
	for(i = 0 ;i < n ; ++i)
		cin >> a[i] ;
	sort(a , n) ;
	for(i = 0 ;i <n ; ++i)
		cout << a[i] ;
	return 0 ;
}

void sort(int* x , int m){
	int i , j , k , temp ;

	//select 
	for(i = 0 ;i < m - 1 ; ++i){
		k = i ;
		for(j = i + 1 ; j < m ; ++j){
			if(x[k] > x[j])
				k = j ;
		}
		if(i == k)
			continue ;
		temp = x[k] ;
		x[k] = x[i] ;
		x[i] = temp ;
			
	}
	//bubble
	for(i = 0 ;i < m - 1 ; ++i){
		int flag = 1 ;
		for(j = 1 ; j < m - i ; ++j){
			if(x[ j - 1] < x[j]){
				int tmp = x[j - 1] ;
				x[j - 1] = x[j] ;
				x[j] = tmp ;
				flag = 0 ;
			}
		}
		if(flag)
			break;
	}
}*/






// --------------------------------2-------------------

/*
class Box{
public:
	Box(int , int) ;
	friend void print(Box& b) ;
private:
	static const int height = 10 ;
	int width ;
	int length ;
};

Box::Box(int w , int len){
	width = w ;
	length = len ;
}

void print(Box& b){
	cout << Box::height << endl;
	cout << b.length << endl;
}

int main()
{
	Box a(15,20) , b(20,30) ;
	print(a) ;
	print(b) ;
	return 0 ;
}*/


//编程题
//-----------------------------1-----------------------------
//#include <iostream>
//using namespace std ;

/*class Goods{
private:
	double price ;
	int num ;
public:
	Goods(double p , int n) : price(p) , num(n){}
	double getPrice(){
		return price ;
	}
	int getNum(){
		return num ;
	}
};

double cost(const Goods& g){
	return g.getPrice() * g.getNum() ;
}


int main()
{
	Goods ga(3.4,5) , gb(332,24) ;
	double sum = 0 ;
	sum += cost(ga) ;
	sum += cost(gb) ;
	cout << "花费的钱数为 : " << sum << endl;
	return 0 ;
}*/



//----------------------------------------2----------------------


/*
#include <string>
#include <fstream>
#include <vector>

class School{
private:
	int id ;
	string name ;
	double cost ;
public:

	School(int x , string n , double c) : id(x) , name(n) , cost(c){}
	int getId(){
		return id ;
	}
	void putId(){
		cout << id  ;
	}
	double getCost(){
		return cost ;
	}
	void putCost(){
		cout << cost ;
	}
	string getName(){
		return name ;
	}
	void putName(){
		cout << name ;
	}
};

class MaxSchool{
	vector<School> vs ;
public:
	MaxSchool() ;
	void Max() ;
};

MaxSchool::MaxSchool(){
	ifstream in("noinput",ios::binary) ;
	if(in){
		int id ;
		double cs ;
		string nm ;
		int n = 5 ;
		while(n--){
			in >> id >> nm >> cs ;
			School tmp(id,nm,cs) ;
			vs.push_back(tmp) ;
		}
	}
	in.close();
}

void MaxSchool::Max(){
	int max = 0 , idx ;
	for(decltype(vs.size()) i = 0 ; i != vs.size() ; ++i){
		if(vs[i].getCost() > max){
			max = vs[i].getCost(); 
			idx = i ;
		}
	}
	vs[idx].putId() ;
	vs[idx].putName();
	vs[idx].putCost() ;
}

int main()
{
	MaxSchool ms ;
	ms.Max() ;
	return 0 ;
}*/