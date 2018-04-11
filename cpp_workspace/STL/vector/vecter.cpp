/*************************************************************************
	> File Name: vecter.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月14日 星期三 17时04分03秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


void print(vector<int> &v1)
{
    for(vector<int>::iterator it = v1.begin(); it != v1.end() ; it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//1、初始化vector
int main1()
{
    vector<int> v1(10);      //定义10个0，提前准备好内存
    vector<int> v2(3,9);
    vector<int> v3(v2);
    vector<int> v4(v2.begin(),v2.begin()+1);
    v1.push_back(100);   //==v1[11] = 100;
    for(int i = 0 ; i < v1.size() ; i++)
    {
        cout<<v1[i]<<" ";
    }

    return 0;
}

//2 迭代器的种类
/*
typedef iterator pointer;
typedef const_iterator const_pointer;
typedef _STD reverse_iterator<iterator> reverse_iterator;
typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;
*/

int main2()
{
    vector<int> v1;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i+1);
    }

    //顺序遍历
    for(vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

     //逆序遍历
    for(vector<int>::reverse_iterator rit = v1.rbegin() ; rit != v1.rend() ; rit++)
    {
        cout<<*rit<<" ";
    }

    return 0;
}


//3、赋值
int main3()
{
    vector<int> v1;
    vector<int> v2(5,9);
//    v1 = v2;
//    print(v1);
//    v1.assign(v2.begin(),v2.end());
//    print(v1);
    v1.assign(5,0);
//    print(v1);

    v1.swap(v2);
    print(v1);
    print(v2);

    return 0;
}

//4、插入与删除
int main()
{
//     插入
//    vector<int> v1(10);
//    vector<int> v2(5,9);
//    print(v1);
//    v1.insert(v1.begin(),9);
//    print(v1);
//
//    v1.insert(v1.begin()+1,v2.begin(),v2.end());
//    print(v1);


    //删除

    vector<int> v3;
    vector<int> v4(5,5);
    for(int i = 0 ; i < 10 ; i++)
    {
        v3.push_back(i+1);
    }

    v3.pop_back(); //弹出尾部元素
    print(v3);
    //指定位置删除
    v3.erase(v3.begin());
    print(v3);

    //指定区间删除
    v3.erase(v3.begin(),v3.begin()+3);
    print(v3);

    //指定值删除
    v3.insert(v3.end(),v4.begin(),v4.end());
    for(vector<int>::iterator it = v3.begin() ; it != v3.end();)
    {
        if(*it == 5)
        {
            v3.erase(it);   //当删除迭代器所指向的元素的时候,erase删除函数会让it自动下移动
        }
        else
        {
            it++;
        }
    }

    print(v3);

    //vector.resize(num);
     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

    v3.resize(2);
    print(v3);

    v3.front() = 9;
    v3.back() = 0;
    print(v3);

    v3.clear(); //移除所有元素
    bool ret = v3.empty();
    if(ret == true)
    {
        cout<<"the vector is empty!"<<endl;
    }
}

