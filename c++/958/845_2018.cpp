#include <iostream>

using namespace std ;

// 一程序阅读题

//-----------------------1--------------------------------

/*using namespace std ;

int main()

{
	int a[6] , b[3] , *p = b ;
	for(int i = 0; i < 6 ; ++i)
		a[i] = i ;
	for(int i = 0 ; i < 3 ; ++i)
		b[i] = a[i * 2] ;
	for(int i = 0 ;i < 3 ; ++i)
		cout<< *(p++) << '/' ;
	//output : 0/2/4/ 
	return 0 ;
}*/


//------------------------------2----------------------------

/*int fun(int a , int b)
{
	return b == 1 ? a + 1 : a -1 ;
}

int main()
{
	for(int i = 0 ;i <= 2 ; ++i){
		for(int j = 0 ;j <= i - 1 ; ++j)
			cout << fun(j , 1) ;
		for(int k = 0 ; k <= 4 - 2 * i ; ++k)
			cout << "A" ;
		for(int j = i - 1 ; j >= 0 ; --j)
			cout << fun(j , 1) ; 
		cout << endl;
	}
	//AAAAA
	//1AAA1
	//12A21	
}*/

//--------------------------------3-------------------------------

/*class B {
public:

	virtual int fun(){
		cout << "B::fun" << endl;
		return 10 ;
	}
};
class D : public B {
public:
	int fun(void){
		cout << "D::fun" << endl;
		return 20 ;
	}
};

int main(void)
{
	D d ;
	B *b1 = &d ;
	B &b2 = d ;
	B b3 ;
	b1->fun() ;
	b2.fun() ;
	b3.fun() ;
	//output:
	//D::fun
	//D::fun
	//B::fun
}
*/



//-----------------------------4----------------------------------
/*
int x = 0 ; 
int Fun()
{
	return x++ ;
}

int main()
{
	try{
		for(int i = 0 ;i < 3 ; ++i){
			switch(i){
				case 0 :
					cout << Fun() << endl ;
				case 1 : 
					cout << Fun() << endl; 
					break ;
				case 2 :
				default :
					throw "Error" ;
					break ;
			}
		}
	}catch(char *exp){
		//const char *exp){
		cout << exp << endl;
	}
	//output :  0
				1
				2
}*/


//--------------------------------5-------------------------------

/*int i = 4 ;
int f(int m)
{
	static int i =  0 ; 
	int s = 0 ; 
	for( ; i < m ; ++i)
		s += i + (::i) ;
	cout << ::i << "," << i << endl;
	return s ;
}

int main()
{
	cout << f(1) << endl;
	cout << f(2) << endl;
	//output:
	//4,1
	//4
	//4,2
	//5
}*/


//---------------------------6-----------------------------------

/*const char * f(const char *a){
	return a ;
}
int f(int b , int c){
	return b + c ;
}
int f(bool b){
	return b ? 1 : -1 ;
}

int main()
{
	std::cout << f(1 ,2 ) << std::endl ;
	std::cout << f("false") << std::endl;
	std::cout << f((bool)0) << std::endl;
	std::cout << f(true) << std::endl;
}*/

//二编程题
//--------------------------------1-------------------------
/*
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	ofstream out("out.dat",ios::binary) ;
	ifstream in("noinput",ios::binary) ;
	if(in && out){
		string s ;
		getline(in , s);
		istringstream is(s) ;
		int tmp ;
		vector<int > v ;
		while(is >> tmp){
			v.push_back(tmp) ;
		}
		sort(v.begin() , v.end()) ;
		for(auto it = v.rbegin() ; it != v.rend() ; ++it)
			out << *it << " " ;
		out << endl;
		int sum = 0 ; 
		for(auto x : v)
			sum += x ;
		out << sum << endl;
		out << (sum / v.size()) << endl;
	}

	out.close() ;
	in.close() ;
	return 0 ;
}*/

//--------------------------------------2-------------------------

/*long fact(int n){
	if(n < 0)
		return 0 ;
	if(n == 0 || n == 1)
		return 1 ;
	return n * fact(n - 1) ;
}

long fact(int n , int base){
	if(n < 0)
		return 0 ;
	if(n == 0 || n == 1)
		return base ;
	else 
		return fact(n - 1 , n * base ) ;
}

int main()
{
	int n ;
	cin >> n ;
	cout << fact(n , 1) ;
	return 0 ;
}

*/


//-------------------------3---------------------------------------



class Date {
	int year;
	int month;
	int day;
public:
	Date() : year(0), month(0), day(0) {}
	Date(int y, int m, int d) : year(y), month(m), day(d) { }
	Date(const string &s);
	friend bool operator == (const Date& d , const Date& d1) {
		if (d.year == d1.year && d.month == d1.month && d.day == d1.day)
			return true;
		else
			return false;
	}
	friend ostream& operator <<(ostream& out, const Date& d) {
		out << d.year << "-" << d.month << "-" << d.day;
		return out;
	}
};

bool operator==(const Date&, const Date&);

Date::Date(const string &s) {
	int a[4] = { 0 };
	int k = 0;
	for (decltype(s.size()) i = 0; i != s.size();) {
		while (s[i] >= '0' && s[i] <= '9') {
			int tmp = s[i] - '0';
			a[k] = tmp + a[k] * 10;
			i++;
		}
		if (a[k]) {
			k++;
		}
		else {
			i++;
		}
	}
	year = a[0];
	month = a[1];
	day = a[2];

}

struct Node {
	Date dt;
	Node *next;
};

class DateList {
	Node *head;
public:
	~DateList() {
		if (head) {
			Node *cur = head;
			while (cur) {
				Node *tmp = cur->next;
				delete cur;
				cur = tmp;
			}
		}
	}

	DateList() { head = nullptr; }
	void Add(const Date &d) {
		Node *tmp = new Node;
		tmp->dt = d;
		tmp->next = nullptr;
		if (head) {
			Node *t = head ;
			while (t->next) {
				t = t->next;
			}
			t->next = tmp;
		}
		else
			head = tmp;
	}
	void delDate(const Date &d) {
		if (head) {
			Node *pre = head, *cur = head->next;
			if (pre->dt == d) {
				head = cur;
				delete pre;
			}
			else {
				while (cur) {
					if (cur->dt == d) {
						pre->next = cur->next;
						delete cur;
						break;
					}
					else {
						pre = cur;
						cur = cur->next;
					}
				}
			}

		}

	}

	void print() {
		if (head) {
			Node *tmp = head;
			while (tmp) {
				cout << tmp->dt << endl;
				tmp = tmp->next;
			}
		}
	}
};




int main()
{
	Date d1("1997-3-4") ;
	Date d2(1997,8,22) ;
	DateList l ;
	l.Add(d1) ;
	l.Add(d2) ;
	l.delDate(d1) ;
	l.Add(d2) ;
	l.Add(d1) ;
	l.print() ;


	return 0 ;
}