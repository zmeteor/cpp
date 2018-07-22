/*************************************************************************
	> File Name: nextHighTemp.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 19时44分30秒
 ************************************************************************/
//给定一个存储每天温度的整数数组，如何生成另外一个数组其中每个数字表示我们还需要等待几天才出现更高的温度？
//如果以后没有更高温度的日子，则用0表示。


/*思路*/

//借助栈来实现一遍遍历,栈中存储下标，变于计算
//从数组第一个元素开始入栈，直到遇到比top大的值就出栈
//此时，top的结果 = 当前元素下标-top

/*时间复杂度为O(n)、空间复杂度O(n)*/
#include <iostream>
#include "stack"

using namespace std;

void nextHighTemp(int* array , int len)
{
    int* result = new int[len];

    stack<int> s;
    for(int i = 0 ; i < len ; i++)
    {
        while(!s.empty() && array[i] > array[s.top()])
        {
            int prev = s.top();
            s.pop();
            result[prev] = i - prev;
        }
        s.push(i);
        
    }

    cout<<"输出结果是："<<endl;
    for(int i = 0 ; i < len ; i++)
    {
        cout<<result[i]<<" ";
    }
    
    cout<<endl;
}

int main()
{
    int a[8] = {73,74,75,71,69,72,76,73};
    nextHighTemp(a , 8);

    return 0;
}

