
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

class Demo{
	int id ;
public:
	Demo(int i){
		id = i ;
		cout << "id=" << id  << " Constructed"<< endl ;
	}
	~Demo(){
		cout << "id=" << id << " Destructed" << endl ;
	}
} ;

Demo d1(1) ;
void Func(){
	static Demo d2(2) ;
	Demo d3(3) ;
	cout << "func" << endl ;
}



// Primer 6.7 函数指针 


string::size_type sumLength(const string &ls , const string &rs)
{
	cout << ls << "    " << rs << endl ;
	return ls.size() + rs.size()  ;

}

decltype(sumLength) *getFcn(const string &s)
{
	cout << s ; 
	return sumLength ; 
}

int func(int x , int y )
{
	return x + y ; 

}


//递归计算C(n,m)

int comm(int n , int m)
{
	if(m > n)
		return 0 ;
	else if(m == n || m == 0)
		return 1 ;
	else
		return comm(n - 1 , m ) + comm(n - 1 , m - 1) ;
}

void hanoi(int dim , int x , int y , int z)
{
	static int count  ;
	count++ ;
	if(dim == 1) {
		printf("%c to %c \n",x,z) ;
		printf("%d\n",count) ;
	}
	else {
		hanoi(dim - 1 ,x , z , y) ;
		printf("%c to %c \n",x , z) ;
		hanoi(dim - 1 ,y ,x , z) ;
	}
}



enum Day{Sun = 7 , Mon = 1 , Tue , Wed , Thu , Fri} ;
enum Level {Freshman , Sophomore , Junior , Senior} ;
enum Grade{ A , B , C , D } ;

class Student {
	
public :
	Student(unsigned number , Level lvl , Grade grd) :
	number(number) , level(lvl) , grade(grd) { } 
	void show() ;
private:
	unsigned number : 27 ;
	Level level : 2 ;
	Grade grade : 2 ;
};

void Student::show(){
	cout << "Number :    " << number << endl ;
	cout << "Level :     " ;
	switch(level){
		case Freshman : 
			cout << "freshman" ; break ;
		case Sophomore :
			cout << "sophomore" ; break ;
		case Junior : 
			cout << "junior" ; break ;
		case Senior :
			cout << "senior" ; break ;
	}
	cout << endl ;
	cout << "Grade :     " ;
	switch(grade){
		case A : 
			cout << "A" ; break ;
		case B :
			cout << "B" ; break ;
		case C : 
			cout << "C" ; break ;
		case D :
			cout << "D" ; break ;
	}
	cout << endl ;
}


 
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size() ;
}
string make_plural(size_t cstr, const string &word , const string &ending)
{
	//make_plural(wc, "word ", "s ")当输入中文本中,
	//word数大于一是在word后加s，为words为word的复数！
	return (cstr <= 1) ? word : word + ending ;
}

//先按字母序排序，然后使用稳定排序(即保持字母序)，按照单词长度排序
void elimDups(vector<string> &words)
{
	sort(words.begin() , words.end()) ;
	auto end_unique = unique(words.begin(), words.end()) ;
	words.erase(end_unique , words.end()) ;

	//删除从end_uniuqe至尾迭代器
	for(const auto &s : words)
		cout << s << "  " ; 
	cout << endl ;
}
void biggies(vector<string> &words, vector<string>::size_type sz , 
	ostream &os = cout , char c = ' ')
{
	elimDups(words) ;
	stable_sort(words.begin(),words.end(),isShorter) ;
	// wc 指向第一个长度不小于给定参数sz的元素
	auto wc = find_if(words.begin(),words.end(),
				[sz](const string &a){return a.size() >= sz ;});
	//auto wc = partition (words.begin(),words.end(),[sz]
	//(const string &a){return a.size() < sz ;});
	auto cnt = count_if(words.begin(),words.end(),[sz](const string &a)
						{return a.size() > sz ; }) ;


	auto count = words.end() - wc ;
	
	os << count << "  " << make_plural(count,"word","s")
		 << " of length " << sz << " or longer" << endl ;
	// make_plural  输出word or words 
	os << cnt << "  " << make_plural(cnt , "word","s") 
	   << " "	<< sz << "  longer" << endl ;

	// for_each 接受一个可调用对象，并对输入序列中每个元素调用此对象
	for_each(wc,words.end(),[&os,c] (const string &s) {os << s << c ;}) ;
	cout << endl ;
}


int main(int argc, char const *argv[])
{
	Demo d4(4) , d7(7);
	d4 = 6  ;
	cout << "main " << endl ;

	{Demo d5(5) ; 
	}
    Func() ;
    cout << "main end" << endl ;

    string::size_type (*pf)(const string & , const string &) ;
    pf = getFcn("dnf") ;
    pf("dnf","dnf") ;  // or (*pf)("dnf","dnf") ; 

    vector<int (*)(int , int)> vPtoFunc ;

    const Day j = Sun ;

    // Student 
    Student stu { 20142231 , Senior , A} ;
    cout << "Size of Student : " << sizeof(Student) << endl;
    stu.show() ;
    
    vector<string> word{"fox","jumps","over","quick","red",
						"red","slow","the","the","turtle"} ;
	biggies(word,6) ;

    return 0;
	
}

