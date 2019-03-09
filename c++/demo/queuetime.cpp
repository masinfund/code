#include <iostream>
#include <vector>


using namespace std ;

int queueTime(vector<int> customers, int n)
{
	/*********************************************************
	* calculate queue time , n is counters and the sequence  *
	* is never  change                                       *
	*                                                        *
	*********************************************************/


	int time = 0;
	int *array = nullptr ; //allocate counters memory 
	decltype(customers.size()) i = 0;
	array = new int[n] () ;
	while (1){
		int j ;
		for ( j = 0; j < n && i != customers.size(); ++j) {
			if (!array[j]) {
				array[j] = customers[i]; // insert element to array[j] == 0 ;
				++i;
			}
		}
		for (j = 0; j < n; ++j){
			if (array[j])   // array[j] is True , subtract ;
				array[j]--;
		}
		for (j = 0; j < n; ++j)
			if (array[j] != 0)
				break;
		if (j == n && i == customers.size())
			break;
		else
			time++; // sum of queue time ;
	}
	time++; // plus the last one ;

	delete []array ;
	array = NULL;
	return time;
}
