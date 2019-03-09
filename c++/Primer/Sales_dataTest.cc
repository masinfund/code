#include "Sales_dataTest.h"

using std::ostream ; using std::istream ;

//构造函数
Sales_dataTest::Sales_dataTest(std::istream &is)
{
	//read will read a transaction from is into this object 
	read(is,*this) ;
	//无返回类型，使用Sales_dataTest::Sales_dataTest的含义是
	//定义这个类的成员，名字是Sales_dataTest
}

//调用如上构造函数时，Sales_dataTest trans(cin) ; 
// this 就是这个trans 对象.

Sales_dataTest::Sales_dataTest(const Sales_dataTest &orig) :
bookNo(orig.bookNo) , units_sold(orig.units_sold) , 
revenue(orig.revenue) { }


//运算符重载函数 

Sales_dataTest& 
Sales_dataTest::operator=(const Sales_dataTest &rhs){
	bookNo = rhs.bookNo ;
	units_sold = rhs.units_sold ;
	revenue = rhs.revenue ;
	return *this ;
}


double Sales_dataTest::avg_price() const {
	if(units_sold)
		return revenue / units_sold ;
	else 
		return 0 ;
}

//add the value of the given Sales_data into this object 
// 定义一个返回this对象的函数
Sales_dataTest& Sales_dataTest::combine(const Sales_dataTest &rhs)
{
	units_sold += rhs.units_sold ;
	revenue += rhs.revenue ;
	return *this ; 
	// 返回调用该函数的引用,return the object on which the function
	//was called
}

//当程序调用如下的函数total.combine(trans) ;
//total 的地址被绑定到隐式的this 参数上，而rhs绑定到了trans上。
// return *this 解引用this 指针，返回total 的引用


Sales_dataTest add(const Sales_dataTest &lhs, const Sales_dataTest &rhs)
{
	Sales_dataTest sum = lhs ;  // 拷贝类的对象的数据成员
	sum.combine(rhs) ;

	/*
	sum.units_sold += rhs.units_sold ;
	sum.revenue += rhs.revenue ;
	return sum ; 
	*/
	return sum ;
}

// transactions contain ISBN , number of copies sold , and sales price

std::istream &read(std::istream &is , Sales_dataTest &item) 
{
	double price = 0 ;
	is >> item.bookNo >> item.units_sold >> price ;
	item.revenue = price * item.units_sold ;
	return is ; 
}

std::ostream &print(std::ostream &os , const Sales_dataTest &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price() ;
	return os ;
}
 // cout << a << b ;  ==     operator << (operator << (cout ,a) ,b) ;

int main(int argc, char const *argv[])
{


	ifstream input(argv[1]) ;
	ofstream output(argv[2] , ofstream::app) ;
	Sales_dataTest total ;

	if(read(input,total)){
		Sales_dataTest trans ;
		while(read(input,trans)){
			if(total.isbn() == trans.isbn()){
				total.combine(trans) ;
			}
			else {
				print(output,total) << endl ;
				total = trans ;
			}
		}
	}
	input.close() ;
	output.close()
	return 0 ;
}