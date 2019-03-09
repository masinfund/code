// Life is limited while learning is limitless, 
//limiting life chasing endless learning until die .

#include "stdafx.h"
 // io mainpulator 
const int  MAXLINE = 1000 ; // maximum input line szie 
const double PI = 3.14159265358979 ;
const int N(100) ;
const int row(92) ;
int cnt ;
//Clock class

class Clock{
			public:
					Clock() ;
					Clock(int newH,int newM, int newS) ; // constructor function
			public :
					void setTime(int newH = 0, int newM = 0 , int newS = 0);
					void showTime() const ;
					Clock& operator ++() ; // 前置重载
					Clock   operator ++(int ) ; // 后置重载
			private:
					int hour , minute , second ;
		};

Clock::Clock(int newH, int newM , int newS) :
	hour(newH) , minute(newM), second(newS){}
Clock::Clock() : hour(0), minute(0) , second(0) {}

void Clock::setTime(int newH, int newM , int newS )
{
	hour = newH ;
	minute = newM ;
	second = newS ;
}
inline void Clock::showTime() const 
{
	cout << hour << ":" << minute << ":" << second <<endl ; 
}

Clock& Clock::operator ++() {
	second++ ;
	if(second >= 60){
		second -= 60 ; minute++ ;
		if(minute >= 60) {
			minute -= 60 ; hour = (hour + 1) % 24 ;
		}	
	}
	return *this ;
}

Clock Clock::operator ++(int ) {
	Clock old = *this ;
	++(*this) ; // 调用前置运算符重载 
	return old ;
}



//Sales_data

class Sales_data{	
public : 
	friend Sales_data add(const Sales_data & , const Sales_data&) ;
	friend std::istream &read(std::istream&, Sales_data&) ;
	friend std::ostream &print(std::ostream&, const Sales_data&) ;
	friend std::istream& operator>>(std::istream& in , Sales_data& s);
	friend std::ostream& operator<<(std::ostream& out , const Sales_data& s) ;
	friend bool operator <(const Sales_data& lhs , const Sales_data& rhs) ;
	friend bool operator >(const Sales_data& lhs , const Sales_data& rhs);
	friend bool operator ==(const Sales_data& lhs , const Sales_data& rhs) ;

	//constructors
	Sales_data() = default ;
	explicit Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s , unsigned n , double p) : bookNo(s) , units_sold(n) , revenue( p * n ) { }
	Sales_data(std::istream &is ) ;
	// = std::cin ;
	//Sales_data() : Sales_data("",0,0) { }   委托构造函数
	//Sales_data(std::istream &is ) : Sales_data() {read(is,*this) ;}
	//接受istream&的构造函数委托给
	

	std::string isbn() const { return bookNo ;}
	Sales_data& combine(const Sales_data &) ;
	double avg_price() const ;

//operations on Sales_data objects 

	Sales_data& operator +=(const Sales_data& s) ;
	Sales_data& operator =(const Sales_data& s); 

private :
	std::string bookNo ; // implicitly initialized to the empty string
	unsigned units_sold = 0 ; // explicitly initialized 
	double revenue = 0.0 ;		
};

Sales_data::Sales_data(std::istream &is ) 
{
	read(is,*this) ;
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold ;
	revenue += rhs.revenue ;
	return *this ;
}

double Sales_data::avg_price() const {
	if(units_sold){
		return revenue / units_sold ;
	}
	else 
		return 0 ;
}

Sales_data& Sales_data::operator =(const Sales_data& s)
{
	return *this ;
}

// 接口函数必须重声明 
Sales_data add(const Sales_data & , const Sales_data&) ;
std::istream &read(std::istream&, Sales_data&) ;
std::ostream &print(std::ostream&, const Sales_data&) ;
std::istream& operator>>(std::istream& in , Sales_data& s);
std::ostream& operator<<(std::ostream& out , const Sales_data& s) ;
bool operator <(const Sales_data& lhs , const Sales_data& rhs) ;
bool operator >(const Sales_data& lhs , const Sales_data& rhs);
bool operator ==(const Sales_data& lhs , const Sales_data& rhs) ;

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) 
{
	Sales_data sum = lhs ;
	sum.combine(rhs) ;
	return sum ;
}

Sales_data& Sales_data::operator+=(const Sales_data& s) 
{
	units_sold += s.units_sold ;
	revenue += s.revenue ;
	return *this ;
}

Sales_data 
operator +(const Sales_data& lhs , const Sales_data& rhs){
	Sales_data ret(lhs); // copy lhs into a local object 
	ret += rhs ;
	return ret ;
}

std::istream &read(std::istream& is , Sales_data& rhs)
{
	double price  ;
	is >> rhs.bookNo >> rhs.units_sold >> price ;
	if(is)
		rhs.revenue = rhs.units_sold * price ;
	else
		rhs = Sales_data() ; // 输入失败;对象被赋予默认的状态
	return is ;
}

std::istream&
operator >>(std::istream& in , Sales_data& s) {
	return read(in,s) ;
}


std::ostream& print(std::ostream& os , const Sales_data& rhs)
{
	os << rhs.isbn() << "  " <<  rhs.units_sold
	   << "  " <<  rhs.revenue << "  " << rhs.avg_price() ;
	 return os ;
}

std::ostream&
operator <<(std::ostream& out , const Sales_data& s)
{
	return print(out , s) ;
}



