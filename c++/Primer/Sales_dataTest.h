// Life is limited while learning is limitless, 
//limiting life chasing endless learning until die .

#ifndef SALES_DATATEST_H
#define SALES_DATATEST_H 

#include "stdafx.h"
/* 
在c++ 中 出现undefined reference to `add' 的错误 ， 头文件需要使用如下的extern "C" 包含代码声明 
并且使用 如下命令编译， 记住不要漏掉-lmingw32 . (这个最重要,因为在Sales_data.h中没有使用extern "C" 
也可以使程序远行，加extern "C" 是因为使用 gcc编译？)

D:\code\c++>g++ -c Sales_test.cc Sales_dataTest.cc

D:\code\c++>g++ -o -lmingw32 Sales_test.o Sales_dataTest.o -o test

*/
#ifdef __cplusplus
extern "C" {
#endif

struct Sales_dataTest{
	//构造函数 
	Sales_dataTest() = default ; // 内联的
	Sales_dataTest(const std::string &s) : bookNo(s) { }
	// equal to Sales_data(cosnt std::string &s) : 
	//bookNo(s) , units_sold(0) , revenue(0) { } ,即其他执行隐式初始化

	Sales_dataTest(const std::string &s,unsigned n , double p) :
				bookNo(s),units_sold(n),revenue(p * n) { }
	Sales_dataTest(std::istream &is) ;
	Sales_dataTest(const Sales_dataTest &) ;

	Sales_dataTest& operator=(const Sales_dataTest &rhs) ;


	/*类内实现构造函数
	Sales_dataTest(std::istream &is)
	{
		double price ;
		is >> this->bookNo >> this->units_sold >> price ;
		this->revenue = this->units_sold * price ;
	}
	*/
	

	//类对象的操作(成员)函数
	std::string isbn() const {return bookNo; } 
	Sales_dataTest& combine(const Sales_dataTest& ) ;
	inline double avg_price() const ;
	//数据成员
	std::string bookNo ;
	unsigned units_sold = 0 ;
	double revenue = 0.0 ;
};

// Sales_dataTest 的非成员接口函数 ，应与类声明在同一个头文件内。
Sales_dataTest add(const Sales_dataTest& lhs, const Sales_dataTest& rhs ) ;
std::ostream &print(std::ostream &os, const Sales_dataTest& item) ;
std::istream &read(std::istream&is , Sales_dataTest&item) ; // 读入会修改数据，no const . 


// 定义在类内部的函数是隐式的inline函数

// 成员函数体可以定义在类内也可以定义在类外，在成员函数内部，
//可以直接使用调用该函数的对象的成员，实际上是通过一个名为this
//的额外的隐式参数来访问调用它的那个对象。
//equal to strd::string isbn() const {return this->bookNo ;} 
//默认情况下this的类型1是指向类类型对象的非常量版本的常量指针
//const : 修饰隐式this 指针(Sales_dataTest *const )的类型，
//表示this可以是一个指向常量的常量指针，即isbn可以是一个普通函数也可以是
//一个常量函数。故使用const ,放在成员函数的参数列表之后，则
//常成员函数的声明和定义都要加const 限定，可以访问const or no-const
//的数据成员，但是不可以修改 ，称为常量成员函数(const member function)
//即常数据成员函数不修改他所在对象内的值 ，即使那个数据可以修改
//const 数据成员可以被const 成员函数访问，也可以被非const的成员函数访问
//以下是非常量成员函数修改对象内的值 ：
// class A{
// 	public :
// 		A(int val = 2) : data(val) { }
// 		void f2(const int &d) ;
// 	private :
// 		int data ;
// } ;

// void A::f2(const int &d)
// {
// 	data = 3 ;
// 	cout <<data ; // now data is 3 ;
// }


// 编译器分两步处理类：首先编译成员的声明，然后才轮到成员函数体(如果有的话
//可能在外面) ，因此 ，成员函数体可以随意使用类中的其他成员而无视次序。

//类外部定义的成员的名字必须包含它所属的类名，且返回类型、参数列表和
//函数名都得与类内部的声明保持一致，是常量成员函数也必须明确指定const属性
/*
	函数放在头文件中的方法
		使用关键字inline 修饰函数定义 。编译器会再调用此函数的地方
		把函数的目标代码直接插入，像宏一样展开 。 

		ex : inline int add(int x , int y ) 
			 {
				return x + y ;
			 }
		也可以使用static修饰函数定义 。 使所有包含此头文件的源文件
		都会存在此函数的一份副本 ，代码会膨胀，但不会互相冲突 ，因
		为static关键字保证了该函数的可见度为单个源文件内。 
		成员函数不可用static . 

		最后就是通过类的成员函数实现 
		static int add(int x , int y) 
		{
			return x + y ;  
		}

		以上方法最好不用， 即函数声明和实现最好分开。 
*/

inline 
bool compareIsbn(const Sales_dataTest &lhs, const Sales_dataTest &rhs)
{
	return lhs.isbn() < rhs.isbn();
}







#ifdef __cplusplus
}
#endif

#endif 

