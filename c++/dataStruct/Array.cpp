#include "stdafx.h"
#include "Array.h"

template<class T>
Array<T>::Array(int sz) 
{
	assert(sz >= 0) ;
	size = sz ;
	list = new T[size] ;
}

template <class T>
Array<T>::Array(const Array<T> &a)
{
	size = a.size ;
	list = new T[size] ;
	for(int i = 0 ; i < size ; ++i)
		list[i] = a.list[i] ;
}

template <class T>
Array<T>::~Array()
{
	delete []list ;
}

template <class T>
Array<T>& 
	Array<T>::operator =(const Array<T> &rhs)
{
	if(&rhs != this){
		if(size != rhs.size){
			delete []list ;
			size = rhs.size ;
			list = new T[size] ;
		}
		for(int i = 0 ; i < size ; ++i)
			list[i] = rhs.list[i] ;
	}
	return *this ;
}

template<class T>
T& 
	Array<T>::operator [](int i)
{	
	return 
		const_cast<T &>(
			static_cast<const Array<T> &>(*this)
				[i]) ;

}

template<class T>
const T& 
	Array<T>::operator [](int i ) const 
{
		assert(i >= 0 && i < size ) ;
	return list[i] ;
}



template<class T>
Array<T>::operator T*() 
{
	return list ;
	// Array<int> a(10) ; 
	//read(a,10) ; // 会将对象名a 转换为int *
}


template <class T>
Array<T>::operator const T* () const {
	return list ;
}

// Array<int> a(10) ; 
// read(a , 10 ) ; //编译系统会进行类型转换，将对象名a转换为int *  
//类型转换操作符的重载函数不用指定返回值的类型,因为返回类型与操作符名称一致



template <class T>
int Array<T>::getSize() const 
{
	return size ;
}

template <class T>
void Array<T>::resize(int sz) {
	assert(sz >=0) ;
	if(sz == size)
		return ;
	T *newL = new T[sz] ;
	int min = (sz < size) ? sz : size ;
	for(int i = 0 ; i < min ; ++i)
		newL[i] = list[i] ;
	delete []list ;
	list = newL ;
	size = sz ;
} 



int main()
{
	Array<int> a(10) ; 






	int cnt = 0 ; 
	int n ; 
	cout << "Enter a value >= 2 as upper limit for prime numbers : " ;
	n = 100 ;
	for(int i = 2 ; i <= n ; ++i){
		bool isPrime = true ;
		for(int j = 0; j < cnt ; ++j)
			if(i % a[j] == 0){
				isPrime = false ;
				break ;
			}
		if(isPrime){
			if(cnt == a.getSize())
				a.resize(cnt * 2) ;
			a[cnt++] = i ;
		}
	}
	cout.fill('*') ;
	for(int i = 0 ; i < cnt ; ++i){
		cout << setw(10) << a[i]  ; 
		if(i + 1 % 4 == 0 )
			cout << '\n' ;
	}
	cout.fill('@') ;
	cout << setw(20) << 42 ;
	cout << endl ;

	cout << setfill(' ')  << 3.24 << endl ;

	double values[] = {1.23 , 35.36, 653.7 , 4358.24 } ;
	string names[] = {"Zoot" , "Jimmy" , "Alin" , "Stan" } ;
	for(int i = 0 ; i < sizeof(values) / sizeof(values[0]) ; ++i)
		cout << setiosflags(ios::left) << setw(6) << names[i]
			 << resetiosflags(ios_base::left) 
			 << setw(10) << setiosflags(ios_base::fixed) << setprecision(1) << values[i] << endl ;

	cout << 3.24 << '\t' << resetiosflags(ios_base::fixed) << setiosflags(ios_base::scientific) 
	<< 3.24 << '\t' << resetiosflags(ios_base::scientific) << 3.24 << endl ;
	cout << setprecision(6) <<  3.24 << endl ;

	ofstream file("runpgms",ios_base::binary | ios_base::app) ;
	for(int i = 0 ; i < 10 ; ++i)
		file.put('d') ;

	string s = " hello " ;
	file.write(s.c_str() , s.size()) ;
	file.close() ;

	int val[] = {3,7,0,5,4} ;
	file.open("runpgms",ios::binary | ios::app) ;
	file.write(reinterpret_cast<char *>(val) , sizeof(val));
	file.close();

	ifstream is("runpgms",ios_base::in | ios_base::binary) ;
	if(is){
		is.seekg(3 * sizeof(int)) ;
		int v ;
		is.read(reinterpret_cast<char *>(&v) , sizeof(int)) ;
		cout << "The 4th is " << v << endl ;
	}else {
		cout << "Error : Cannot open " << endl ;
	}
	is.close() ; 

	struct Sa{
		string name ;
		double *tax ;
	};
	double db = 3.24 ;
	Sa s1 = {"zj",&db} ;
	ofstream os("runpgms",ios::binary) ;
	os.write(reinterpret_cast<char *>(&s1),sizeof(s1));
	os.close() ;
	Sa s2 ;
	is.open("runpgms",ios::binary) ;
	if(is){

		is.read(reinterpret_cast<char *>(&s2),sizeof(s2));
	}else {
		cout << "Error" << endl ;
	}
	is.close() ;
	printf("%p   %p\n",s1.tax , s2.tax) ;
	cout << *s2.tax << endl;


	return 0 ;
}


/*
This chart above demonstrates the proportion of each grade of college
students to tatke part-tiem jobs in a certain city. According to the 
data given..
that ..

the situation of part-time jobs of college students in ca certain city.
the situation college students' taking part-time jobs in a certain city
*/