//Person class 
struct person{
	private:
		// data member 
		std::string name ;
		std::string address ;
	public :
		//constructor member
	  person() = default ;
		person(const std::string &lhs ,const std::string &rhs) : name(lhs) , address(rhs) {}
		person(std::istream &is) 
		{
			is >> this->name >> this->address ;
		}

		// func member 
		std::vector<string> per_message() const 
		{ return {name,address} ;  }
		std::string per_name() const 
		{ return name ;}
		std::string per_ddress() const 
		{ return this->address ;}

} ;


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
		char get(pos ht, pos wd) const  ;
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
		void do_display(std::ostream &os) 
		const { os << contents ; } 
		//
		pos cursor = 0 ; 
		pos height = 0 , width = 0 ;
		std::string contents ;
		mutable size_t access_ctr = 0 ;
} ;

inline 
Screen &Screen::move(pos ht , pos wd)
{
	pos row = ht * width ;
	cursor = row + wd  ;
	return *this ; //update the class 
}

inline 
char Screen::get( pos ht , pos wd ) const 
{
	pos row = ht * width ;
	return contents[row + wd] ;
}

inline
size_t Screen::some_member() const
{
	return ++access_ctr ;
	std::cout << access_ctr ;
}

inline
Screen &Screen::setc(char c)
{
	contents[cursor] = c ;
	return *this ;
}

inline 
Screen &Screen::setc(pos r , pos col , char ch )
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
	static int PlaceQueen[row][N] ;
	static int board[N][N] ;
	void putqueen(int Queen) ;
	void queen(void) ;
	bool check(int row , int column) ;
	// mathTest class member 
	double fact(int n , int num = 1) ;
	double NaturalNumber(int x ) ;
	int maxSubSum(const vector<int> & a) ;


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



class ExamInfo{
	public :
		ExamInfo() : name("test") , mode(PASS),pass(pass) {}
		ExamInfo(string name , char grade) : name(name) ,mode(GRADE),grade(grade){ }
		ExamInfo(string name , bool pass) : name(name) ,mode(PASS),pass(pass) { }
		ExamInfo(string name , int percent) : name(name),mode(PERCENTAGE) , percent(percent) { }		
	public :
		void show() ;
	private :
	string name ;
	enum {
			GRADE , PASS , 
			PERCENTAGE 
	} mode ;
	union {
		int percent ;
		char grade ;
		bool pass ;
	} ;
} ;

void ExamInfo::show() 
{
	cout << name << ": " ;
	switch(mode) {
		case GRADE : cout << grade ;		break ;
		case PASS : cout << (pass ? "PASS" : "FAIL") ;       break ;
		case PERCENTAGE  : cout << percent ;     break ;
	}
	cout << endl ;
}


class ArrayOfExamInfos {
	public :
		ArrayOfExamInfos(int size ) : size(size) { 
		ExamInfos = new ExamInfo[size] ;

		}
		~ArrayOfExamInfos() {
			cout << "Deleting..." << endl ;
			delete []ExamInfos ;
		}
		ExamInfo &element(int index) {
			assert(index >= 0 && index < size) ;
			return ExamInfos[index] ;
		}

	private :
		ExamInfo  *ExamInfos ; 
		int size ;
};

//派生类 


class CreditAccount : public Account {
	private :
		double acc ; // 利息累加器
		double credit ;  // 信用额度
		double rate ; 	// 日利率 
		double fee  ;  // 年费
		double getDebt() const ;
	public :
		CreditAccount(const Date &date , const std::string &id , double credit , double rate , double fee) ;
		double getCredit() const ;
		double getRate() const ;
		double getFee() const ;
		double getAvailableCredit() ;
		void deposit(const Date &date , double amount , const std::string &desc) ;
		void withdraw(const Date &date , double amount , const std::string &desc) ;
		void settle(const Date &date) ;
		void show() const ;
} ;


class Employee {
	public :
	Employee(const string &name , const string &ssn) ;
	const string& get_name() const ;
	void print(std::ostream& out ) const ;
	void print(std::ostream& out , const string &msg) const ;
	protected :
		string m_name ;
		string m_ssn ;
} ;

Employee::Employee(const string &name , const string &ssn)
				  : m_name(name) , m_ssn(ssn) 
{
	// initializer list sets up the values !
}

inline const string& Employee::get_name() const 
{
	return m_name ;
}

inline void Employee::print(std::ostream& out ) const 
{
	out << m_name << '\n' << m_ssn << endl ;
}

inline void Employee::print(std::ostream& out , const string &msg) const 
{
	out << msg << endl ;
	print(out) ; // avoid code duplication 
}



class Manager : public Employee {
	public :
	Manager(const string &name , const string &ssn , const string &title) ;
	const string title_name() const ;
	const string& get_title() const ;
	void print(std::ostream& out) const ;
	private :
		string m_title ;
} ;

Manager::Manager(const string &name , const string &ssn , const string &title): Employee(name,ssn) , m_title(title) {}
inline void Manager::print(std::ostream& out) const 
{
	Employee::print(out) ; // call the base class func member
	out << m_title << endl ;
}

inline const string& Manager::get_title() const 
{
	return m_title ;
}

inline const string Manager::title_name() const 
{
	return string(m_title + ": " + m_name) ;
}





class A {
	public :
		A() : i(0) { p = 0 ; cout << "A::A() " << endl; } 
		~A() { if(p) delete p ; cout << "A::~A() " << i << endl ;}
		void new_p() { p = new int ;}
		void print() { cout << "A：：" << i << endl ;}
		void print(int i ){ cout << i ; print() ; }
		void fun(A *q) { cout << "A::fun() , q->i = " << q->i << endl ;}
	//protected : 
		void set(int i) { this->i = i ;}

