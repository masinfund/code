#include "stdafx.h"


// Matrix
class Matrix {
public:
	Matrix(int size = 2) ;
	~Matrix() ;
	void setMatrix(const double *values) ;
	void printMatrix() const ;
	int getSize() const { return size ;}
	double& element(int i , int j ) {return elements[i * size + j] ;}
	double& element(int i , int j) const {return elements[i * size +j ] ;}
private :
	int size ;
	double *elements ;
	
} ;


void Matrix::setMatrix(const double *values)
{
	for(int i = 0 ; i < size * size ; ++i) {
		elements[i] = values[i] ;
	}
}

Matrix::Matrix(int size) : size(size) { elements = new double[size * size ] ;}
Matrix::~Matrix() {delete []elements ;}
void  Matrix::printMatrix() const {
	cout << "The Matrix is : " << endl ;
	for(int i = 0 ; i < size ; ++i){
		for(int j = 0 ; j < size ;++j)
			cout << setiosflags(ios::left) << setfill('0') << setw(6) << setprecision(4) << element(i , j) << "\t" ;
		cout << endl ;
	}
}


class LinearEqu : public Matrix
{
public:
	LinearEqu(int size = 2);
	~LinearEqu();
	void setLinearEqu(const double *a , const double * b) ;
	bool solve() ;
	void printLinearEqu() const ;
	void printSolution() const ;
private :
	double *sum ;
	double *solution ;
};

LinearEqu::LinearEqu(int size ) : Matrix(size){
	sum = new double[size] ;
	solution = new double[size] ;
}

LinearEqu::~LinearEqu() {
	delete []sum ;
	delete []solution ;
}

void LinearEqu::setLinearEqu(const double *a , const double *b){
	setMatrix(a) ;
	for(int i = 0 ; i < getSize() ; ++i)
		sum[i] = b[i] ;
}

void LinearEqu::printLinearEqu() const {
	cout << "The Line eqution is :" << endl ;
	for(int i = 0 ; i < getSize() ; ++i) {
		for(int j = 0 ; j < getSize() ; ++j)
			cout << setiosflags(ios::left) << setfill('0') << setw(6) << setprecision(4) <<  element(i , j) << " " ;
		cout << "\t" << sum[i] << endl ;
	}
}

void LinearEqu::printSolution() const {
	cout << "The Result is : " << endl ;
	for(int i = 0 ; i < getSize() ; ++i)
		cout << "x[" << i << "] =" << setiosflags(ios::left) << setfill('0') << setw(6) << setprecision(4) <<  solution[i] << endl ;
}



//全选主元高斯消去法
bool LinearEqu::solve() {
	int *js = new int [getSize()] ; // 存储主元素所在列号的数组	
	for(int k = 0 ;k < getSize() - 1 ; ++k){
		int is ; // 主元素所在的行号
		double max = 0.0 ;
		for(int i = k ; i < getSize() ; ++i)
			for(int j = k ; j < getSize() ; ++j){
				double t = fabs(element(i , j)) ;
				if(t > max){
					max = t ;
					js[k] = j ;
					is = i ;
				}
			}
	
	if(max < 1e-15){
		delete[] js ;
		return false ;
	}
	else {
		if(js[k] != k) 
			for(int i = 0 ; i < getSize() ; ++i)
				swap(element(i , k) , element(i , js[k])) ;
		if(is != k){
			for(int j = k ; j < getSize() ; ++j)
				swap(element( k , j) , element(is , j)) ;
			swap(sum[k] , sum[is] ) ;
		}
	}

	double major = element(k , k ) ;
	for(int j = k + 1 ; j < getSize() ;++j)
		element(k , j) /= major ;
	sum[k] /= major ;
	for(int i = k + 1 ; i < getSize() ; ++i){
		for(int j = k + 1 ; j < getSize() ; ++j)
			element(i , j) -= element(i , k) * element(k , j) ;
		sum[i] -= element(i , k) * sum[k] ;
	}
}

	double d = element(getSize() - 1 , getSize() - 1) ;
	if(fabs(d) < 1e-15){
		delete[] js ;
		return false ;
	}

	solution[getSize() - 1] = sum[getSize() - 1] / d ;
	for(int i = getSize() - 2 ; i >= 0 ; --i){
		double t = 0.0 ;
		for(int j = i + 1 ; j <= getSize() - 1 ; ++j) {
			t += element(i , j) * solution[j] ;
		}
		solution[i] = sum[i] - t ;
	}

	js[getSize() - 1] = getSize() - 1 ;
	for(int k = getSize() - 1 ; k >= 0 ; --k)
		if(js[k] != k)
			swap(solution[k] , solution[js[k]]) ;
	delete []js ;
	return true ;
}

void testMatrix(){
	double a[] = {0.2368 , 0.2471 , 0.2568 , 1.2671 ,
				  0.1968 , 0.2071 , 1.2168 , 0.2271 ,
				  0.1581 , 1.1675 , 0.1768 , 0.1871 ,
				  1.1161 , 0.1254 , 0.1397 , 0.1490} ;
	double b[] = {1.8471 , 1.7471 , 1.6471 , 1.5471 } ;
	LinearEqu equ(4) ;
	equ.setLinearEqu(a , b) ;
	equ.printMatrix() ;
	equ.printLinearEqu() ;

	if(equ.solve())
		equ.printSolution() ;
	else 
		cout << "Fail" << endl ;
}



int main()
{
	testMatrix() ;
	return 0 ;
}