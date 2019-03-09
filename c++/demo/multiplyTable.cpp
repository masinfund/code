#include <iostream>
#include <iomanip>

using namespace std ;

int  main()
{
	int i , j ;
	cout << "---Nine-by-nine Multiplication Table---\n" ;
	cout << "---------------------------------------\n" ;
	cout << "  " ;
	for(i = 1 ; i <= 9 ; ++i){
		cout << setw(4) << i ;
	}
	cout << '\n' ;
	cout << "---------------------------------------\n" ;
	for(i = 1 ;i <= 9 ;++i){
		cout << i << ">" ;
		for(j = 1 ; j <= 9 ; ++j){
			if(j > i){
				cout << "    " ;
			}
			else 
				cout << setw(4) << i * j ;
		}
		cout << endl ;
	}
	cout << "--------------------------------------\n" ;
	cout << endl ;
	return 0 ;
}