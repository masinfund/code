//#include "stdafx.h"

//#include <iostream>
#include <fstream>
//using namespace std ;
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
int main()
{
    ifstream in("noinput");
    if (in)
    {
        map<int, string> m;
        int stuNum, currNum, i;
        in >> stuNum >> currNum;
        cout << stuNum << "  " << currNum << endl;
        for (i = 0; i < stuNum; ++i)
        {
            string name;
            int tmp, avg = 0;
            in >> name;
            for (int j = 0; j < currNum; ++j)
            {
                in >> tmp;
                avg += tmp;
            }
            avg /= currNum;
            m.insert(make_pair(avg, name));
        }

        vector<pair<int, string>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<int, string> &lhs, const pair<int, string> &rhs) {
            if (lhs.first > rhs.first)
                return true;
            else if (lhs.first == rhs.first && lhs.second < rhs.second)
                return true;
            else
                return false;
        });

        i = 1;
        for (auto it = v.begin(); it != v.end(); ++it, ++i)
        {
            cout << i << " " << it->second << "  " << it->first << endl;
        }
    }
    in.close();
    return 0;
}
