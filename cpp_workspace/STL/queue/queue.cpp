/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月15日 星期四 12时10分35秒
 ************************************************************************/

#include <iostream>
#include "deque"
#include "algorithm"

using namespace std;


void printD(deque<int> &d)
{
	for (deque<int>::iterator it=d.begin(); it!=d.end(); it++ )
	{
		cout << *it << " ";
	}
	cout<<endl;
}

//deque的初始化
int  main()
{
	deque<int> d1;

	//尾插
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);

    //头插
	d1.push_front(-1);
	d1.push_front(-2);
	d1.push_front(-3);

	cout << "头部元素:" << d1.front() <<endl;
	cout << "尾部元素:" << d1.back() << endl;
	printD(d1);

	d1.pop_front();  //弹出头部元素
	d1.pop_back();    //弹出尾部元素
	printD(d1);
	cout <<endl;

	//查找 -3 在数组下标的值
	deque<int>::iterator it =  find(d1.begin(), d1.end(), -3 );
	if (it != d1.end())
	{
		cout<< distance(d1.begin(), it) <<endl;
	}
	else
	{
		cout << "not find" << endl;
	}


	return 0;
}

