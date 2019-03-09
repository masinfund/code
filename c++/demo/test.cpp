// Life is limited while learning is limitless, 


#include "stdafx.h"
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
	hour(newH) , minute(newM), second(newS)
	{if(!(hour >= 0 && hour < 24 && minute >= 0 
		&& minute < 60 && 0 <= hour && hour < 24 
		&& second >= 0 && second < 60)) cout << "Time error!" << endl ;}
Clock::Clock() : Clock(0,0,0) {}

void Clock::setTime(int newH, int newM , int newS )
{
	hour = newH ;
	minute = newM ;
	second = newS ;
}
inline void Clock::showTime() const 
{
	cout << "Time is :" << '\n' ;
	cout << hour << ":" << minute << ":" << second <<endl ; 
}

//前置++重载
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

//Person class 
struct person{
	private:
		// data member 
		std::string name ;
		std::string address ;
		std::string phone ;
	public :
		//constructor member
	  person() = default ;
		person(const std::string &lhs ,const std::string &rhs) : name(lhs) , address(rhs) {}
		person(std::istream &is) 
		{
			is >> this->name >> this->address >> phone ;
		}

		// func member 
		std::vector<string> per_message() const 
		{ return {name,address , phone} ;  }
		std::string per_name() const 
		{ return name ;}
		std::string per_ddress() const 
		{ return this->address ;}
		std::string per_phone() const {
			return phone ;
		}

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

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size() ;
}


//先按字母序排序，然后使用稳定排序(即保持字母序)，按照单词长度排序
void elimDups(vector<string> &words)
{
	sort(words.begin() , words.end()) ;
	auto end_unique = unique(words.begin(), words.end()) ;
	words.erase(end_unique , words.end()) ;

	stable_sort(words.begin(),words.end() , isShorter) ;

	words.erase(end_unique,words.end()) ;
	//删除从end_uniuqe至尾迭代器
	for(const auto &s : words)
		cout << s << "  " ; 
	cout << endl ;
}


string make_plural(size_t cstr, const string &word , const string &ending)
{
	//make_plural(wc, "word ", "s ")当输入中文本中,
	//word数大于一是在word后加s，为words为word的复数！
	return (cstr == 1) ? word : word + ending ;
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


	auto count = words.end() - wc ;
	os << count << "  " << make_plural(count,"word","s")
		 << " of length " << sz << " or longer" << endl ;
	// make_plural  输出word or words 

	// for_each 接受一个可调用对象，并对输入序列中每个元素调用此对象
	for_each(wc,words.end(),[&os,c] (const string &s) {os << s << c ;}) ;
	cout << endl ;
}



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



class Rectangle1 : private Point {
	public :
	void initRectangle1(int x , int y , double w , double h){
		initPoint(x,y) ;
		width = w ;
		high = h ;
	}
	void move(int offX , int offY){Point::move(offX,offY) ;}
	int getX() const {return Point::getX() ;}
	int getY() const {return Point::getY() ;} 
	double getH() const {return high ;}
	double getW() const {return width ;}
	double area() { return width * high ; }

	private :
		double width , high ;
} ;

class Shape {
public:

	virtual double area() const { return 0.0 ; } // 虚函数
	virtual void shapeName() const = 0  ;	
} ;

class Point1 : public Shape {
public:
	friend ostream& operator <<(ostream& out , const Point1 &p){
		out << "[" << p.x << "," << p.y << "]" << endl ;
		return out ; 
	}
	Point1(double a = 0.0 , double b = 0.0) : x(a) , y(b) {}
	void set(double a , double b){
		x = a ; 
		y = b ;
	}
	double getX() const {return x ;}
	double getY() const {return y ;}
	virtual void shapeName() const { cout << "Point" ;}
private:
	double x ;
	double y ;
};

class Circle: public Point1 {
public:
	friend ostream& operator <<(ostream &out , const Circle &c){
		out << "[" << c.getX() << " , " << c.getY() << "] , r = " << c.getRadius() << endl ;
		return out ; 
	}
	Circle(double a = 0.0 , double b = 0.0 , double r = 0.0) : 
	Point1(a , b) , radius(r) {}
	void setRadius(double r){
		radius = r ;
	}
	double getRadius() const {return radius ;}
	virtual double area() const {return 3.14 * radius * radius ;}
	virtual void shapeName() const {cout << "Circle" ; }
private:
	double radius ;

};



//派生类 
class Base0 {
	public :
	Base0() { cout << "Base0 constructor" << endl ; }
	Base0(const Base0& b) : var(b.var) { cout << "Base0 copy constructor" << endl ;}
	~Base0() { cout << "Base0 destructor" << endl ; }
	int var ;
	Base0(int v) : var(v) { cout << "Base0 constructor" << v << endl ;}
	void fun() { cout << &var <<  "\tMember 0" << "  " << var << " " <<  this <<  endl ;}
	virtual void display() const = 0 ; // 纯虚函数

} ;
//具体实现不应该写入类体中，写入类体中会被作为内联函数在编译阶段嵌入
//具体的代码中去。

