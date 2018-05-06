/*************************************************************************
> File Name: longestconsecut.cpp
> Author: 
> Mail: 
> Created Time: 2018年05月06日 星期日 16时31分49秒
************************************************************************/

#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

class Bound
{
    public:
        int low;
        int high;
        
        Bound(int l = 0 ,int h = 0):low(l),high(h){};
};


int longestConsecutive(vector<int> v1)
{
    unordered_map<int , Bound> mp;
    int maxlen = 0;
    vector<int>::iterator it;

    for(it = v1.begin() ; it != v1.end() ; it++)
    {
        if(mp.count(*it))  //若元素重复，则跳过
        {
            continue;
        }

        int local = *it;
        int low = local;
        int high = local;

        //若当前元素是序列的后序 ,更新low
        if(mp.count(local - 1))
        {
            low = mp[local - 1].low;
        }

        //若当前元素是序列的前序 ,更新high
        if(mp.count(local + 1))
        {
            high = mp[local + 1].high;
        }

        mp[low].high = mp[local].high = high; //作为序列后驱加入
        mp[high].low = mp[local].low = low;  //作为序列前去加入

        if(high - low + 1 > maxlen)
        {
            maxlen = high - low + 1;
        }

    }

    return maxlen;
}

int main()
{
    vector<int> v1;
    /*v1.push_back(0);
    v1.push_back(-3);
    v1.push_back(-2);
    v1.push_back(-1);
    v1.push_back(8);
    v1.push_back(9);
    */
    v1.push_back(6);
    v1.push_back(9);
    v1.push_back(7);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(8);


    cout<<longestConsecutive(v1)<<endl;

    return 0;
}
