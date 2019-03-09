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


// map set 
void test01()
{
	map<string , size_t> word_count ; 
	set<string> exclude = {"The","But", "And","Or","An","A",
							"the","butt","and","or","an","a"} ;
	string word ;
	ifstream ifs("in.dat",ios::binary) ;
	while(ifs >> word)
		if(exclude.find(word) == exclude.end()){
			++word_count[word] ;
		}
	for(const auto &i : word_count)
		cout << i.first << " occurs " << i.second	
			 << ((i.second > 1) ? " times" : " time") << endl;
	ifs.close() ;
}

void test02()
{
	char ch ;
	while((ch = cin.get()) != '\n')
		cout << ch << endl;
	cin.get(ch) ;
	cout << ch << endl;
	cout << "getbuf " ;
	char buf[256] = {0} ;
	cin.get(buf,255); // 从缓冲区读一个字符串
	cout << buf << endl;
	cout << "getline" ;
	cin.getline(buf,255) ; // 读取一行数据,不读换行符
	cout << buf << endl;

	cout << "get ignore " ;
	cin.get(ch) ;
	cout << ch << endl;
	cin.ignore() ; // 忽略当前的字符
	cin.get(ch) ;
	cout << ch << endl;

	cout << "peek" ;
	ch = cin.peek() ; // 看一下缓冲区，返回第一个字符
	if(ch >= '0' && ch <= '9'){
		cout << "number" << endl;
	}
	else
		cout << "???" << endl;

	cout << "putback" ;
	cin.get(ch) ;
	cout << ch << endl;
	cin.putback(ch) ;
	cin.getline(buf,255) ;
	cout << buf << endl;

	//输出
	cout << "put" ;
	cout.put('h');
	cout << '\n' ;
	cout << "write" ;
	cout.write("hello jie\n",100);
	cout << buf ;
   // 格式化输出
	int number = 10 ;
	cout.unsetf(ios::dec) ; // 卸载当前默认的10进制输出方式
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << number << endl;
	cout.unsetf(ios::hex) ;
	cout.setf(ios::dec) ;
	cout << number << endl;

	cout << "width\n" ;
	cout.fill('*') ;
	cout.setf(ios::left) ;
	cout.width(10) ;

}



int sum (const vector<int> &v , int low , int high)
{
	if(low == high)
		return v[low] ;
	else {
		int mid = (low + high) >> 1 ;
		return sum(v,low,mid) + sum(v,mid + 1,high) ;
	}
}
int sum(const int *a , int n){
	if(n < 1)
		return 0 ;
	else 
		return sum(a , n - 1) + a[n - 1] ;
}


/*trail-recursion
If all the recursive calls in a function appear at the end of
the function, we call this function is trail-recursion.
*/

int sumTrail(const int *a , int n , int sum = 0)
{
	if(n == 0 )
		return sum  ;
	else 
		return sumTrail(a + 1 , n - 1 ,sum + a[1]) ;
}

double fact(int n , int num )
{
	if(n <= 1)
		return num ;
	else 
		return fact(n - 1, n * num) ;
}

void bubblesort1A(int A[] , int n){
	bool sorted = false ;
	while(!sorted){
		sorted = true ;
		for(int i = 1 ; i < n ; ++i)
			if(A[i - 1] > A[i]){
				swap(A[i - 1] , A[i]) ;
				sorted = false ;
			}
	}
	// 缩短待排序序列的有效长度
	n-- ; 
}


int squareUniqueNum(vector<int> &v){
	//有序数组每个数平方后， 求其中不同数字的个数
	int len(0) , n = v.size() , pre(v[0]) ;

	for(size_t i = 0 ; i < n / 2 ; ++i){
		if(v[i] == v[n - 1 - i] ){
			len++ ;
		}
		else {
			if((v[i] + v[n - 1 - i]) < 0 ){
				pre = v[n - 1 - i] ;
				len += 2 ;
			}
			else if((v[i] + v[n - 1 - i]) > 0){
				pre = v[i] ;
				len += 2 ;
			}
			else if(pre != abs(v[i]))
				len++ ;
			
		}
	}
	if(pre != v[n / 2])
		len++ ;
	return len ;
}

int main(int argc, char const *argv[])
{

	// test01() ;
	vector<int> v{-5,-3,-1,1,1,2} ;
	cout << squareUniqueNum(v) << endl;
    return 0;
}

