#include <iostream>
using namespace std ;
#include <iomanip>
#include <cmath>
//一阅读题
//-----------------------------------1---------------------------
/*
int a[4] = {36,-5 , 73 , 8} ;
int main()
{
	int i , y ;
	for(i = 0 ; i < 4 ; ++i){
		if(a[i] < 0) 
			y = 1 ;
		else if(a[i] < 10 )
			y = a[i] * a[i] + 3 ;
		else if(a[i] < 60 )
			y = 4 * a[i] - 5 ;
		else 
			y = int(sqrt(a[i])) ;
		cout << setw(5) << a[i] << setw(5) << y  ; 
	}
	// output:  
	//   36  139   -5    1   73    8    8   67
    //...  ..   ...  .... ...  .... .... ...
}

*/

//------------------2--------------------------------------
/*void f2(int& x, int& y){
	int z = x ;
	x = y ;
	y = z ;
}
void f3(int* x , int* y){
	int z = *x ;
	*x = *y ;
	*y =  z ;
}

int main()
{
	int x = 10 , y = 26 ;
	cout << "x,y=" << x << ", " << y << endl;
	f2(x,y) ;
	cout << "x,y=" << x << ", " << y << endl;
	f3(&x,&y) ;
	cout << "x,y=" << x << ", " << y << endl;
	x++ ; y-- ;
	f2(y , x) ;
	cout << "x,y=" << x << ", " << y << endl;
	//output
	//x,y=10, 26
	//x,y=26, 10
	//x,y=10, 26
	//x,y=25, 11
}
*/

//-------------------------3------------------------------
/*#include <cstring>
class CD{
	char *a ;
	int b ;
public:
	void Init(const char *aa , int bb){
		a = new char[strlen(aa) + 1] ;
		strcpy(a , aa) ;
		b = bb ;
	}
	char *Geta() {return a ;}
	int Getb() {return b ;}
	void OutPut() {cout << a << ' ' << b << endl;}
};

int main()
{
	CD dx , dy ;
	char a[20] ;
	dx.Init("abcdef",30) ;
	strcpy(a , dx.Geta()) ;
	strcat(a,"xyz") ;
	dy.Init(a,dx.Getb() + 20) ;
	dx.OutPut() ;
	dy.OutPut() ;
	//output:
	//abcdef 30
	//abcdefxyz 50
}
*/

/*
class Franction{
	int nume ;
	int deno ;
protected:
	int gcd( int a , int b ){
		if(!b) return a ;
		gcd( b , a % b) ;
	}
public:
	void FranSimp() ;
	Franction FranAdd(const Franction& x);
	void InitFranction() {
		nume = 0 ; 
		deno = 1 ;
	}
	void InitFranction(int n , int d){
		nume = n ;
		deno = d ;
		this->FranSimp() ;
	}
	void FranOutput() {
		cout << nume << '/' << deno << endl ;
	}
};


void Franction::FranSimp()
{
	int x = gcd(nume , deno) ;
	nume /= x ;
	deno /= x ;
}

Franction Franction::FranAdd(const Franction& x) 
{
	int n = nume , d = deno ;
	n = nume * x.deno + x.nume * deno ;
	d = deno * x.deno ;
	Franction tmp ;
	tmp.InitFranction(n , d) ;
	return tmp ;
}

int main()
{
	Franction a , b , c , d;
	a.InitFranction(6,15) ;
	b.InitFranction(3,10) ;
	c.InitFranction() ;
	c = a.FranAdd(b) ;
	d = c.FranAdd(a) ;
	cout << "a : " ;
	a.FranOutput() ;
	cout << "b : " ;
	b.FranOutput() ;
	cout << "c : " ;
	c.FranOutput() ;
	cout << "d : " ;
	d.FranOutput() ;
	cout << endl ; 
	//output:
	//a : 2/5
	//b : 3/10
	//c : 7/10
	//d : 11/10
}

*/

