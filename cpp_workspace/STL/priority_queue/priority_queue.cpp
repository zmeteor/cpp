/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月15日 星期四 19时18分56秒
 ************************************************************************/


//优先级队列，出队顺序由优先级决定
#include <iostream>
#include "queue"

using namespace std;

int main()
{
	priority_queue<int> p1 ; //默认情况下 是 最大值优先级队列
	priority_queue<int , vector<int>, less<int> > p2; //提前定义好的预定义函数
	priority_queue<int , vector<int>, greater<int> >  p3; //最小值优先级队列

	p1.push(33);
	p1.push(11);
	p1.push(55);
	p1.push(22);

	cout << "队头元素:" << p1.top() <<endl;
	cout << "队列的大小:" << p1.size() << endl;

	while (p1.size() > 0 )
	{
		cout << p1.top() << " ";
		p1.pop();
	}

	cout << "测试 最小值优先级队列 " << endl;

	p3.push(33);
	p3.push(11);
	p3.push(55);
	p3.push(22);

	cout << " 最小值优先级队列 队头元素:" << p3.top() <<endl;
	cout << " 最小值优先级队列 队列的大小:" << p3.size() << endl;

	while (p3.size() > 0 )
	{
		cout << p3.top() << " ";
		p3.pop();
	}

    return 0;
}

