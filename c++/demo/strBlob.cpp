
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <climits>
#include <cctype>
#include <array>
#include <iterator>
#include <functional> // bind
#include <typeinfo>
//对某个空指针p执行typeid(*p)  throw bad_typeid
#include <initializer_list>
#include <windows.h>
#include <memory>
#include <cassert> 
#include <stdexcept>
#include <deque>
#include <list>
#include <stack>
#include <forward_list>
#include <utility>
#include <locale>


#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;


//Strblob 

class StrBlobPtr ;

class StrBlob {
	friend class StrBlobPtr ;
	public :
		typedef std::vector<std::string>::size_type size_type ;
		
		StrBlob() ;
		StrBlob(std::initializer_list<std::string> i1) ;
		size_type size() const {return data->size() ;}
		StrBlobPtr begin() ;
		StrBlobPtr end()  ;

		bool empty() const {return data->empty() ;} 
		void push_back(const std::string &t) {data->push_back(t) ;}
		void pop_back() ;
		std::string &front() ;
		std::string &front() const ;
		std::string &back() ;
		std::string &back() const ;
	private :
		std::shared_ptr<std::vector<std::string>> data ;
		void check(size_type i , const std::string &msg) const ;
} ;

StrBlob::StrBlob() :data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> i1) : 
			data(make_shared<vector<string>>(i1)){ }
void StrBlob::check(size_type i , const std::string &msg) const {
	if(i >= data->size())
		throw out_of_range(msg) ;
}

string &StrBlob::front() {
	check(0,"front on empty StrBlob") ;
	return data->front() ;
}
std::string &StrBlob::front() const {	
	check(0,"front on empty StrBlob") ;
	return data->front() ;
}
std::string &StrBlob::back() const {
	check(0,"back on empty StrBlob") ;
	return data->back() ;
}
string &StrBlob::back() {
	check(0,"back on empty StrBlob") ;
	return data->back() ;
}

void StrBlob::pop_back() {
	check(0,"pop_back on empty StrBlob") ;
	cout << data->back() << " " ;
	data->pop_back() ;
}


class StrBlobPtr
{
private :
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t , const std::string &) const ;
	std::weak_ptr<std::vector<std::string>> wptr ;
	std::size_t curr ;
public:
	StrBlobPtr() : curr(0) {};
	StrBlobPtr(StrBlob &a , size_t sz = 0) : wptr(a.data),curr(sz) {}
	std::string & deref() const ;
	StrBlobPtr& incr() ;
	
};
std::string& StrBlobPtr::deref() const {
	auto p = check(curr,"dereferecne past end") ;
	return (*p)[curr] ;
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr,"increment past end") ;
	++curr ;
	return *this ;
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i , const std::string &msg) const 
{
	auto ret = wptr.lock() ;
	if(!ret)
		throw runtime_error("unbound StrBlobPtr") ;
	if(i >= ret->size())
		throw std::out_of_range(msg) ;
	return ret ;
}


// Strblob 在声明之后再调用StrBlobPtr的函数时，一定要将此函数声明写在
//StrBlobPtr 函数体定义之后，即写在StrBlobPtr之后
StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this) ;}
StrBlobPtr StrBlob::end() {auto ret = StrBlobPtr(*this ,data->size()) ; return ret ;}




int main(int argc, char const *argv[])
{


    return 0;
}