	private :
		int i ;
		int *p ;
} ;

class B : public A{
	public :
		int c ;
		void f() { set(20) ; print() ;}
		print() {cout << "B::print()" << endl ;}
		void print(int i ) { A::print(i) ;}
} ;


class Complex {
public :
	friend ostream& operator <<(ostream &out , const Complex &c) ;
	friend istream& operator >>(istream &in , Complex &c) ;
	friend Complex operator *(const Complex &c1 , const Complex &c2) ;
	

	Complex(const Complex &) ;
	Complex(double r = 0.0 , double i = 0.0) : real(r) , imag(i) { }
	
	//运算符重载
	Complex operator +(const Complex &c2) const ;
	Complex operator -(const Complex &c2) const ;
	Complex& operator =(const Complex &c2) ;
	void display() const ;
private :
	double real ;
	double imag ;
} ;

inline Complex::Complex(const Complex &c) : real(c.real) , imag(c.imag) {}

ostream& operator <<(ostream &out , const Complex &c) ;
istream& operator >>(istream &in , Complex &c) ;
Complex operator *(const Complex &c1 , const Complex &c2) ;

ostream & operator <<(ostream &out , const Complex &c) 
{
	out << "(" << c.real << " , " << c.imag << ")" ;
	return out ;
}

istream& operator >>(istream &in , Complex &c)
{
	in >> c.real >> c.imag ;
	return in ;
}

Complex operator *(const Complex &c1 , const Complex &c2)
{
	return Complex(c1.real * c2.real - c1.imag * c2.imag , 
				   c1.real * c2.imag + c1.imag * c2.real) ;
}

Complex&
Complex::operator=(const Complex &c2){
	real = c2.real ;
	imag = c2.imag ;
	return *this;
}

Complex Complex::operator +(const Complex &c2) const {
	
	return (Complex(real + c2.real , imag + c2.imag)) ;
}
// const Complex * const this ;
Complex Complex::operator -(const Complex &c2) const {
	return Complex(real - c2.real , imag - c2.imag) ;
}
void Complex::display() const {
	cout << "(" << real << " , " << imag << ")" << endl ;
}




	class Base1 {
		public :
		virtual void display() const = 0 ; // 纯虚函数

	} ;
	//具体实现不应该写入类体中，写入类体中会被作为内联函数在编译阶段嵌入
	//具体的代码中去。

	class Base2 : public Base1 {
		public :
		virtual void display() const ;
	} ;
	void Base2::display() const {
		cout << "Base2::display() " << endl ;
	}
	class Derived : public Base2 {
	public :
		virtual void display() const ;
	} ;
	void Derived :: display() const {
		cout << "Derived ::display() " << endl ;
	}
	void fun(Base1 &p) {
		p.display() ;
	}


template <typename T>
T abs(T x) 
{ 
	return x < 0 ? -x : x ;
}

template <class T >
void putArr(const T *arr , int cnt) 
{
	for(int i = 0 ; i < cnt ; ++i)
		cout << arr[i] << "  " ;
	cout << endl ;
}



struct Stu{
	int id ;
	double gpa ;
} ;

template <class T>
class Store{
	private :
	T item ;
	bool flag ;
	public :
	Store() ;
	T& getElem() ;
	void putElem(const T &x) ;
};

template <class T>
Store<T>::Store() : flag(false) { }

template <class T>
T &Store<T> :: getElem() {
	if(!flag){
		cout << "No item present !" << endl ;
		exit(EXIT_FAILURE) ;
	}
	return item ;
}

template <class T>
void Store<T>::putElem(const T &x)
{
	flag = true ;
	item = x ;
}


template <class T>
class Array{
	private :
		T *list ;
		int size ;
	public :
		Array(int sz = 100) ;
		Array(const Array<T> &a) ;
		~Array() ;

		Array<T> & operator = (const Array<T> &rhs) ;
		T & operator [](int i) ;
		const T &operator [](int i ) const ;
		operator T* () ;
		operator const T*() const ;
		int getSize() const ;
		void resize(int sz) ;
};

template <class T>
Array<T>::Array(int sz)  { 
	assert(sz >= 0) ;
	size = sz ;
	list = new T [size] ;
}

template <class T>
Array<T>::~Array() {
	delete []list ;
}

template <class T>
Array<T>::Array(const Array<T> &a) {
	size = a.size ;
	list = new T[size] ;
	for(int i = 0 ; i != a.size ; ++i)
		list[i] = (a.list)[i] ;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T> &rhs)
{
	/*重载 = , 将对象rhs赋值给本对象， 实现对象之间的整体赋值*/
	if(&rhs != this ) {
		if(size != rhs.size) {
			delete []list ;
			size = rhs.size ;
			list = new T[size] ;
		}
		for(int i = 0 ;i != size ; ++i)
			list[i] = rhs.list[i] ;
	}
	// 返回当前对象的引用
	return *this ;
}

template <class T>
T & Array<T>::operator [](int i )
{
	assert( i >= 0  && i < size ) ;
	return list[i] ;
}

template <class T>
const T& Array<T>::operator [](int i) const {
	assert(i >= 0 && i < size ) ;
	return list[i] ;
}


// 重载指针转换运算符 ， 将Array类的对象名转换为T类型的指针
template <class T>
Array<T>::operator T*() {
	return list ;
}

