/*************************************************************************
	> File Name: findPairNum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 13时39分41秒
 ************************************************************************/

//给定array和sum,找出所有和为sum的pair

#include <iostream>
#include "unordered_map"
#include "vector"

#define size 7

using namespace std;

void findPair(int num[size] , int sum)
{
    unordered_map<int , vector<int> > mp;
    unordered_map<int , vector<int> >::iterator it;
    
    for(int i = 0 ; i < size ;i++)
    {
        it = mp.find(sum-num[i]);
        if(it == mp.end())
        {
            vector<int> v1;
            v1.push_back(i);
            mp.insert(make_pair(sum-num[i] , v1));
        }
        else
        {
            mp[sum-num[i]].push_back(i);
        }

    }


    
    for(int j = 0 ; j < size ;j++)
    {
        it = mp.find(num[j]);
        if(it == mp.end())
        {
            continue;
        }
        else
        {
            vector<int>::iterator it2 = it->second.begin();
            while(it2 != it->second.end())
            {
                if(*it2 > j)
                {
                    cout<<j<<", "<<*it2<<": ";
                    cout<<num[j]<<" "<<num[*it2]<<endl;
                }
                it2++;
            }

        }

    }

}

int main()
{
    int num[7] = {1,2,3,0,2,3,5};
    int sum = 5;
    
    findPair(num , sum);

    return 0;
}
