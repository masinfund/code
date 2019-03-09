#include <bits/stdc++.h>
using namespace std ;
int main()
{
	vector<int> v ;
	multimap<int , string> msg ;
	ifstream ifs("in") ;
	string num  ;
	int score , cnt = 0 ;
	
	getline(ifs,num) ;


	while(ifs >> num >> score) ;
	msg.insert(make_pair(score,num)) ;
	for(const auto &i : msg)
		cout << (++cnt) << "  " << i.second << " " 
			 << i.first << endl ;
	ifs.close() ;

	return 0 ;

}