template <class T>
Array<T>::operator const T*() const {
	return list ;
}


template <class T>
int Array<T>::getSize() const {
	return size ;
}

template <class T>
void Array<T>::resize(int sz)
{
	assert(sz >= 0) ;
	if(sz == size )
		return ;
	T *tmp = new T[sz] ;
	for(int i = 0 ; i != size ; ++i)
		tmp[i] = list[i] ;
	delete []list ;
	list = tmp ;
	size = sz ;
	tmp = nullptr ;
}



//node template 
template <class T>
class Node {
private:
	Node<T> *next ;
public:
	T data ;
	Node(const T& item , Node<T> * next = 0) ;
	void insert(Node<T> *p) ;
	Node<T> *deleteAfter() ;
	Node<T> *nextNode() ;
	const Node<T> *nextNode() const ;
} ;

template <class T>
Node<T>::Node(const T& item , Node<T> *next ) :
			 data(item){this->next = next ; }

template <class T>
Node<T>* Node<T>::deleteAfter()
{
	Node<T> *tmp = next ;
	if(!next)
		return nullptr  ;
	
	next = tmp->next ;
	return tmp ;

}

template <class T>
void Node<T>::insert(Node<T> *p)
{	p->next = next ;
	next = p ;
}

template <class T>
Node<T> *Node<T>::nextNode() 
{
	return next ;
}

template <class T>
const Node<T> *Node<T>::nextNode() const {
	return next ;
}



template <class T>
class LinkList{
	private :
		Node<T> *front , *rear ;
		Node<T> *pre, *cur ;
		int size ;
		int position ; // 记录当前元素在表中的位置序号
		Node<T> *newNode(const T& item , Node<T> *ptrnext = nullptr) ;
		void freeNode(Node<T> *p) ;
		void copy(const LinkList<T> &L) ;
	public :
		LinkList() ;
		LinkList(const LinkList<T> &L) ;
		~LinkList() ;
		LinkList<T> &operator = (const LinkList<T> &L) ;
		int getSize() const ;
		bool isEmpty() const ;
		void reset(int pos = 0) ;
		void next() ;
		bool endOfList() const ;
		int curPos() const ;

		void insertFront(const T &item) ;
		void insertRear(const T &item) ;
		void insertAt(const T& item) ;
		void insertAfter(const T &item) ;
		T deleteFront() ;
		void deleteCur() ;
		T& data() ;
		const T& data() const ;
		void clear() ;
} ;

template <class T , int SIZE = 50>
class Stack{
	private :
		T list[SIZE] ;
		int top ;
	public:
		Stack() ;
		void push(const T &item) ;
		T pop() ;
		void clear() ;
		const T &peek() const ;
		bool isEmpty() const ;
} ;


template <class T , int SIZE>
Stack<T,SIZE>::Stack() : top(-1) { }

template <class T , int SIZE>
void Stack<T,SIZE>::push(const T& item)
{
	assert(isEmpty()) ;
	list[++top] = item ;
}

template <class T , int SIZE>
T Stack<T,SIZE>::pop(){
	assert(!isEmpty()) ;
	return list[top--] ;
}

template <class T , int SIZE>
const T& Stack<T,SIZE>::peek() const
{
	assert(!isEmpty()) ;
	return list[top] ;
	
}

template <class T , int SIZE>
bool Stack<T,SIZE>::isEmpty() const 
{
	return top == -1 ;
}

template <class T , int SIZE>
void Stack<T,SIZE>::clear()
{
	top = -1 ;
}


class Calculator{
	private :
		Stack<double> s ;
		void Enter(double num) ;
		bool getOperands(double &opnd1 , double &opnd2) ;
		void compute(char op) ;
	public :
		void run() ;
		void clear() ;
} ;


inline double stringTodouble(const string &str)
{
	istringstream stream(str) ;
	double result ;
	stream >> result ;
	return result ;
}

void Calculator::Enter(double num) {
	s.push(num) ;
}

bool Calculator::getOperands(double &opnd1, double &opnd2){
	if(s.isEmpty()){
		cerr << "Missing operand!" << endl ;
		return false ;
	}
	opnd1 = s.pop() ;
	if(s.isEmpty()){
		cerr << "Missing operand !" << endl ;
		return false ;
	}
	opnd2 = s.pop() ;
	return true ;
}

void Calculator::compute(char op) {
	double opnd1 , opnd2 ;
	if(getOperands(opnd1,opnd2)){
		switch(op) {
			case '+' :
				s.push(opnd2 + opnd1) ;        break ;
			case '-' :
				s.push(opnd2 - opnd1) ;		   break ;
			case '*' :
				s.push(opnd2 * opnd1) ; 	   break ;
			case '/' :
				if(!opnd1){
					cerr << "Divided by 0 !" << endl ;
					s.clear() ;
				}
				else 
					s.push(opnd2 / opnd1) ;	   break ;
			case '^' : 
				s.push(pow(opnd2,opnd1)) ;	   break ;
			
			default :
				cerr << "unrecognized operator !" << endl ;
				break ;
		}
		cout << " = " << s.peek() << " " ;
	}
	else 
		s.clear() ;
}

void Calculator::run() {
	string str ;
	while(cin >> str , str != "q"){
		switch(str[0]){
			case'c' : s.clear() ; 			break ;
			case '-' : 
				if(str.size() > 1)
					Enter(stringTodouble(str)) ;
				else 
					compute(str[0]) ;
				break ;
			case '+' :
			case '*' :
			case '/' :
			case '^' :
				compute(str[0]) ;
			default :
				Enter(stringTodouble(str)) ;
				break ;
		}
	}
}

