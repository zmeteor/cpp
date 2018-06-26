/*************************************************************************
	> File Name: largestRectArea.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 22时03分44秒
 ************************************************************************/
//计算直方图的最大矩形面积

#include <iostream>
#include "vector"
#include "stack"

using namespace std;

int largestArea(vector<int> &v1)
{
    int n = v1.size();
    if(n == 0)
    {
        return 0;
    }

    int result = 0;  //存放最大面积
    stack<int> s;

    for(int i = 0 ; i < n ; i++)
    {
        //当栈顶元素大于当前元素，右边界确定，出栈 
        while((!s.empty()) && v1[s.top()] > v1[i])  
        {
            int high = v1[s.top()]; //当前块的高度
            s.pop();
            result = max(result , ((i - 1 - (s.empty() ? (-1):s.top()))*high));
        }
        
        //当栈顶元素小于当前元素，入栈
        s.push(i);
    }

    //将最后的元素出栈
    while(!s.empty())  
    {
        int high = v1[s.top()]; //当前块的高度
        s.pop();
        result = max(result , ((n - 1 - (s.empty() ? (-1):s.top()))*high));
    }

    

    return result;
}

int main()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(1);

    cout<<largestArea(v1)<<endl;

    return 0;
}

