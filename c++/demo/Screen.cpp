
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


class Screen ; //应该要提供Screen 类的前向引用说明

class Window_test{
	public :
		using Screentest = std::vector<Screen>::size_type ;
		void clear(Screentest i ) ;
		Screentest add(const Screen &s) ;
		void show(Screentest i) ;
	private :
		std::vector<Screen> screens ;
		//不能调用Screen 类自定义的构造函数，
		//因为此时还未定义Screen constructor

} ;


//Screen class 
typedef std::string::size_type pos ;
class Screen{

friend char show_screen(const Screen &lhs ,pos ht, pos wd);
friend class Window_mgr; //forward referencing is needless
friend void Window_test::clear(Screentest) ;
friend Window_test::Screentest Window_test::add(const Screen &s) ;
friend void Window_test::show(Screentest i) ;
public :

	// using pos = std::string::size_type ;		
	Screen() = default ;
	Screen(pos ht , pos wd ) :
	height(ht) , width(wd),contents(ht * wd , ' ') { }
	
	Screen(pos ht , pos wd ,char c) :
	height(ht),width(wd), contents(ht * wd , c){ }
	
	// opteration members 
	char get() const { return contents[cursor] ; }
	inline char get(pos ht, pos wd) const  ;
	
	Screen &move(pos ht, pos wd) ; 
	size_t some_member() const ;
	Screen &setc(char ) ;
	Screen &setc(pos , pos , char ) ;
	string getstr() const { return contents ;}

	Screen &display(std::ostream &os) 
		{do_display(os) ; return *this ;}
		//const成员函数可以访问非const对象的非const数据成员、const数据成员也可以访问const对象内的所有数据成员；
		//非const成员函数可以访问非const对象的非const数据成员、const数据成员，但不可以访问const对象的任意数据成员.
	const  // for return const class member .
	    Screen &display(std::ostream  &os) const
		    { do_display(os) ; return *this ;}


		// this pointer is passed implicitly when one 
		//member calls another .
		//returning a Screen reference can as a lvalue
		// so we concatenate a sequence of these actions
		//into a single expression .like this
		//myScreen.move(4,0).setc('4').display(cout) ;
private :
	//to do the actual work of printing the Screen 
	void do_display(std::ostream &os) const { os << contents ; } 
	
	pos cursor = 0 ; 
	pos height = 0 , width = 0 ;
	std::string contents ;

	// 即使在一个const对象内也能被修改
	mutable size_t access_ctr = 0 ;

} ;

inline Screen &Screen::move(pos ht , pos wd)
{
	pos row = ht * width ;
	cursor = row + wd  ;
	return *this ; //update the class 
}

char Screen::get( pos ht , pos wd ) const 
{
	pos row = ht * width ;
	return contents[row + wd] ;
}

inline size_t Screen::some_member() const
{
	return ++access_ctr ;
	std::cout << access_ctr ;
}

inline Screen &Screen::setc(char c)
{
	contents[cursor] = c ;
	return *this ;
}

inline Screen &Screen::setc(pos r , pos col , char ch )
{
	contents[r * width + col ] = ch ;
	return *this ;
}
/*
	move and setc also return a reference to the object
	on which they are called .Functions that return a 
	reference are lvalues, which means that they 
	return the object itself, not a copy of the object.
	so if we concatenate sequence of these
	actions into a single expression :
	myScreen.move(4,2).set('@') ;
	these operations will execute on the same object .
*/


//function declaration 
	

	char show_screen(const Screen &lhs, pos ht , pos wd) ; 



// window manager class , need under class Screen 
class Window_mgr{
	public :
		using ScreenIndex = std::vector<Screen>::size_type ;
		void clear(ScreenIndex) ;
		Window_mgr& add(Screen &s) { screens.push_back(s) ; return *this ;}
		Window_mgr& show(ScreenIndex i) { do_show(i) ; return *this ;}
		const Window_mgr& show(ScreenIndex i) const { do_show(i) ; return *this ;}

	private :
		//std::vector<Screen> screens{Screen(24,80,' ') } ;
		std::vector<Screen> screens { Screen(24, 80,' ') } ;
		void do_show(ScreenIndex i)  const { screens[i].display(cout) ;}

} ;



int main(int argc, char const *argv[])
{


    return 0;
}



char show_screen(const Screen &lhs , pos ht , pos wd)
{
	unsigned count = 0 ;
	for(auto ch : lhs.contents){
		cout << ch ;
		count++ ;
		if(count % ht == 0)
			cout << '\n' ;	
	}
	size_t idx = lhs.cursor ;
	return (lhs.contents)[idx] ;
}

void Window_test::clear(Screentest i) 
{
	Screen &s = screens[i] ;
	s.contents = string(s.height * s.width , '0') ; //显示修改操作效果
}

Window_test::Screentest Window_test::add(const Screen &s) 
{
 screens.push_back(s) ;
 return screens.size() - 1;
}
void Window_test::show(Screentest i) 
{
	 std::cout << screens[i].getstr() ; 
}
void Window_mgr::clear(ScreenIndex i) 
{
	Screen &s = screens[i] ;
	s.contents = string(s.height * s.width , ' ') ;
}


