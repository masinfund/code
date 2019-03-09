#include <iostream>

using namespace std ;


//程序阅读题 
//------------------------------------------1----------------------
/*#define DOUBLE(x) x + x  // #define DOUBLE(x) ((x) + (x))
int main()
{
	int i = DOUBLE(5) * 5 ;
	cout << i << endl;
	//output:
	//30 
}*/


//-----------------------------------------2-------------------------

/*int main(){
	int i , j , x= 0 ;
	for(i = 0 ;i < 2 ; i++){
		x++ ;
		for(j = 0 ; j < 3 ; j++){
			if(j % 2)
				continue ;
			x++;
		}
		x++ ;
	}

	cout << "x=" << x << endl;
	//output:
	//x=8  // (1 + 2 + 1) * 2
}
*/

//-----------------------------------3-----------------------------

/*void f(int *s){
	static int j = 0 ;
	do{
		s[j] += s[j + 1] ;
	}while(++j < 2) ;
}

int main()
{
	int k , a[10] = {1,2,3,4,5};
	for(k = 1 ; k < 3 ; k++ )
		f(a) ;
	for(k = 0 ; k < 5 ; k++)
		cout << a[k] << "  " ;
	//output:
	//3 5 7 4 5
}*/

//---------------------------------4------------------------------
/*
class A{
	int a ;
public:
	A() { cout << "calls A constructor" << endl;}
};
class B{
	int b ;
public:
	B(){cout << "calls B constructor" << endl;}
};

class C : public A , public B{
	B b ;
	A a ;
	int c ;
public:
	C(){
		cout << "calls C constructor" << endl;
	}
};

int main()
{
	C c ; 
	//output:
	//A
	//B
	//B
	//A
	//C 
}*/

//--------------------------------5--------------------------
/*class A{
	int num ;
public:
	A(){ num = 0 ; cout << "缺省构造函数" << endl;}
	A(int n) {num = n ; cout << "带参构造函数，num=" << num << endl;}
	~A(){cout << "析构函数,num=" << num << endl;}
};

int main(){
	A a , *p ;
	p = new A(2) ;
	a = *p ;
	delete p ;
	cout << "退出" << endl;
	//output : 缺省构造函数
	//带参构造函数，num=2 
	//析构函数，num=2
	//退出
	//析构函数，num=2
}*/


//二程序改错题
//----------------------------------1-------------------------

/*int main(){
	char c = 'c' ; // 字符赋值
	cout << c << endl;
	int b = 1024 ; // 范围溢出
	b += 1024 ;
	if(b == 2048){
		cout << "Test" << endl;
	}
	return 0;
}*/


//-------------------------------2-------------------------------
/*class CRectangle{
private:
	double length , width ;
public:
	CRectangle(){
		cout << "Default constructor.\n" ;
	}
	CRectangle(double l , double w){
		length = l ;
		width = w ;
		cout << "Constructor.\n" ;
	}
	void Set(double l , double w){
		this->length = l ;
		this->width = w ;
	}
	void GetArea(){
		cout << "Area is " << length * width << endl;
	}
};

int main()
{
	CRectangle Rect1(3.0,4.0);
	CRectangle Rect2;
	Rect1.GetArea();
	Rect2.Set(0,0) ;
	Rect2.GetArea();
	Rect1.GetArea();
}*/


//三编程题

//-----------------------------1---------------------------------
/*#include <algorithm>
#include <cstring>

void fun(char *ch)
{
	sort(ch + 1, ch + strlen(ch) - 1 , [](const char &c1 , const char &c2){return c1 > c2 ;});
}
int main()
{
	char ch[] = "zxafdxc";
	fun(ch);
	cout << ch << endl;
	return 0 ;
}
*/

//-------------------------------------2-----------------------

/*struct student{
	int grade ;
	student *next ;
};

int fun(student *head){
	if(!head)
		return -1 ;
	int max = 0;
	student *s = head->next ;
	while(s){
		if(s->grade > max)
			max = s->grade ;
		s = s->next ;
	}
	return max ;
}

*/


//---------------------------------3------------------------------
#define PI 3.14159
#include <cmath>
class Shape
{
    double r;
  public:
    Shape(double x) : r(x) {}
    virtual ~Shape() {}
    virtual double area() const = 0;
    double getR() const { return r; }
};

class Circle : public Shape
{
  public:
    Circle(double x) : Shape(x) {}
    double area() const { return PI * getR() * getR(); }
};

class Square : public Shape
{
  public:
    Square(double x) : Shape(x) {}
    double area() const { return getR() * getR(); }
};

class Rectangle : public Shape
{
    double w;
  public:
    Rectangle(double x, double wid) : Shape(x), w(wid) {}
    double area() const { return getR() * w; }
};

class Triangle : public Shape
{
    double x1, x2;
  public:
    Triangle(double x, double y, double z) : Shape(x), x1(y), x2(z) {}
    double area() const {
        double a = (getR() + x1 + x2) / 2;
        return sqrt(a * (a - getR()) * (a - x1) * (a - x2) );
    }
};

int main()
{
    Circle c(2);
    Square s(2);
    Rectangle r(2,3);
    Triangle t(2, 3, 4);
    Shape *ps[4] = {&c, &s, &r , &t};
    double sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += ps[i]->area();
    }
    cout << sum << endl;
    return 0;
}
