#include "stdafx.h"

template < class T>
class Array{
private:
	T *list ;
	int size ;
public:
	Array(int sz = 50) ;
	Array(const Array<T> &a) ;
	virtual ~Array() ;
	Array<T> & operator = (const Array<T> &rhs) ;
	T& operator [](int i) ;
	const T& operator [](int i ) const ;  // []对const的重载
	operator T*() ; // 重载到 T * 类型的转换
	operator const T* () const  ;
	int getSize() const ;
	void resize(int sz) ; 

};

