/*#include <iostream>

using namespace std ;

//一程序阅读题
//-----------------------------------------1----------------------

/*
int main()
{
	int a = 10 ; 
	bool b = true ;
	float c = 10.5f + a ;
	char d = 'a' ;
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << (int) c << endl; 
	//output:
	//10 1 20.5 a
	//20
}*/


//-----------------------------------2------------------------------

/*#include <cstring>
int fun(char *a){
	return strlen(a) ;
}

int fun(int b , int c){
	return b + c + 1 ;
}

int fun(bool b){
	return b ? 1 : -1 ;
}

int main()
{
	cout << fun(5 , 6) << endl << fun(false) << endl << fun(5) ;
	//output 
	//12
	//-1
	//1
}*/


//-----------------------------3-------------------------------
/*
class B {
public:
	void f(){
		cout << "1" << endl;
	}
	~B(){
		cout << "5" << endl;
	}
	virtual void g(float x){
		cout << x << endl;
	}
};

class D : public B {
public:
	virtual void f(){
		cout << "3" << endl; 
	}
	virtual void g(float y){
		cout << y << " " << y << endl ;
	}
};

int main()
{
	D *d = new D ;
	d->f() ;
	d->g(200) ;
	delete d ;
	//output:
	//3 
	//200 200 
	//5 
}*/



//------------------------------4-------------------------------

/*static int allcount = 0 ;
class Task{
	int x ;
	Task() : x(20) { allcount++ ; x++ ;}
public:
	~Task(){ allcount-- ; delete this ;}
	static Task* create(){
		return new Task ;
	}
	int getX() const {
		return x ;
	}
	int getAllCount(){
		return allcount ;
	}
};

int main()
{
	Task* p[3] ;
	for(int i = 0 ; i < 3 ; ++i){
		p[i] = Task::create() ;
		cout << p[i]->getX() << " " << p[i]->getAllCount() << endl;
	}
	//output:
	//21 1
	//21 2
	//21 3
}
*/

//--------------------------------5------------------------------
/*
void process(int (*a)[4] , int row , int col){
	for(int i = 0 ;i < row ; ++i)
		for(int j = 0 ; j < col ; ++j){
			a[i][j] += *(*(a + i) + j) ;
		}
}

int main()
{
	int a[][4] = {1,1,1,1,
				  2,3,4,5,
				  6,6,6,6,
				  6};
	process(a,3,4) ;
	for(int i = 0 ;i < 3; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			cout << a[i][j] ;
			if(j < 3){
				cout << "-" ;
			}
		}
		cout << endl;
	}

	//output:
	//2-2-2-2
	//4-6-8-10
	//12-12-12-12
}
*/


 //--------------------------------6----------------------------
/*
int main()
{
	try{
		for(char i = '1' ; i < '5' ; i++){
			switch(i){
				case '1':
				case '2':
					cout << i << endl;
					break ;
				case '3':
					cout << i << endl;
					throw 10 ;
				case '4' :
					cout << i << endl;
				default:
					cout << "default" << endl;
					throw i ;
			}
		}
	}catch(int exp){
		cout << exp << endl;
	}catch(char exp){
		cout << exp << endl;
	}
	//output:
	//1
	//2
	//3
	//10
}


*/



//二编程题
//------------------------1------------------------------------

/*#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	ifstream fin("file.txt" , ios::binary) ;
	ofstream fout("out.dat", ios::app | ios::binary) ;
	if(fin){
		vector<int > v ;
		int tmp ;
		while(fin >> tmp){
			v.push_back(tmp) ;
		}
		sort(v.begin() , v.end()) ;
		for(auto x : v){
			fout << x << " " ;
		}
		cout << endl;
		int a = v[v.size() - 1] , b = v[v.size() - 2] ;
		if(a && b){
			while(a % b){
				tmp = a % b ;
				a = b ;
				b = tmp ;
			}
			cout << b << endl;
		}

	}
	fin.close();
	fout.close() ;
}*/


//-------------------------------2-----------------------------
/*
class Building{

	int room ;
	int layor;
	double area ;
public:
	Building(int x , int y , double z) : room(x) , layor(y) ,
										 area(z) { }
	virtual ~Building(){}
	int getRoom(){
		return room ;
	}
	int getLayor(){
		return layor ;
	}
	double getArea(){
		return area ;
	}

};
class Housing : public Building{
	int bedroom ;
	int shower ;
public:
	Housing(int  b , int s , int x , int y , double z) :
	bedroom(b) , shower(s) , Building(x , y , z){ }
	print(){
		cout << getRoom() << " "
			 << getLayor() << " "
			 << getArea() << " " 
			 << bedroom << " " 
			 << shower << " " ;
	}
};

class Office : public Building{
	int tele ;
	int fireExit;
public:
	Office(int t , int f , int x , int y , double z):
	tele(t) , fireExit(f) , Building(x , y , z) {}
	print(){
		cout << getRoom() << " "
		 << getLayor() << " "
		 << getArea() << " " 
		 << tele<< " " 
		 << fireExit << " " ;
	}
};


int main()
{

	Housing h(1,2,3,4,5.0) ;
	Office o(1,2,3,4,5.0) ;
	h.print() ;
	cout << endl;
	o.print() ;
	return 0 ;
}


*/



//-------------------------3-----------------------------

/*

void print(int a ,int b){
	for(int i = a ; i <= b ; ++i)
		cout << i << " " ;
	cout << endl;
}

int main()
{
	int a , b , c , d ;
	cin >> a >> b >> c >> d ;

	if(c > a){
		if(c > b){
			cout << "无交集" << endl;
		}
		else if(b < d){
			print(c , b) ;
		}
		else {
			print(c , d) ;
		}
	}
	else{
		if(a > d){
			cout << "无交集" << endl;
		}
		else if(d < b){
			print(a , d) ;
		}else{
			print(a , b) ;
		}
	}

	return 0 ;
}*/


