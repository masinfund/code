#include "stdafx.h"


struct Rule {
	bool operator()(const int& lhs , const int& rhs){
		return (lhs % 10 < rhs % 10) ;
	}
};

void print(int *a ,int size)
{
	for(int i = 0 ; i < size ; ++i)
		cout << a[i] << endl;
}

struct StudentInfo{
	int id ;
	string name ;
};
struct Student{
	int score ;
	StudentInfo info ;
};

typedef multimap<int , StudentInfo> Map_Stu ;


int BinarySearch(int *a , int size , int p)
{
	// O(log(n))
	int left = 0 ; 
	int right = size - 1 ;
	while(left <= right){
		int mid = left + (right - left) / 2 ;
		if(p == a[mid])
			return mid  ;
		else if( p > a[mid])
			left = mid + 1 ;
		else 
			right = mid - 1 ;
	}
}


int main()
{

// #ifdef LOCAL
// freopen("runpgms","w",stdout);
// #endif // caution 

/*	Map_Stu mp ;
	Student st ;
	string tmp ;
	while(cin >> tmp){
		if(tmp == "Add"){
			cin >> st.info.name >> st.info.id >> st.score ;
			mp.insert(make_pair(st.score,st.info));
		}else if(tmp == "Query"){ 
		// 查找分数低于输入的一个值，无则返回Nobody
			int score ;
			cin >> score ;
			Map_Stu::iterator p = mp.lower_bound(score) ;
			if(p != mp.begin()){
				--p ;
				score = p->first ;//比要查询分数低的最高分
				auto maxp = p ;
				int maxid = p->second.id ;
				while(p != mp.begin() && p->first == score){
					if(p->second.id > maxid){
						maxp = p ;
						maxid = p->second.id ;
					} 
					--p ;
				}
				if(p->first == score){
					if(p->second.id > maxid){
						maxp = p ;
						maxid = p->second.id ;
					}
				}
				cout << maxp->second.name << " " << maxp->second.id 
					 << " " << maxp->first << endl;
				
			}else
				cout << "Nobody" << endl;
		}

	}
*/


	int a[] = {12,45,3,98 , 21 , 7 ,  7} ;
	sort(begin(a) , end(a));
	print(a , 6) ;

	cout << binary_search(a , end(a) , 2) << endl;
	cout << binary_search(a,end(a),98) << endl;

	int *p = lower_bound(begin(a), end(a) , 7) ;
	cout << *p << " , " << p - a << endl;
	p = upper_bound(begin(a) , end(a) , 7) ;
	cout << *p << endl; 

	sort(a , end(a) , Rule()) ;
	print(a,6) ;
	cout << binary_search(a,end(a),7) ;
	cout << binary_search(a , end(a) , 8 , Rule()) ;

	cout << *lower_bound(a , a + 7 , 16 , Rule()) << endl;




	return 0 ;
}