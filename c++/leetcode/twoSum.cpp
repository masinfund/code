#include <bits/stdc++.h>

using namespace std ;

/*
Given an array of integers, return indices of the two
numbers such that they add up to a specific target.
You may assume that each input would have exactly one 
solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> vi ;
    map<int,int> m ;
    for(vector<int>::size_type i = 0 ; i != nums.size() ; ++i){
        int y = target - nums[i] ;
        auto it = m.find(y) ;
        if (it != m.end()){
            vi.push_back(it->second) ;
            vi.push_back(i) ;
            return vi ;
        }
        m.insert(make_pair(nums[i],i)) ;
    }
    
	
}


int main()
{
	vector<int> v{1,2,3,4} ,v1 ;
	int tgt = 6 ;
	v1 = twoSum(v,tgt) ;
	for(auto x : v1)
		cout << x << '\t' ;
	cout << endl ;
	return 0 ;
}