class Base1 : public Base0 {
public :
	Base1() {cout << "Base1 Constructor" << endl ;}
	Base1(const Base1& b) : Base0(b.var) , j(b.j) { cout << "Base1 copy constructor" << endl ;}
	int j ;
	Base1(int i , int j) : Base0(i) , j(j) { cout << "Base1 Constructor" << j << endl ;}
	~Base1() { cout << "Base1 destructor" << endl ;}
	void display() const ;
} ;
void Base1::display() const {
	cout << "Base1::display() " << endl ;
}
class Base2 {
	public:
		Base2() { cout << "Base2 Constructor" << endl ;}
		Base2(int j) { cout << "Constructing Base2 " << j << endl ;}
		~Base2() { cout << "Destructors Base2" << endl ;}
};
class Derived : public Base1 , public Base2 {
public :
	Derived() { }
	Derived(int a , int b , int c , int d , int e , int f) : Base1(a,b) , Base2(c) , b1(d , e) , b2(f) { cout << "Constructor Derived" << endl ;}
	~Derived() { cout << "Destructors Derived " << endl ;}
	void display() const ;
private :
	Base1 b1 ;
	Base2 b2 ;
} ;
void Derived :: display() const {
	cout << "Derived ::display() " << endl ;
}
void fun(Base0 *p) {
	p->display() ;
}


void foo5(int (*c)[5],int n) ;
void wordCount() ;
void foo(int n) ;
void foo2() ;
void foo3(int n) ;
void inplace_swap(int &x , int &y) ;
void heart() ;
float heart_h(float x , float z);
float heart_f(float x , float y , float z);
template <unsigned n , unsigned m>
int compare(const char (&p)[n], const char (&q)[m]) ;
static int PlaceQueen[row][N] ;
static int board[N][N] ;
void putqueen(int Queen) ;
void queen(void) ;
bool check(int row , int column) ;
// mathTest class member 
double fact(int n , int num = 1) ;
double NaturalNumber(int x ) ;
int maxSubSum(const vector<int> & a) ;


/*#ifdef LOCAL
    freopen("in.dat","r",stdin) ;
    freopen("out.dat","w",stdout) ;
#endif
*/

void findFACh(){
	// 寻找第一次只出现一次的字符
	int arr[26][2] = {0} ;
	for(int i = 0 ;  i < 26 ; ++i){
		arr[i][0] = 'a' + i ;
	}
	char tmp , ch ; 
	while(cin >> tmp) {
		for(int i = 0 ; i < 26 ; ++i){
			if(tmp == arr[i][0])
				arr[i][1]++ ;
		}
	}

}


class A{
public:
	string str;
	A() {str = "gl" ;}
	explicit A(const string &s) : str(s){cout << s << endl ;}
	A& operator=(const A& a) {if(&a != this) str = a.str ; cout << "copy-assign" << endl ;}
	A& operator=(A& a) {if(&a != this) str = a.str ; cout << "copy-assign-no-const" << endl ;}
	A(const A& a){str = a.str ; cout << "copy" << str << endl ;}
	A(A& a){str = a.str ; cout << "copy noconst" << str << endl ;}
	//A(A&& a){str = a.str ; cout << "nocopyconst"<< endl;}
	//A(const A&& a){str = a.str ; cout << "nocopy" << endl;}
	//A& operator=(const A&& a){str = a.str ; cout << "moveRnoConst";}
};
A A_test()
{
	A a("adfad") ;
	return a ;
}







void daffodil()
{
	//水仙花数
	for(int i = 100 ; i < 1000 ; ++i){
		int s = 0 , tmp , j = i ;
		while(j){
			tmp = j % 10 ; 
			s += tmp * tmp * tmp  ;
			j /= 10 ;
		}
		if(s == i)
			cout << i << endl ;
	}
}


int exgcd(int a , int b , int& x , int& y)
{
	if(!b){
		x = 1 ;
		y = 0 ; 
		return a ;
	}
	int gcd = exgcd(b , a % b , x , y) ;
	int x_t , y_t = y ;
	x = y_t ;
	y = x_t - (a / b) * y_t ;
	return gcd ;
}

void hanxinCount()
{
//存在一个数x，除以3余2，除以5余三，除以7余二，然后求这个数。
//两个数相加，如果存在一个加数，不能被a整除，那么它们的和，就不能被a整除
// a + c === (b + c ) (mod n )
// a * c === b * c (mod n ) 
//乘法逆元  ： a * x === 1 (mod m )   a * x + m * y = 1 
//两数不能整除，若除数扩大或缩小，而被除数不变，其商和余数也同时扩大或缩小
//相同的倍数。
//裴蜀定理 ： 若 a * x + b * y = z , 则 gcd(a , b) / z 

	int a = 2 , b = 1 , c = 6 , sum ;
	sum = (a * 70 + b * 21 + c * 15) ;
	if(sum > 105)
		sum %= 105 ;
	cout << sum << endl ;

}


void test01()
{
	daffodil() ;
	hanxinCount() ;
}





int main(int argc , const char **argv)
{

	test01() ;

	return 0 ;
}






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



int Add (int x, int y)
{
// add two numbers but can't use '+' and '-' 
	while(y != 0){
		int tmp = x ^ y ; 
		int tmp1 = x & y ; 
		x = tmp ; 
		y = tmp1 << 1 ;
	}
	return  x;
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


