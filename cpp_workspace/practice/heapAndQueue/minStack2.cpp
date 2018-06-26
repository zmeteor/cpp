/*************************************************************************
	> File Name: minStack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 17时44分17秒
 ************************************************************************/
//支持最小值查询的堆栈的优化，minstack去重

#include <iostream>
#include "stack"

using namespace std;

template <class T>
class Minstack1
{
public:
    void mypush(T data);
    void mypop(void);
    T    getMin(void);

public:
    stack<T> basestack;   //正常使用
    stack<T> minstack;    //保存最小值
};

template <class T>
void Minstack1<T>::mypush(T data)
{
    basestack.push(data);
    if(minstack.empty() || data <= minstack.top())  //<=存在两个最小值
    {
        minstack.push(data);
    }

}

template <class T>
void Minstack1<T>::mypop(void)
{
    if(basestack.top() == minstack.top())
    {
        minstack.pop();
    }
    basestack.pop();
}

template <class T>
T Minstack1<T>::getMin()
{
    return minstack.top();
}
int main()
{
    Minstack1<int> s;
    s.mypush(3);
    s.mypush(5);
    s.mypush(2);
    s.mypush(1);
    s.mypush(4);
    
    cout<<s.getMin()<<endl;
    s.mypop();
    cout<<s.getMin()<<endl;
    s.mypop();
    cout<<s.getMin()<<endl;

    return 0;
}