void Calculator::clear() {
	s.clear() ;
}

double square(double x) {
	return x * x ;
}


template <class T , class InputIterator , class OutputIterator >
void mySort(InputIterator first , InputIterator last , OutputIterator result)
{
	vector<int> s ;
	while(first != last){
		s.push_back(*first++) ;
	}
	sort(s.begin() , s.end() );
	copy(s.begin() , s.end() , result) ;

}

template <class T>
void printContainer(const char *msg , const T& s) {
	cout << msg << ": " ;
	copy(s.begin(),s.end() ,ostream_iterator<int>(cout," ")) ;
	cout << endl ;
}

int sum (const vector<int> &v , int low , int high)
{
	if(low == high)
		return v[low] ;
	else {
		int mid = (low + high) >> 1 ;
		return sum(v,low,mid) + sum(v,mid + 1,high) ;
	}
}
  
void elimDups(vector<string> &words)
{
	sort(words.begin(),words.end()) ;
	// unique 重排输入范围使得每个单词只出现一次排列在范围的前部，
	//返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(),words.end()) ;
	words.erase(end_unique,words.end()) ;
}
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size() ;
}

string make_plural(size_t cstr, const string &word , const string &ending)
{
	return (cstr == 1) ? word : word + ending ;
}

void biggies(vector<string> &words, vector<string>::size_type sz , ostream &os = cout , char c = ' ')
{
	elimDups(words) ;
	stable_sort(words.begin(),words.end(),isShorter) ;
	// wc 指向第一个长度不小于给定参数sz的元素
	auto wc = find_if(words.begin(),words.end(),
				[sz](const string &a){return a.size() >= sz ;});

	auto count = words.end() - wc ;
	os << count << "  " << make_plural(count,"word","s")
		 << " of length " << sz << " or longer" << endl ;
	// make_plural  输出word or words 

	// for_each 接受一个可调用对象，并对输入序列中每个元素调用此对象
	for_each(wc,words.end(),[&os,c] (const string &s) {os << s << c ;}) ;
	cout << endl ;
}

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


class Word_transform
{

	public :
	void word_transform(ifstream &map_file , ifstream &input) ;
	map<string, string> buildMap(ifstream &map_file) ;
	const string &transform(const string &s , 
					const map<string,string> &m) ;
} ;
const string &Word_transform::transform(const string &s , 
					const map<string,string> &m) 
{
	auto map_itor = m.find(s) ;
	if(map_itor != m.cend())
		return map_itor->second ;
	else 
		return s ;
}
map<string, string> Word_transform::buildMap(ifstream &map_file) 
{
	map<string , string>trans_map ;
	string key ;
	string value ;
	//读取第一个单词存入key , getline读取行中剩余内容存入value 
	while(map_file >> key && getline(map_file,value))
		if(value.size() > 1)
			trans_map[key] = value.substr(1) ;
		else 
			throw runtime_error("no rule for " + key) ;
	return trans_map ;
}
void Word_transform::word_transform(ifstream &map_file , ifstream &input)
{
	auto trans_map = buildMap(map_file) ;
	string text ;
	while(getline(input,text)) {
		istringstream stream(text) ;
		string word ;
		bool firstword = true;
		while(stream >> word) {
			if(firstword)
				firstword = false ;
			else 
				cout << " " ;
			cout << transform(word,trans_map) ;
		}
		cout << endl ;
	}
}

class test {
	void do_print() const ;
	vector<int> *p ;
public :
	
	test() ;
	~test() ;
	test &print() ;
	const test &print() const ;
	test &read() ;

} ;
void test::do_print() const {
	for(auto x : *p)
		cout << x << "  " ;
	cout << endl ;
}

test &test::print() {
	do_print() ;
	return *this ;
}
	
const test &test::print() const {
	do_print() ;
	return *this ;
}

test::~test(){
	delete p ;
	cout << "destructor" << endl ;
}
test &test::read(){
	int tmp ;
	while(cin >> tmp)
		p->push_back(tmp) ;
	return *this ;
}

test::test() {
	p = new vector<int> ;
	cout << "constructor" << endl ;
}


class IntCell {
public :
	explicit IntCell(int initialValue = 0) ;
	IntCell(const IntCell &rhs) ;
	~IntCell() ;
	const IntCell &operator=(const IntCell &rhs) ;
	int read() const ;
	void write(int x) ;
private :
	int *storedValue ;
} ;

IntCell::IntCell(int initialValue){
	storedValue = new int(initialValue) ;
}
IntCell::IntCell(const IntCell &rhs)
{
	storedValue = new int(*rhs.storedValue) ;
}
IntCell::~IntCell() {
	delete storedValue ;
}

const IntCell &IntCell::operator=(const IntCell &rhs){
	if(this != &rhs){
		*storedValue = *rhs.storedValue ;
	}
	return *this ;
}

void IntCell::write(int x){
	*storedValue = x ;
}



void visit(int &v , int a) {
	v *= a ;
	cout << v << " " ;
}


/*
template <typename T , typename VST>
void vector<T>::traverse(VST &visit){
	visit() ;
}
*/

void foo5(int (*c)[5],int n) ;
void foo4() ;
void foo(int n) ;
void foo1() ;
void foo2() ;
void foo3(int n) ;
void inplace_swap(int &x , int &y) ;
void heart() ;
float heart_h(float x , float z);
float heart_f(float x , float y , float z);

