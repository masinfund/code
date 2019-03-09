#include <iostream>
using namespace std ;

// 一
//----------------------------1------------------------

/*int a[8] = {1,2,3,4,5,6,7} ;
void fun(int *pa , int n);
int main()
{
	int m = 8 ; 
	fun(a , m) ;
	cout << a[7] << endl ;
	// output : 28 
	return 0 ;
}

void fun(int *pa , int n)
{
	for(int j = 0 ; j < n - 1 ; ++j)
		*(pa + 7) += *(pa + j) ;
}*/


//--------------------------2------------------------------------

/*class A {
public:
	A(int i , int j){
		a = i ; 
		b = j ;
	}
	void Move(int x , int y){
		a += x ;
		b += y ;
	}
	void Show(){
		cout << "(" << a << "," << b << ")" << endl ;
	}
private:
	int a , b ;
};

class B : public A {
public:
	B(int i , int j , int k , int l): A(i,j),x(k),y(l){}
	void Show(){ cout << x << "," << y << endl ;}
	void F1(){Move(3,5) ; A::Show();}
private:
	int x , y ;

};

int main()
{
	A a(1,2) ;
	a.Show() ;
	B b(3,4,5,6) ;
	b.A::Show();
	b.B::Show() ;
	b.F1() ;
	//output :
	// (1,2)
	// (3,4)
	// 5,6
	//(6,9)
}*/


//-------------------------3----------------------------
/*#include <cmath>
class Point {
private:
	double X , Y ;
public:
	Point(double xx = 0 , double yy = 0){
		X = xx ;
		Y = yy ;
		cout << "Point(" << X << "," << Y << ")" << endl ;
	}
	Point(const Point &p){
		X = p.X ;
		Y = p.Y ;
		cout << "Point is copied." << endl ;
	}
	// Point(Point &&p){
	// 	X = p.X ;
	// 	Y = p.Y ;
	// 	cout << "Point is copied.move" << endl ;
	// }

	double Distance(Point &p) ;
};

double Point::Distance( Point &p)
{
	double dx , dy ;
	dx = X - p.X ;
	dy = Y - p.Y ;
	return sqrt(dx * dx + dy * dy) ;
}

Point f(double x , double y) 
{
	Point p(x,y) ;
	return p ;
}

int main()
{
	Point A(0,0) ;
	Point B = f(3,4); 
	// 返回的是一个临时量，使用引用无法通过编译
	// 改成创建变量B后，仍无法通过编译
	//通过将复制构造函数的形参改为接受const 版本通过编译
	//Point &B = *static_cast<Point *>(&f(3,4)); 
	// 这样也通过了编译(vs)，而不用改复制构造函数
	
	//关于使用引用的区别
	//第一个未使用引用实际上是还调用了一次移动构造函数
	//如果改成 Point B = *static_cast<Point *>(&f(3,4)); 
	// 就会调用两次复制构造函数

	//另外通过声明移动构造函数的形参为非const也通过了编译
	cout << "Distance is " << A.Distance(B) << endl ;
	//output :
	//Point(0,0)
	//Point(3,4)
	//Point is copied.
	//Distance is 5

}*/


//-------------------------4----------------------------
/*
class A{
public:
	A(){ } 
	A(const A&){cout << "A::A(const A&)" << endl ;}
	A& operator =(const A&){
		cout << "A::operator=" << endl ;
		return *this ;
	}
};

int main()
{
	A a ;
	A b = a ;
	b = b ;
	//output :
	//A::A(const A&)
	//A::operator=
	return 0 ;
}*/



//--------------------------5------------------------------------

/*class Sample{
	int A ;
	static int B ;
public:
	Sample(int a) {A = a ; B += a ;}
	static void func(Sample& s) ;
};

int Sample::B = 0 ;
void Sample::func(Sample& s){
	cout << "A=" << s.A << " ,B=" << B << endl ;
}
int main(){
	Sample s1(2),s2(7) ;
	Sample::func(s1) ;
	Sample::func(s2) ;
	//output :
	//A=2 ,B=9
	//A=7 ,B=9
//静态成员函数访问非静态成员需要通过对象.成员的形式

}*/



//二
//---------------------------1-------------------------------------

/*double f(double a[] , double b[] , int n){ 
	// 加返回值 double 
	// 去* 号，改形参类型为double 
	double s = 0 ; // 改s 为double 
	for(int i = 0 ; i < n ; ++i)
		s += a[i] * b [i] ;
	return s ;
}

int main()
{
	double c[4] = {1.1,2.2,3.3,4.4} , d[4] = {10,0,100,0} ;
	cout << f(c,d,4) << endl ;
	//output : 341
}

*/


