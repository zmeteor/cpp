/*************************************************************************
	> File Name: seqheap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 12时56分58秒
 ************************************************************************/

//给定一些元素的入栈顺序和出栈顺序，问是否可能？
// 模拟堆栈即可，如果当前要出栈的元素恰好在栈顶，则必须出栈，否则就入栈。

#include<iostream>
#include"stack"
#include"vector"

using namespace std;

bool isPossible(vector<int> &inp ,vector<int> &out)
{
    if(inp.size() != out.size())
    {
        return false;
    }

    int i = 0;
    stack<int> s;

    for(int j = 0 ; j < out.size() ; j++)
    {
        while(s.empty() || s.top() != out[j])
        {
            if(i >= inp.size())
            {
                return false;
            }
            s.push(inp[i++]);
        }

        s.pop();

    }


    return true;

}

int main()
{
    vector<int> inp;
    inp.push_back(1);
    inp.push_back(2);
    inp.push_back(3);
    inp.push_back(4);
    inp.push_back(5);

    vector<int> out;
    out.push_back(2);
    out.push_back(2);
    out.push_back(3);
    out.push_back(5);
    out.push_back(1);

    if(isPossible(inp , out))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }


    return 0;
}