template <unsigned n , unsigned m>
int compare(const char (&p)[n], const char (&q)[m])
{	//使用字面量的大小来代替n and m .
	return strcmp(p,q) ;
}
int strcm(const char *p1 , const char *p2){
	assert(p1 && p2) ;
	while(*p1++ == *p2++ )
		; 
	return *p1 - *p2 ; 
}

void convert(Stack<char> &s , int n , int base = 2)
{
	//十进制n到base进制的转换
	static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;
	if( n > 0){
		convert(s , n / base , base) ;
		s.push(digit[n % base]) ;
	}
	//新进制由高到底各位，自顶而下保存于栈中
	/*迭代版
	while( n > 0){
		int rem = n % base ;
		s.push(digit[rem]) ;
		n /= base ;
	}
	*/
}

void num_reverse(int number) {

	/*
	int res = 0 ;
	while(number){
		res = res * 10 + number % 10 ;
		number /= 10 ;
	}
	cout << ((res < INT_MIN || res > INT_MAX) ? 0 : res ) << endl ;
	*/

	int  flag = 1 ;
	while(number){
		if(number < 0){
			cout << '-' ;
			number *= -1 ;
		}
		if(number % 10 == 0 && flag ){
			flag = 0 ;
			number /= 10 ;
		}
		else{
			cout << number % 10 ;
			number /= 10 ;
		} 
	}
	cout << endl ;
}


int main(int argc , const char **argv)
{
	clock_t start ,end; // 毫秒级
	start = clock() ;

	LARGE_INTEGER cpuFreq ;
	LARGE_INTEGER startTime ;
	LARGE_INTEGER endTime ;
	double runTime = 0.0 ;
	QueryPerformanceFrequency(&cpuFreq) ;
	QueryPerformanceCounter(&startTime) ;




	char csx ;
	cin >> csx ;
	cout << csx ;

	


	int col_a[7][7] ;
	for(int j = 0 ; j != 7 ; ++j){
		for(int (*p)[7] = col_a ; p != &*(col_a + 7) ; ++p){
			(*p)[j] = rand() % 2  ;
			cout << setiosflags(ios::left) << setw(3) << (*p)[j] ;
		}
		cout << '\n' ;
	}
	cout << endl ;
	for(int i = 0 ; i != 7 ; ++i){
		for(int j = 0 ; j != 7 ; ++j){
			/*code*/
			cout << setiosflags(ios::left) << setw(3) << col_a[i][j] ;
		}
		cout << '\n' ;
	}

	cout << endl ;
	
	typedef int (*funptr)(double) ;











	vector<vector<int> > v {{1,2,3},{2,3,4}} ;
	for(auto a = v.begin() ; a != v.end() ;a++)
		for(auto x : *a)
			cout << x << "  " ;
	cout << endl ;


	int arr[2][2]; // const int (*arr)[2] 
	int (*p)[2] = begin(arr) ;
	int (*q)[2] = std::end(arr) ;
	int i = 0 ;
	int *tmp = *p ;
	while(tmp != *q) {
		*tmp = 4 ;
		cout << *tmp++ << " " ; 

	}
	fill_n(*begin(arr),1,9) ;
	cout << '\n' ;
	cout << typeid(arr).name() << endl ;
	for(auto &c : arr){
		for(auto x : c){
			cout << x << " " ;
			cout << typeid(x).name() << " " ;
		}
		cout << typeid(c).name() << endl ;
	}
	cout << endl ;
	fill(*begin(arr),*std::end(arr),7) ;
	for(auto &a : arr)
		for(auto v : a)
			cout << v << " " ;
	cout << endl ;


	allocator<string> alc ;
	const auto p1 = alc.allocate(4) ;
	cout << typeid(p1).name() << endl ;







	Complex r(2,4) ,r1 ;
	r1 = 5 * r ;
	cout << r1 << endl ;

	r1 = r ;
	cout << r1 << endl ;

	Clock C(16,24,56) ;
	cout << "First time output : " ;
	C.showTime() ;
	cout << "Show Clock++ : " ;
	(C++).showTime() ;
	cout << "Show ++Clock : " ;
	(++C).showTime() ;

	Sleep(1000) ; // windows.h ,以毫秒为单位
	end = clock() ;
	QueryPerformanceCounter(&endTime) ;
	runTime = (((endTime.QuadPart - startTime.QuadPart) * 1000.0f) / cpuFreq.QuadPart) ;
	cout << "Use time is " << end - start << "(ms)" << endl ;
	cout << "Use time is " << runTime << "(ms)" << endl ;



	return 0 ;

}


void foo5(int (*c)[5] , int n ) {
	//二维数组翻转90度
	for(int i = 0 ; i != n / 2 ; ++i){
		for(int j = i ; j != 4 - i ; ++j){
			int tmp = c[j][4 - i] ;
			c[j][4 - i] = c[i][j] ;
			c[i][j] = tmp ;
			tmp = c[4 -i ][4 - j] ;
			c[4 - i][4 - j] = c[i][j] ;
			c[i][j] = tmp ;
			tmp = c[4 - j][i] ;
			c[4 - j][ i] = c[i][j] ;
			c[i][j] = tmp ;
		}
	}
	
}