/*class AA {
public:
	//或者AA(int i = 0 , int j = 0) 
	AA(int i , int j){
		A = i ; B = j ;
		cout << "Constructor.\n" ; 
	}
	~AA(){
		cout << "Destructor.\n" ;
	}
	void Print() ;
private:
	int A , B ; 
	//类内初始化，C++11 可用，旧版的不可以通过编译，
};

void AA::Print(){
	cout << A << " , " << B << endl ;
}


int main(){
	AA *a1 , *a2 ;
	a1 = new AA(1,2) ;
	a2 = new AA(3,4) ;
	a1->Print() ;
	a2->Print() ; // 指针
	delete a1 ;
	delete a2 ;
	//output :
	//Constructor.
	// Constructor.
	// 1 , 2
	// 3 , 4
	// Destructor.
	// Destructor.
}
*/

/*void f(char *p) // 加*
{
	p++ ;
	char &c = *p ;
	c += 'A' - 'a';
}

int main() // 因为返回了0,那这里就改成int 
{
	char str[] = "abcde" ;
	f(str + 3) ;
	cout << str << endl;
	//output
	//abcdE

	return 0 ;
}
*/


//-----------------------------4-------------------------------

/*class local{
	int x , y ;
public:
	int printY(){cout << y ;} // 把printY 写成公有成员函数
	void init() {x = 0 ; y = 1 ;} // 加;
	int printX(){cout << x ;}
}; //加 ;

int main()
{
	local a, b , c ;
	a.init();
	a.printX() ;
	b.printY() ;
	//output : 00
}*/

//------------------------5---------------------------------------

/*class Base{
public:
	Base(){}
	Base(int c) : count(c){}
	virtual void print() const  {cout << "Base" << endl;}
	//纯虚函数无法构造对象，故改写print();
private:
	int count ;
};

class Derived : public Base{
public:
	Derived() : Base(0){}
	Derived(int c) : Base(c) {}
	void print() const {cout << "Derived" << endl;}
};

int main()
{
	Derived d(10) ;
	Base dd(1) ; //改虚函数
	Base *pb ;
	pb = &d ;
	pb->print() ;
	Base &cb = d;
	Derived ddd = *static_cast<Derived * >(pb) ;
	//不能从基类向派生类转换,可以使用强制类型转换,安全性由自己把握了，此处是可以的(本来就是派生类的对象)
	//output : Derived 

}*/

//三编程题
//--------------------------1--------------------------------------
//#include <iostream>
//#include <iomanip>
//using namespace std ;
/*class Time {
private:
	int hour ;
	int minute;
	int second ;
public:
	Time(int h = 0 , int m = 0 , int s = 0) : 
	hour(h), minute(m) , second(s) { } 

	int getHour() const {return hour ;}
	void setHour(int h){hour = h ;}
	
	int getMinute() const { return minute;}
	void setMinute(int m) { minute = m ;}

	int getSecond() const {return second ;}
	void setSecond(int s) { second = s ;}

	void setTime(int h , int m , int s){
		hour = h ;
		minute = m ;
		second = s ;
	}

	void disp12(){
		cout << setfill('0') << setw(2) << (hour % 12) 
			 << ":" << setw(2) << minute << ":" 
			 << setw(2) << second ;
		if(hour > 12)
			cout << "PM" << endl;
		else 
			cout << "AM" << endl;
		//cout << setfill(' ') ;
	}

};


int main()
{
	Time t1(13,45,12),t2(9,30,50) ;
	t1.disp12() ;
	t2.disp12() ;
}*/


//------------------------------------2-------------------------

/*//#include <iostream>
#include <fstream>
//using namespace std ;
#include <map>
#include <vector>
#include <algorithm>
int main()
{
	ifstream in("noinput",ios::binary) ;
	if(in){
		multimap< int , string > m ;
		int stuNum , currNum  , i ;
		in >> stuNum >> currNum ;
		cout << stuNum << "  " << currNum << endl ;
		for(i = 0 ; i < stuNum ; ++i){
		 	string name ;
		 	int tmp , avg = 0 ;
		 	in >> name  ;
		 	for(int j = 0 ;j < currNum ;++j){
		 		in >> tmp ;
		 		avg += tmp ;
		 	}
		 	avg /= currNum;
		 	m.insert(make_pair(avg , name));
		}
		vector<pair<int , string > > v(m.rbegin() , m.rend()) ;
		sort(v.begin() , v.end() , [](const pair<int , string >& lhs , const pair<int , string >& rhs) 
		{
			if(lhs.first > rhs.first )
				return true ;
			else if(lhs.first == rhs.first && lhs.second < rhs.second)
				return true ;
			else 
				return false;
		}) ;
		i = 1 ;
		for(auto it = v.begin()  ; it != v.end() ; ++it , ++i){
			cout << i << " " << it->second << "  " << it->first << endl;
		}
	}
	in.close() ;

// in :
// 7 4

// smith 60 50 80 24
// frank 80 60 70 24
// file  99 91 32 40
// zdd   63 63 63 24
// jie   97 78 88 24
// mik   37 92 49 87
// yd    63 63 63  24

// output :
// 1 jie  71
// 2 mik  66
// 3 file  65
// 4 frank  58
// 5 smith  53
// 6 yd  53
// 7 zdd  53

	return 0 ;

}*/