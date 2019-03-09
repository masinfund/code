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


template<typename T> 
class Blob{
public:
	typedef T value_type ;
	typedef typename std::vector<T>::size_type size_type ;

	Blob() ;
	Blob(std::initializer_list<T> il) ;

	size_type size() const {return data->size() ; }
	bool empty() const {return data->empty() ;}
	void push_back(const T &t){data->push_back(t) ;}

	void push_back(T &&t){data->push_back(std::move(t)) ;}
	void pop_back() ;

	T& back() ;
	T& operator[](size_type i) ;
private:
	std::shared_ptr<std::vector<T> > data ;
	// 若data[i]无效，则抛出msg
	void check(size_type i , const std::string &msg)const  ;

};

template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()){ }

template< typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T> > (il)){ }
	

template <typename T>
void Blob<T>::check(size_type i , const std::string &msg) const {
	if(i >= data->size())
		throw std::out_of_range(msg) ;
}

template<typename T>
T& Blob<T>::back(){
	check(0,"back on empty Blob" ) ;
	return data->back() ;
}

template <typename T>
void Blob<T>::pop_back(){
	check(0,"pop_back on empty Blob") ;
	data->pop_back() ;
}

template< typename T>
T& Blob<T>::operator[](size_type i){
	check(i,"subscript out of range") ;
	return (*data)[i] ;
}



// 递归，尾递归

int fact(int n){
	if(n < 0)
		return 0 ;
	else if(n == 0 || n == 1)
		return 1 ;
	else {
		cout << n << endl;
		return n * fact(n - 1) ;
	}
}

int fact_tail(int n , int res = 1)
{
	if(n < 0)
		return 0 ;
	else if(n == 0 || n == 1)
		return res ;
	else {
		cout << n << "\t" << res << endl;
		return fact_tail(n - 1 , res * n) ; 
	}

}



// 行为像指针
class HasPtr{
	friend void swap(HasPtr& , HasPtr&) ;
public:
	HasPtr(const string &s = string()) : ps(new string(s)),
	i(0),use(new size_t(1)){ }
	HasPtr(const HasPtr &p) : ps(p.ps),i(p.i),use(p.use){ ++*use ;}
	HasPtr& operator=(const HasPtr& rhs) ;
	~HasPtr() {
		if(--*use == 0){
			delete ps ;
			delete use ;
		}
	}
private:
	string *ps ;
	int i ;
	size_t *use ; // record
};


HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use ;
	if(--*use == 0){
		delete ps ;
		delete use ;
	}
	ps = rhs.ps ;
	i = rhs.i ;
	use = rhs.use ;
	return *this ;

	/*
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this , rhs) ;
	return *this ; 
}

    ex :
    	a = b ;
	*/
}

inline 
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap ;
	swap(lhs.ps,rhs.ps) ;
	swap(lhs.i , rhs.i) ;
}


//Message Folder 

class Message ; 

class Folder{
private:
	std::set<Message *> Msg;
public:
	void remMsg(Message *m) {
		Msg.erase(m) ;
	}
	void addMsg(Message *m){
		Msg.insert(m) ;
	}
};



class Message{
	friend class Folder ;
	friend void swap(Message & , Message &) ;
public:
	explicit Message(const std::string &str = "") :
			 		contents(str){ }
	//拷贝控制成员，用来管理指向本Message的指针
	Message(const Message& ) ;
	Message& operator=(const Message&) ;
	~Message() ;

	// 从给定Folder集合中添加/删除本Message 
	void save(Folder&) ;
	void remove(Folder&) ;
private:
	std::string contents ; // 实际消息文本
	std::set<Folder*> folders ;
	// 包含指向本Message的Folder

	//公共的工具函数
	void add_to_Folders(const Message&) ;
	// 将本Message添加到指向参数的Folder总
	void remove_from_Folders() ; 
	// 从folders中的每个Folder中删除本Message 
};


void Message::save(Folder& f)
{
	folders.insert(&f) ;
	f.addMsg(this) ;
}
void Message::remove(Folder& f)
{
	folders.erase(&f) ; 
	f.remMsg(this) ;
}

void Message::add_to_Folders(const Message& m)
{
	for(auto f: m.folders)
		f->addMsg(this) ;
}

Message::Message(const Message &m):
	contents(m.contents), folders(m.folders)
	{
		add_to_Folders(m) ;
	}

void Message::remove_from_Folders()
{
	for(auto f : folders)
		f->remMsg(this) ;
}
Message::~Message()
{
	remove_from_Folders() ;
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders() ;
	contents = rhs.contents ;
	folders = rhs.folders ;
	add_to_Folders(rhs) ;
	return *this ;
}

void swap(Message &lhs , Message& rhs)
{
	using std::swap ;
	for(auto f : lhs.folders)
		f->remMsg(&lhs) ;
	for(auto f : rhs.folders)
		f->remMsg(&rhs) ;
	swap(lhs.folders , rhs.folders) ;
	swap(lhs.contents , rhs.contents) ;
	for(auto f : lhs.folders)
		f->addMsg(&lhs) ;
	for(auto f : rhs.folders)
		f->addMsg(&rhs) ;
}


int main(int argc, char const *argv[])
{

	vector<int> v ;
	fill_n(back_inserter(v),10,1) ;
	cout << v.size() ;
	cout << '\n' ;


	//lambda -> type 
	int lda = 3 ;
	auto ldaFun = [&]() -> bool { 
		if(lda){
			--lda ;
			return false ;
		}
		else 
			return true ;
	};
	while(1){
		cout << lda ;
		if(ldaFun()){
			cout << " is 0" << endl;
			break ;
		}
		else 
			cout << " is not 0" << endl ;
	}


	Blob<int> ia{1,2,3,4} ;
    return 0;
}

