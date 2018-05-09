/*************************************************************************
	> File Name: rmDupElem.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 20时46分02秒
 ************************************************************************/

//删除数组中的重复元素，返回删除后的数组长度

#include <iostream>

using namespace std;

int rmDupElem(int a[10] , int n)
{
    int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[s])
        {
            a[++s] = a[i];
        }
    }

    for(int i = 0 ; i <= s ; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    return ++s;

}

int main()
{
    int a[10] = {1,1,2,3,3,3,4,4,4,5};
    int n = sizeof(a) / sizeof(a[0]);

    cout<<rmDupElem(a , n)<<endl;

    return 0;
}

