#include "Sales_dataTest.h"
#include <iostream>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
	Sales_dataTest total ;

	if(read(cin,total)){
		Sales_dataTest trans ;
		while(read(cin,trans)){
			if(total.isbn() == trans.isbn())
				total.combine(trans) ;
			else {
				print(cout,total) << endl; 
				total = trans ;
			}
		}
		print(cout,total) << endl ;
	}
	else {
		cerr << "NO data!" << endl ;
	}
	return 0;
}