void foo4()
{
	map<string , size_t> word_count ; // string 到size_t上的空map
	set<string> exclude = {"The","But","And","or"} ;
	string word ;
	while(cin >> word){
		if(exclude.find(word) == exclude.end())
			++word_count[word] ;
	}
	for(const auto &w : word_count)
		cout << w.first << "occurs" << w.second 
		     << ((w.second > 1) ? " times" : " time") << endl ;
}

float heart_f(float x , float y , float z)
{
	float a = x * x + 9.0f / 4.0f * y * y + z * z  - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z ;
}
float heart_h(float x , float z)
{
	for(float y = 1.0f ; y >= 0.0f ; y -= 0.001f)
		if(heart_f(x,y,z) <= 0.0f)
			return y ;
	return 0.0f ;
}
void heart()
{
	for(float z = 1.5f ; z > -1.5f ; z -= 0.1f) {
		for(float x = -1.5f ; x < 1.5f ; x += 0.025f) {
			float v = heart_f(x , 0.0f , z) ;
			if(v <= 0.0f){
				float y0 = heart_h(x , z) ;
				float ny = 0.01f ;
				float nx = heart_h(x + ny , z) - y0 ;
				float nz = heart_h(x , z + ny) - y0 ;
				float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz ) ;
				float d = (nx + ny - nz) * nd * 0.5f + 0.5f ;
				putchar(".:-=+*#%@"[(int)(d * 5.0f)]) ;
			}
			else
				putchar(' ') ;
		}
		putchar('\n') ;
	}

}
void inplace_swap(int &x , int &y) 
{
	y = x ^ y ; // 0011 ^ 0101 = 0110
	x = x ^ y ;
	y = x ^ y ;
}




void foo3(const int v)
{

	int a[N][N] = {0} , tot , x = 0 , y = v - 1 ;
	tot = a[x][y] = 1 ;
	while(tot < v * v){
		while(x < v - 1  && !a[x + 1][y])
			a[++x][y] = ++tot ;
		
		while(y > 0 && !a[x][y - 1])
			a[x][--y] = ++tot ;
		
		while(x > 0 && !a[x - 1][y])
			a[--x][y] = ++tot ;
		
		while(y < v - 1 && !a[x][y + 1])
			a[x][++y] = ++tot ;
	}
	for(int i = 0 ; i != v ; ++i){
		for(int j = 0 ; j != v ; ++j){
			cout << setw(4) <<  a[i][j] << " " ;
		}
		cout << endl ;
	}
}


void foo2()
{

	/* 	1,2,3,4,5,6,7,8,9 only use the 9 numbers , no-repeat
		output all 
		abc def ghi = 1 : 2 : 3 
		ex : 192 384 576 
				...
	*/
	stringstream s ;
	string str ;
	string ch = "123456789" ;
	int cnt ;
	for(int i = 100 ; i != 333; ++i){
		if(i % 10 == 0)
			continue ;
		s << i << 2 * i << 3 * i ;
		s >> str ;
		for(auto c : ch){
			cnt = 0 ;
			for(auto x : str){
				if(x == c)
					cnt++ ;
			}
			if(cnt > 1)
				break ;
		}
		if(cnt == 1)
			cout << i << " " << 2 * i << " " << 3 * i << endl ;
		s.clear() ;
	}

}



void foo(int n)
{
	// 打印菱形
	for(int i = n  ; i > 1 ; --i){
		for(int j = 1 ; j <= i - 1 ; ++j)
			cout << " " ;
		for(int j = 1 ; j <= (n - i + 1) * 2 - 1 ; ++j)
			cout << "*" ;
		cout << endl ;
	}
	for(int i = n ; i >= 1 ; --i){
		for(int j = 1 ; j <= (n - i) ; j++ )
			cout << " " ;
		for(int j = 1 ; j <= 2 * i - 1 ; ++j){
			cout << "*" ;
		}
		cout << endl ;
	}
}

void foo1()
{
	// 计算 a / b , 保留c 位小数。
	int a ,b , c ;
	cin >> a >> b >> c ;
	if( !a && !b && !c)
		return ;
	if(!b){
		cerr << "wrong!!! " << endl ;
		return ;
	}
	int dec[c + 1] = {0}  ;
	cout << a / b ;
	for(int i = 0 ; i != c + 1 ; ++i){
		if(!a)
			break ;
		while(a / b == 0){
			a *= 10 ;
		}
		dec[i] = a / b ;
		a %= b ;
	}
	if(dec[c] >= 5)
		dec[c - 1] += 1 ;
	if(c)
		cout << "." ;

	for(int i = 0 ; i != c ; ++i)
		cout << dec[i] ;
	cout << endl ;
	foo1() ;

}


// test func 
int maxSubSumDC(const vector<int> &a , int ls , int rs)
{
	// ls and rs is subs
	if(ls == rs){
		if(a[ls] > 0)
			return a[ls] ;
		else 
			return 0 ;
	}

	int piv = (ls + rs) / 2 ;
	int maxSuml = 0  , maxSumr = 0 ;
	for(int i = ls ; i <= piv ; ++i){
		int thisSum = 0 ;
		for(int j = i ; j <= piv ; ++j){
			thisSum += a[j] ;
			if(thisSum > maxSuml){
				maxSuml = thisSum ;
			}
		}
	}
	for(int i = piv + 1 ; i <= rs ; ++i){
		int thisSum = 0 ;
		for(int j = i ; j <= rs ; ++j){
			thisSum += a[j] ;
			if(thisSum > maxSumr) {
				maxSumr = thisSum ;
			}
		}
	}

	return 1 ;
}