//-----------------------------5------------------------------
/*
class Base{
public:
	Base(int i , int j ){x0 = i ; y0 = j ;}
	void Move(int x , int y) { x0 += x ; y0 += y ;}
	void Show(){cout << "Base(" << x0 << "," << y0 << ")" << endl;}
private:
	int x0 , y0 ;
};
class Derived : private Base{
public:
	Derived(int i , int j , int m , int n):
		Base(i , j) { x = m ; y = n  ;}
	void Show() { cout << "Next(" << x << "," << y << ")" << endl;}
	void Move1() { Move(2,3) ;}
	void Show1() { Base::Show() ;}
private:
	int x , y ;
};

int main()
{
	Base b(1,2) ;
	b.Show() ;
	Derived d(3,4,10,15) ;
	d.Move1() ;
	d.Show() ;
	d.Show1() ;
	//output:
	//Base(1,2)
	//Next(10,15) 
	//Base(5,7)
}*/


//改错题
//----------------------------1-----------------------


/*
struct TestClass1{
	TestClass1(int i = 0){
		m_i =  i ;
	}
	void print(){
		cout << "TestClass1: " << m_i << endl;
	}   //1
	int m_i ;
};

class TestClass2{
public:
	TestClass2() {}
	void print() {
		cout << "TestClass2" << endl;
	} // 2
	~TestClass2() {} // 3 
private:
};


int main()
{
	TestClass1 obj1 ; //4 
	TestClass2 obj2 ; //5
	obj1.print() ;
	obj2.print() ;
	return  0;
}
*/

//-----------------------------2----------------------------

/*struct NODE{
	int data ;
	NODE *next ;
};

NODE* appendToList(NODE *list , int x){
	NODE *p = new NODE ; // 1
	p-data = x ;
	p->next = NULL ;
	if(list == NULL)
		return p ;
	NODE *p1 = list ;
	while(p1->next != NULL)
		p1 = p1->next ;
	p1->next = p ;       // 2
	return list ;   
}
*/


//三 编程题
//-------------------------1----------------------

/*#include <vector>
// #include <iostream>
// using namespace std ;
class Score{
	vector<int> grades ;
public:
	void push(int x){
		grades.push_back(x) ;
	}
	void GetResult(){
		int min = 101  , max = -1 , sum = 0 ;
		for(const auto &num : grades){
			if(num < min)
				min = num ;
			if(num > max)
				max = num ;
			sum += num ;
		}
		int avg =  (sum - max - min) / (grades.size() - 2) ;
		cout << "平均得分为" << avg << endl;
	}
};
*/

//-----------------------------------------2-----------------------

/*//#include <iostream>
//using namespace 
class vehicle{
	int wheels ;
	int weight ;
public:
	vehicle() { }
	vehicle(int x  , int y) : wheels(x) , weight(y){ }
	virtual print() {
		cout << "wheels " << wheels << " weight " << weight << endl;
	}
	virtual ~vehicle() { }
};

class car : public vehicle{
	int passenger_load ;
public:
	car() { }
	car(int x ,int y , int z ) : vehicle(x,y) , passenger_load(z){}
	void print(){ vehicle::print() ; 
		cout << "passenger_load " << passenger_load << endl;}
};

class truck : public vehicle{
	int passenger_load ;
	int payload ;
public:
	truck() {}
	trunk(int x , int y , int z , int a) :
		vehicle(x,y) , passenger_load(z) , payload(a) {}
	void print(){
		vehicle::print() ;
		cout << "passenger_load " << passenger_load << " payload  "
			 << payload << endl;
	}
};*/



//-----------------------------------3----------------------------
/*
#define pi 3.1415926

class Body{
	int data ;
public:
	Body(x) : data(x) { } 
	virtual double area() const = 0 ;
	virtual double volume() const = 0 ;
	virtual ~Body() { }
};

class sphere : public Body{
public:
	sphere(int x) : Body(x) { }
	double area() const {
		return 4 * pi * data *data ;
	}
	double volume() const {
		return 4 / 3 * pi  * data * data * data ; 
	}
};

class square : public Body{
public:
	square(int x) : Body(x){ }
	double area () const {
		return 6 * data * data ;
	}
	double volume() const {
		return data * data * data ;
	}
} ;

class circleVol :public Body{
	int h;
public:
	circleVol(int x , int y) : Body(x) , h(y) { }
	double area() const {
		return 2 * pi * data * (data + h) ;
	}
	double volume() const {
		return pi * data * data * h ;
	}
};*/

