/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月16日 星期五 10时25分17秒
 ************************************************************************/


#include <iostream>
#include "list"

using namespace std;


//list的基本操作
int main1()
{
    list<int> l;
    for(int i = 0; i < 10; i++)
    {
        l.push_back(i); //尾插法
    }
    cout<<"list的大小:"<<l.size()<<endl;

    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;
    list<int>::iterator it;
    //list不能随机访问
    it = l.begin();
    it++;
    it++;
    it++;
    //it = it + 5;  //error 不支持随机的访问容器
    l.insert(it, 100);
    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }

    //结论1 链表的结点index 序号是从0号位置开始
    //在3号位置插入元素, 让原来的3号位置变成4号位置  原来的4号位置变成5号位置

    return 0;
}

//list 删除
int main()
{
    list<int> l;
    cout<<"list的大小:"<<l.size()<<endl;
    for(int i = 0; i < 10; i++)
    {
        l.push_back(i); //尾部插入元素 尾插法
    }
    cout<<"list的大小:"<<l.size()<<endl;

    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //区域删除
    list<int>::iterator it1 = l.begin();
    list<int>::iterator it2 = l.begin();
    it2++;
    it2++;
    it2++;

    l.erase(it1, it2);

    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    l.insert(l.begin(), 100);
    l.insert(l.begin(), 100);
    l.insert(l.begin(), 100);

    l.erase(l.begin());

    //删除所有100
    //法一：
    //l.remove(100);
    //法二：
    for(list<int>::iterator it = l.begin();it != l.end();)
    {
        if(*it == 100)
        {
            l.erase(it);
        }
        else
        {
            it++;
        }
    }
//    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
//    {
//        cout<<*it<<" ";
//    }
//    cout<<endl;

    l.reverse();
    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}