int maxSubSum(const vector<int> &a)
{
	int maxSum = 0 ; 
	for( int i = 0 ; i < a.size() ; i++){
		int thisSum = 0 ;
		for(int j = i ; j < a.size() ;j++){
			thisSum += a[j] ;
			if(thisSum > maxSum ){
				maxSum = thisSum ;
			}
		}
	}
	return maxSum ; 
}

int maxSubSumOn_line(const vector<int> &a)
{
	int maxSum = 0 , thisSum = 0 ;
	for(int i = 0 ; i != a.size() ; ++i){
		thisSum += a[i] ;
		if(thisSum > maxSum){
			maxSum = thisSum ;
		}
		else if(thisSum < 0){
			thisSum = 0 ;
		}

	}
	return maxSum ;
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






// return e^x

double NaturalNumber(int x)
{
	double sum = 0.0 ;
	int i = 0;
	double subNum = 1 / fact(i) ;
	while(subNum >= 1e-10){
		sum += subNum * pow(x , i) ;
		++i ;
		subNum = 1 / fact(i) ;
	}
	return sum ;
}

/*trail-recursion
If all the recursive calls in a function appear at the end of
the function, we call this function is trail-recursion.
*/
double fact(int n , int num )
{
	if(n <= 1)
		return num ;
	else 
		return fact(n - 1, n * num) ;
}


int split(vector<int> &v , int low , int high) 
{
	int pivot = v[low] ;
	while(low < high){
		while(low < high && v[high] >= pivot){
			high-- ;
		}
		if(low < high){
			v[low++] = v[high] ;
		}
		while(low < high && v[low] <= pivot){
			low++ ;
		}
		if(low < high ){
			v[high--] = v[low] ;
		}
	}
	v[low] = pivot ;

	return low ;	
}


int quickSort(vector<int> &v , int low , int high)
{
	int idx ;
	if(low >= high )
		return 0;
	idx = split(v,low , high) ;
	quickSort(v,low , idx - 1) ;
	quickSort(v,idx + 1, high) ;
}


void bubble_sort(int *a , int n)
{
    for(int i = 0 ; i != n - 1 ; ++i){
        int flag = 1 , j; 
        for( j = 0  ; j != n - i ; ++j){
            if(a[j + 1] < a[j]){
                a[j + 1 ] = a[j + 1 ] + a[j] ;
                a[j] = a[j + 1 ] - a[j] ;
                a[j + 1 ] = a[j + 1 ] - a[j] ;
                flag = 0 ;
            }
        }
         if(flag){
            break ;
        }
    }
}



void select_sort( int *a , int n )
{
	for( int i = 0 ; i != n - 1 ; ++i){
		for(int j = i + 1 ; j != n ; ++j){
			if(a[j] < a[i]){
				int tmp = a[i] ;
				a[i] = a[j] ;
				a[j] = tmp ;
			}
		}
	}
}

int search(int *a , int idx , int num )
{
	int left = 0 , right = idx ;
	// needing  orderly sort
	idx = (idx + 1) / 2 ;
	while(left < right ){
		if(a[idx] > num){
			right = idx - 1;
			idx = (idx + left ) / 2  ;
		}
		else if( a[idx] < num){
			left = idx + 1;
			idx = (idx + right) / 2 ;
		}
		else 
			return a[idx] ;
	}
	return INT_MAX ;
}

int sum_recursion(int *a , int n , int sum = 0)
{
	if(n == 0 )
		return sum  ;
	else 
		return sum_recursion(a + 1 , n - 1 ,sum + a[1]) ;
}



int Add (int x, int y)
{
// add to numbers but can't use '+' and '-' 


  return 1 ;
}

double arctan(double x)
{
	//arctanx = x - x ^ 3 / 3 + x ^ 5 / 5 - x ^ 7 / 7 + ... 
	double sqr = x * x ;
	double sum = 0 ;
	double e = x ;
	int i = 1 ;
	int flag = 1 ;
	while(e / i > 1e-10){
		double sub = e / i ;
		sum += flag * sub ;
		flag *= -1 ;
		e *= sqr ;
		i += 2 ;
	}
	return sum ;
}


// queen code 
void queen(void)
{	
	int i , j , n ,ith ;
	putqueen(0) ;
	cin >> n ;
	for(i = 0 ; i != n ;++i){
			cin >> ith ;
		for(j = 0 ; j != N ;++j)
			cout << PlaceQueen[ith - 1][j] ;
		cout << endl ;
	}
}

void putqueen(int ithQueen)
{
	int j ;
	if(ithQueen == N ){
		cnt++ ;
	}

	for(j = 0 ;j != N ; ++j){
		if(!board[j][ithQueen]){
			board[j][ithQueen] = ithQueen + 1 ;
		
			for(int i = cnt ; i != row ; ++i){
				PlaceQueen[i][ithQueen] = j + 1 ;
			}
			if(check(j,ithQueen))
				putqueen(ithQueen + 1) ;

			for(int i = 0 ; i != N ; ++i){
				for(int j = 0 ; j != N ; ++j){
					if(board[i][j] == ithQueen + 1)
						board[i][j] = 0 ;
				}
			}
			
		}
	}
}

bool check(int row , int column)
{
	int i ;
	for(i = 0 ; i < row ; ++i)
		for(int j = 0 ; j != N ; ++j){
			if(j == column || abs(i - row) != abs(j - column)){
				board[i][j] = column + 1 ;
				return false ;
			}
		}
	return true ;

}


