/*************************************************************************
	> File Name: maxArrayK.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 23时03分24秒
 ************************************************************************/
//给定一个数组a［0..n],还有一个值k，
//计算数组b［i］ = max(a[i – k + 1.. i]) 注意认为负数下标对应值是无穷小

//思路：利用划动窗口和双短队列


#include <iostream>
#include "deque"
#include "vector"

using namespace std;

void makeV2(vector<int>& v1 , vector<int>& v2 , int k)
{
    int n = v1.size();
    deque<int> q;

    for(int i = 0 ; i < n ; i++)
    {
        //处理过期
        while(!q.empty() && ((i - q.front()) >= k))
        {
            q.pop_front();
        }

        //队尾的元素无用
        while(!q.empty() && (v1[q.back()] < v1[i]))
        {
            q.pop_back();
        }

        q.push_back(i);

        v2.push_back(v1[q.front()]);
    }
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    int k = 3;

    v1.push_back(5);
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(6);

    makeV2(v1 , v2 , k);

    for(int i = 0 ; i < v1.size() ;i++)
    {
        cout<<v2[i]<<endl;
    }
    return 0;
}

