/*************************************************************************
	> File Name: stackUseQueue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 16时11分47秒
 ************************************************************************/
//使用两个队列模拟堆栈

#include <iostream>
#include "queue"

using namespace std;

template<class T>
class mystack
{
public:
    void mypush(T data);
    void mypop(void);
    T mytop(void);
public:
    queue<T> q1;
    queue<T> q2;
};

template<typename T>
void mystack<T>::mypush(T data)
{
    if(!q1.empty())
    {
        q1.push(data);
    }
    else
    {
        q2.push(data);
    }
}

template<class T>
void mystack<T>::mypop(void)
{
    if(!q1.empty())
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }
    else
    {
        while(q2.size() > 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
    }
}

template<class T>
T mystack<T>::mytop(void)
{
    T topdata;
    if(!q1.empty())
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        topdata = q1.front();
        q2.push(q1.front());
        q1.pop();
    }
    else
    {
        while(q2.size() > 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        topdata = q2.front();
        q1.push(q2.front());
        q2.pop();
    }

    return topdata;
}
int main()
{
    mystack<int> s;
    s.mypush(1);
    s.mypush(2);

    cout<<s.mytop()<<endl;

    s.mypop();

    cout<<s.mytop()<<endl;
    
    
    return 0;
}

