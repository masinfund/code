#include "stdafx.h"

class A{
	int a ;
public:
	A(int x) : a(x) { } 

	virtual void f() = 0 ;

};

class B : public A {
	int b ;
public:
	B(int a, int b) : A(a) , b(b) {}
	void f() { cout << "  B" << b << endl ;}
};

class Test{
public:
	Test(int i ) : number(i) { }
	void SetNumber(int m) { number =  m ;}
	int GetNumber() const {
		return number ;
	}
	void Print() const {cout << "number=" << number << endl ;}
private:
	int number ;
};



string com(const string &tmp){
	string vs = "PAT" ;
	auto nps = tmp.find("PAT") ;
	string::size_type pos1 , pos2 ;
	if(nps != string::npos){
		string s1 = tmp.substr(0,nps);
		string s2 = tmp.substr(nps + 3 , tmp.size() - 1 - tmp.find('T')) ;
		if(s1 == s2 && s1 == string(s1.size() , 'A')){
			return vs ;
		}else{
			return string() ;
		}

	}
	else{
		pos1 = tmp.find('P');
		pos2 = tmp.find('T');
	//	cout << "p1" << pos1 << "p2" << pos2 << endl;
		if(pos2 == string::npos || pos2 < pos1 + 2)
			return string() ;

		string a = tmp.substr(0,pos1);

		string b = (pos1 + 1 < tmp.size() ) ? (tmp.substr(pos1 + 1 ,
				pos2  - pos1   - 2 )) : string() ;
		string c = (pos2 + 1 + a.size() < tmp.size()) ?  ( tmp.substr(pos2 + 1,
		 tmp.size() - pos2 - 1 - a.size()) ) : string() ;
		string fc = a + "P" + b + "T" + c ;
	//	cout << a << " a " << b << " b" << c << " c"  << endl;
		if(fc == vs){
			return vs ;
		}
		else{
			return fc ;
		}
	}
}


int main()
{
	// B b(1,2) ;
	// A *pa ;
	// b.f() ;
	// pa = &b ;
	// pa->f() ;

	// Test b1(1) ;
	// b1.Print() ;
	// Test b2(3) ;
	// b1.SetNumber(10) ;
	// b2.SetNumber(100) ;
	// b1.Print() ;
	// b2.Print() ;

// 1002 3n + 1 

	// for(int i = 1 ;i <= 1000 ; ++i){
	// 	int num , cnt = 0 ;
	//  	num = i ;
	//   	if(num == 1){
	//     	cout << 0 << endl ;
	//     	continue ;
	//   	}
	//   	while(num != 1){
	//     	if(num % 2 == 0)
	//      		 num /= 2;
	//     	else{
	//      	 	num = (3 * num + 1) / 2 ;
	//     	}	
	//     	cnt++ ;
 //  		}
 //  		cout << cnt << endl ;
	// }







// 1003 match "PAT"

// 	8
// PAT
// PAAT
// AAPATAA
// AAPAATAAAA

// xPATx
// PT
// Whatever
// APAAATAA


	int n ;
	cin >> n ;
	string tmp;
	while(n--){
		cin >> tmp ;
		
		auto i = tmp.size() ;
		for(i = 0 ;i != tmp.size() ; ++i){
			if(tmp[i] != 'P' && tmp[i] != 'A' && tmp[i] != 'T')
				break ;
		}
		
		if(i != tmp.size()){
			cout << "NO" << endl;
			continue ;
		}

		string vs = com(tmp) ;
		while(vs.size()){
			if(vs == "PAT"){
				cout << "YES" << endl;
				break;
			}

			else
				vs = com(vs) ;
		}
		if(!vs.size()){
			cout << "NO" << endl;
		}
	}



	return 0 ;
}