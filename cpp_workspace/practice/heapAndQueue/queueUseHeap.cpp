/*************************************************************************
	> File Name: queueUseHeap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 17时06分28秒
 ************************************************************************/
//使用两个堆栈模拟队列

#include <iostream>
#include "stack"

using namespace std;

template <class T>
class myqueue
{
public:
    void mypush(T data);
    T mypop(void);
public:
    stack<T> m_push;
    stack<T> m_pop;
};

template <class T>
void myqueue<T>::mypush(T data)
{
    m_push.push(data);
}

template <class T>
T myqueue<T>::mypop(void)
{
    T popdata;

    if(m_pop.empty())
    {
        while(!m_push.empty())
        {
            m_pop.push(m_push.top());
            m_push.pop();
        }
    }
    
    popdata = m_pop.top();
    m_pop.pop();

    return popdata;
}


int main()
{
    myqueue<int> q;

    q.mypush(1);
    q.mypush(2);
    cout<<q.mypop()<<endl;
    q.mypush(3);
    cout<<q.mypop()<<endl;
    cout<<q.mypop()<<endl;

    return 0;
}

