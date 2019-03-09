
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <climits>
#include <cctype>
#include <array>
#include <iterator>
#include <functional> // bind
#include <typeinfo>
//对某个空指针p执行typeid(*p)  throw bad_typeid
#include <initializer_list>
#include <windows.h>
#include <memory>
#include <cassert> 
#include <stdexcept>
#include <deque>
#include <list>
#include <stack>
#include <forward_list>
#include <utility>
#include <locale>


#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;


void test01()
{

	ofstream  ofs("out.dat" , ios::binary | ios::app) ;
	ifstream ifs("in.dat" , ios::binary ) ;
	string s1 ;
	getline(ifs,s1);
	for(auto &ch : s1)
		ch = toupper(ch) ;
	ofs << s1 << endl;
	ofs.close();
	ifs.close() ;

	

}


int main(int argc, char const *argv[])
{


    return 0;
}

