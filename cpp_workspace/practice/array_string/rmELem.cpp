/*************************************************************************
	> File Name: rmELem.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 21时57分12秒
 ************************************************************************/
//删除数组中的指定元素，返回修改后的长度允许更改顺序

#include <iostream>
#include "vector"

using namespace std;

//方法一：借助vector的erase方法
int rmElement1(vector<int> v1 , int rmnum)
{
    int n = v1.size();
    if(n == 0)
    {
        return 0;
    }

    vector<int>::iterator it;
    for(it = v1.begin() ; it != v1.end() ; it++)
    {
        if(*it == rmnum)
        {
            it = v1.erase(it);
            it--;   //执行erase之后，it指向下一个元素，必须--
        }

    }


    return v1.size();
}

//方法二：将每一个待删除的元素与数组的最后一个元素交换，size--

int rmElement2(vector<int> v1 , int rmnum)
{
    int n = v1.size();
    if(n == 0)
    {
        cout<<"n"<<endl;
        return 0;
    }

    cout<<"before rm2"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < n ; i++)
    {
        if(v1[i] == rmnum)
        {
            v1[i] = v1[n-1];
            i--;  //检测交换之后的元素是否应该删除
            n--;  //长度--
        }


    }

    cout<<"rm2"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    return n;
}


int main()
{
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(4);
    v1.push_back(4);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(4);

    int rmnum = 4;
    cout<<rmElement1(v1 , rmnum)<<endl;
    cout<<rmElement2(v1 , rmnum)<<endl;

    return 0;
}

