/*************************************************************************
	> File Name: localmin.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月22日 星期二 16时02分46秒
 ************************************************************************/
//求数组的局部最小值

#include <iostream>
#include "vector"

using namespace std;

int findLocalMin(const vector<int> &v)
{
    int lo = 0, hi = v.size() - 1;
    while(lo < hi)
    {
        int mid = (lo + hi) >> 1;
        if(v[mid] > v[mid + 1])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}


int main()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(7);
    v1.push_back(6);
    v1.push_back(3);

    int index = findLocalMin(v1);
    cout<<v1[index]<<endl;


    return 0;
}

