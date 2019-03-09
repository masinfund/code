#include "stdafx.h"


class CLessThen9{
public:
	bool operator() (int n){ return n < 9 ; }
};
void outputSquare(int value) { cout << value * value << endl;}
int calculateCube(int value) { return value * value * value ;}

class C {
	public:
		int a , b ;
	C(int x = 6 , int y = 7)  : a(x) , b(y){cout << "Constructor" << endl;}
	~C() { cout << "destructor" << endl;}
	C(const C&& x) { a = x.a ; b = x.b ; cout << "move-c" << endl;}
	C& operator=(const C&&x){a = x.a ; b = x.b ; cout << "move-c-a" << endl;}
	C(const C& x) {a = x.a ; b = x.b ; cout << "copy" << endl;}
	C& operator = (const C& x ) { a = x.a ; b = x.b ; cout << "copy assign" << endl; return *this ;}
	void display(){cout << a << "  " << b << endl;}
};
int main()
{
{
	C c1(5) ;
	C c2 = C(2,2.4);
	c2.display();
	cout << typeid(c1).name() << endl;
}
	int a[] = {1,2,3,4,5,6,7,44,89,29,0,3,4,5,200};
	int a1[] = {2,4,5,6,7,8,432,8,2,4,9 ,10} ;
	vector<int > v(a,end(a));
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),[](const int& a){ cout << a <<  " " ;});
	cout << endl;
	auto it = lower_bound(v.begin(),v.end(),201);
	cout << it - v.begin() << "  " << v.size() << endl;	
	ostream_iterator<int> output(cout," ") ;

	copy(v.begin(),v.end(),output) ;
	//copy 第一个参数类型是vector<int>::const_iterator
	//output 是 ostream_iterator<int> 
	ofstream ouFile("runpgms",ios::out) ;
	ostream_iterator<int> outf(ouFile,"\n");
	copy(v.begin(),v.end(),outf) ;
	ouFile.close() ;


	cout << endl;

	random_shuffle(v.begin(),v.end()); // 变序算法
	copy(v.begin(),v.end() ,output) ;
	cout << endl;

	copy(a1,end(a1),v.begin());
	copy(v.begin(),v.end(),output) ;
	cout << endl;

	cout << count(v.begin(),v.end(),8)<< endl; ;
	cout << count_if(v.begin(),v.end(),CLessThen9()) << endl;

	cout << *(min_element(v.begin(),v.end())) << endl;

	cout << *(max_element(v.begin(),v.end())) << endl;
	cout << accumulate(v.begin(),v.end(),0) ;//求和,和的初始值为0

	for_each(v.begin(),v.end(),outputSquare);

	transform(a1,end(a1),v.begin(),calculateCube);
	copy(v.begin(),v.end(),output);
	cout << endl;

	priority_queue<double> pq ;
	pq.push(3.2) ;
	pq.push(9.8) ;
	pq.push(9.8);
	pq.push(5.4) ;
	while(!pq.empty()){
		cout << pq.top() << "  " ;
		pq.pop() ;
		cout << endl;
	}

	typedef multimap<int , double , less<int> > mmid ;
	mmid pairs ;
	cout << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(15,2.7)) ;
	pairs.insert(mmid::value_type(15,99.3));
	pairs.insert(make_pair(24,9.3));
	cout << pairs.count(15) << endl;
	for(auto i  = pairs.begin() ; i != pairs.end() ; ++i){
		cout << "(" << i->first << " , " << i->second << ")" << endl;
	}

	


	return 0 ;
}