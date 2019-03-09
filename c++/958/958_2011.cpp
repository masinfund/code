// iostream.h 报错 gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
#include <iostream> 
using namespace std ;


//--------------------------1----------------------------
/*void Swap1(int a , int b)
{
	int t = a ;
		a = b ;
		b = t ;
}
void Swap2(int &a , int &b)
{
	int t = a ;
		a = b  ;
		b = t ;
}

int main()
{
	int x(3) , y(30) ;
	Swap1(x,y) ;
	cout << "x=" << x << " , y= " << y << endl ;
	Swap2(x , y) ;
	cout << "x=" << x <<" , y = " << y << endl ;
	return 0 ;

//output :  x=3 , y= 30
//			x=30 , y = 3

}*/



//---------------------2---------------------------
/*
class BaseClass 
{
public:
	BaseClass(){ cout << "constructor A " << endl ;}
	~BaseClass() { cout << "destructor A" << endl ;}

};
class DerivedClass : public BaseClass {
public:
	DerivedClass() { cout << "constructor C" << endl ;}
	~DerivedClass() { cout << "destructor C" << endl ;}
};

int main()
{
	DerivedClass d ;
// output :
// 	constructor A 
// 	constructor C
// 	destructor C
// 	destructor A
	return 0 ;
}
*/

//--------------------------3----------------------------

/*class A {
public:
	A() { }
	virtual void f() { cout << "Destructors A" << endl ;}
	~A() {f() ;}
};

class B : public A {
public:
	B() { }
	void f() { cout << "Destructors B" << endl ; }
	~B() { f() ;}
} ;

int main()
{
	B b ;
	A a = b ;
//output : 
//Destructors A
//Destructors B
//Destructors A
	return 0 ;
}*/

//-------------------------4----------------------------------
/*
class sample {
public:
	int i , j ;
	sample(int a= 0 , int b = 0) {
		i = a ;
		j  = b ;
		cout << "constructor1" << endl ;
	}
	sample(const sample& H) {
		i = H.i , j = H.j ;
		cout << "constructor2" << endl ;
	}
	void plus(sample H){
		i += H.i ; 
		j += H.j ;
	}
	void display() {
		cout << i << "  " << j << endl ;
	}
} ;




int main()
{
	sample s1(3 , 3) ,s2(4 , 4) , s3(5 , 5) ;
	s2.display() ;
	s1.plus(s3) ;
	s1.display() ;
//output :
//constructor1
// constructor1
// 4  4
// constructor2
// 8  8
	return 0 ;
}*/

//--------------------------5-------------------------
/*void f1() 
{
	static int x = 0 ;
	x++ ;
	cout << "during call to f1, x=" << x << endl ;
}

int main() 
{
	int x = 10 ; 
	cout << "Initially , x =" << x << endl ;
	f1() ; 
	f1() ;
	cout << "Atu the end,x=" << x << endl ;
// Initially , x =10
// during call to f1, x=1
// during call to f1, x=2
// Atu the end,x=10
	return 0 ;
}

*/

// 改错题
//---------------------1-----------------------------

/*class Tany{ // 加个空格
	int x , y ; // . 改成 ;
public:
	Tany(int  a , int b){ x = a , y = b ; } 
	//T 改成 int , b 后分号
	int Tsum() {return x + y ; }
	// 返回类型int , 分号
} ; // 漏 ;

 // using namespace std ;
int main() 
{
	Tany p(1 , 2) ;
	cout << p.Tsum() << endl ; // Tsum() 函数
	// output : 3 
	return 0 ;
}*/

//--------------------2---------------------------------

/*class A {
public:
	void fun() { cout << "a.fun" << endl ;}
};

class B {
public:
	void fun() { cout << "b.fun" << endl;}
	void gun() { cout << "b.gun" <<  endl ;}
};

class C: public A , public B {
private:
	int b ;
public:
	void gun() { cout << " c.gun" << endl;}
	void hun() { A::fun() ; } // A B 都有fun() ，重名
} ;

int main()
{
	C cc ;
	cc.gun() ;
	cc.B::fun() ;
	// 可以如上 加上类名以区分
	//output :  c.gun
	//b.fun
	return 0 ; 
}*/


//-----------------------3------------------------------

/*class A {
public:
	A(int x = 0 , int y = 0) : a(x) , b(y) { } // ()
	void show() {cout << a << " " << b << endl ;}
private:
	int a, b ;
};

int main(void)
{
	A obj(18) ;
	obj.show() ;
//output : 18 0
	return 0 ;
}*/

//-----------------------4----------------------------------

/*class CComplex{
	double m_real ;
	double m_image ;
public:
	~CComplex() { }
	void setValue(double r = 0 , double i = 0) {
		m_real = r ;
		m_image = i ;
	}
	double getreal(){
		return m_real ;
	}
	double getimag() {
		return this->m_image ; // this is a pointer 
	}
	void show(){
		cout << m_real << " + " << m_image << endl ;
	}
};

int main()
{
	CComplex c1 ;
	c1.setValue(2.5,7.5) ;
	cout << c1.getreal() << endl; // 私有数据不可访问
	//output : 2.5
}*/




//----------------------5---------------------------------
/*
int main()
{
	int *a ;
	int* &p = a ;
	int b = 20 ;
	p = &b ;
	// p 是a的别名，故为int * , 需要把b的地址给p,同时也就是赋给了a.
	cout << *a ;
	//output 20 
}*/

//编程题
//------------------------1-------------------------------------

//#include <iostream>
//#include <algorithm>
//using namespace std ;


/*int main()
{
	//在输入时就去除重复的数字.sort后输出
	int arr[20] , tmp , i , j , cnt ;
	cin >> arr[0] ;
	cnt = 1 ;
	while( cin >> tmp ){
		for(j = 0 ; j < cnt ; ++j){
			if(tmp == arr[j])
				break;
		}
		if(j == cnt){
			arr[cnt] = tmp ;
			cnt++ ;
		}
	}
	sort(arr,arr + cnt) ;
	for(i = 0 ; i < cnt ; ++i){
		cout << arr[i] << endl ;
	}
	return 0 ;
}
*/

//------------------------2---------------------------------

/*
class Rectangle {
private:
	int len ; // 长
	int width ; // 宽
public:
	Rectangle(int a, int b) : len(a) , width(b) { }
	friend bool operator >(const Rectangle& lhs , const Rectangle& rhs){
		return (lhs.len * lhs.width) > (rhs.len * rhs.width) ;
	}
	void area() {  cout << len * width ;}
};

bool operator >(const Rectangle& lhs , const Rectangle& rhs);//友元的类外声明

int main()
{
	Rectangle r1(5,6) ,r2(4,5) ;
	cout << "r1 area " ;
	r1.area() ;
	cout << endl ;
	cout << "r2 area " ;
	r2.area() ;
	cout << endl ;
	if(r1 > r2)
		cout << "r1 > r2" << endl ;
	else 
		cout << "r1 < r2" << endl ;
}*/