
#include "stdafx.h"


class Complex {
	public :
	friend ostream& operator <<(ostream &out , const Complex &c) ;
	friend istream& operator >>(istream &in , Complex &c) ;
	friend Complex operator *(const Complex &c1 , const Complex &c2) ;

	Complex(const Complex &) ;
	Complex(double r = 0.0 , double i = 0.0) : real(r) , imag(i) { }
	const Complex operator +(const Complex &c2) const ;
	Complex operator -(const Complex &c2) const ;
	Complex& operator =(const Complex &c2) ;
	Complex& operator +=(const Complex &c) ;
	Complex& operator -=(const Complex &c) ;
	void display() const ;
	private :
	double real ;
	double imag ;
} ;

Complex::Complex(const Complex &c) : real(c.real) , imag(c.imag) {}

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

Complex&
Complex:: operator +=(const Complex &c)
{
	real += c.real ;
	imag +=c.imag ;
	return *this ;

}
Complex& Complex:: operator -=(const Complex &c)
{
	real -= c.real ;
	imag -= c.imag ;
	return *this ;
}

const Complex Complex::operator +(const Complex &c2) const {
	
	return (Complex(real + c2.real , imag + c2.imag)) ;
}
// const Complex * const this ;
Complex Complex::operator -(const Complex &c2) const {
	return Complex(real - c2.real , imag + c2.imag) ;
}
void Complex::display() const {
	cout << "(" << real << " , " << imag << ")" << endl ;
}
