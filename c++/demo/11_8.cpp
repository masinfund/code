#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <iterator>

using namespace std ;

int main()
{
	int n , m ;
	cin >> n >> m ;
	m = floor(m * 1.5) ;
	multimap<int , int > ms ;
	while(n--){
		int num ;
		int grade ;
		cin >> num >> grade ;
		ms.insert(make_pair(grade,num));
	}

	vector<pair<int , int > > v(ms.begin(), ms.end());

	sort(v.begin() , v.end(), [](const pair<int , int >& a ,  const pair<int , int >& b){
		if(a.first < b.first)
			return true ;
		else if(a.first == b.first && a.second > b.second)
			return true;
		else 
			return false;
		});
	vector<pair<int , int> >::iterator p = upper_bound(v.begin() , v.end() ,
		(v.rbegin() + m - 1)-> first  - 1 , [](int a ,  const pair<int , int >& b)
		{
			return a < b.first ;
		}) ;

	cout << p->first<< " " << distance(p , v.end()) << endl; ;

	for(auto it = v.rbegin() ; it != v.rbegin() + (distance(p,v.end() )); ++it)
		cout << it->second <<  " " << it->first << endl;

	return 0 ;
}






// 88 5
// 1422 95
// 8805 95
// 9848 90
// 4162 88
// 6731 88
// 5 3
// 2538 78
// 7972 88
// 6001 70
// 9323 89
// 2783 95
/*

5 3
2538 78
7972 88
6001 70
9323 89
2783 95

6 3
9848 90
6731 88
1422 95
7483 84
8805 95
4162 88

78 4
2783 95
9323 89
7972 88
2538 78


*/