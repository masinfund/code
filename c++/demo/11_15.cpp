#include "stdafx.h"

ostream& operator << (ostream &out , string (*p)()){
	out << p() ;
	return out ;
}
ostream& operator<< (ostream& out , int (*p)()){
	out << p() ;
	return out ;
}

string print1()
{
	return "****" ;
}

int print2()
{
	return 100 ;
}


ostream operator<<(ostream& out , void *p)
{
	out << "0x" << hex << (int ) p ;
}

class Except{} ;
class ExceptApple :public Except{ } ;
class ExceptOrange : public Except{ } ;




int main()
{
	cout << print1 << print2 << endl;
	list<int> mylist ;
	for(size_t x = 0 ; x != 4 ; ++x)
		mylist.push_front(x) ;
	list<string> slis ;
	slis.insert(slis.begin() , "Hello!") ;
	// equ slis.push_ffront("Hello!") ;

	vector<string> svec ;
	svec.insert(svec.begin(),"Hello!") ;
	// vector不支持push_front ，但可以插入到begin() 之前，但可能很慢
	svec.insert(svec.end(),10,"Anna") ;
	// 将10个Anna插入到svec.end() 之前。
	svec.insert(svec.begin(),slis.begin(),slis.end());
	// slis插入到sven的开始位置。

// 访问元素
	//包括array在内的每个顺序元素都有一个front成员函数,而除forward_list
	//外所有顺序容器都有一个back成员函数
	if(!svec.empty()){
		auto val = *svec.begin() , val_next = svec.front();
		auto last = svec.end() ;
	}

	char *cTmp = new char[4]() ;
	cTmp[1] = 4 ;
	cout << *cTmp << endl;
	int *iTmp = reinterpret_cast<int *>(cTmp);
	cout<< *iTmp << endl;
	delete []cTmp ;

	try{
		char str[] = "Orange or Apple" ;
		char newStr[10] ;
		char *p = str ;
		for(; p - str <= 6 ; ++p){
			cout << p - str << endl;
			newStr[p - str] = *p ;
		}
		newStr[p - str] = 0 ;
		cout << newStr << endl ;
		switch( *(p - 1)){
			case 'm' :
				throw ExceptApple() ;
			case 't' :
				throw ExceptOrange() ;
			default :
				throw Except() ;
		}
	}catch(ExceptApple) {
		cout << "Apple" << endl;
	}catch(ExceptOrange){
		cout << "Orange" << endl;
	}catch(Except){
		cout << "Unknow" << endl; 
	}

	string s1 = "def" ;
	string s2 = "gh" + s1 + "lmn" ;
	cout << s2 << endl;


	int xxx = (int )&xxx ;
	cout << "0x" <<  hex <<  xxx << endl;

	stack<int> intStack ;
	for(size_t ix = 0 ;ix != 10 ; ++ix)
		intStack.push(ix) ;
	while(!intStack.empty()){
		int value = intStack.top() ;
		cout << value << "\t" ;
		intStack.pop() ;
	}
	cout << '\n' ;
	string sst ;
	sst = 'c' ;
	cout << sst << sst.size() << endl;
	return  0 ;
}