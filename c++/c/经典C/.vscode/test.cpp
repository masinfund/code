#include<iostream>
#include <cstring>
using namespace std ;
#define N 1000 

class Base {
    public:
        Base() { }
        Base(int i) : b(i) {}
        virtual void fun() { cout << "Base" << endl ;}
    private:
        int b ;
};
class Base1 : public Base{
    public:
    Base1(int i) : Base(i) {}
    Base1() {}
    virtual void fun() {cout << "1" << endl ;}
};
class Derived : public Base1 {
    public:
        Derived() {}
        Derived(int i , int j) : Base1(i) , d(j) { }
    private:
        int d ;
        void fun() { cout << "Derived" << endl ;}
};

void func(Base *p){
    p->fun() ;
}

int main(int argc, char const *argv[])
{
    Base *p ;
    Base1 b1 ;
    Derived d1 ;
    p = &b1 ;
    p->fun() ;
    func(p) ;
    p = &d1 ;
    p->fun() ;
    func(p) ;
    p = new Base ;
    func(p) ;
    p->fun() ;
    delete p ;

    return 0;
}
