/*************************************************************************
	> File Name: mergeSortArray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 20时04分01秒
 ************************************************************************/

//合并两个已经排序的数组，不借助额外空间

#include <iostream>

using namespace std;

//从后往前比较，合并
void  mergeSortArray(int a[10] , int m , int b[6] , int n)
{
    int index = m + n - 1;
    cout<<index<<endl;
    m--;
    n--;
    while(m >= 0 && n >= 0)
    {
        if(a[m] > b[n])
        {
            a[index--] = a[m--];
        }
        else
        {
            a[index--] = b[n--];
        }
    }

    if(m > 0)
    {
        a[index--] = a[m--];
    }

    if(n > 0)
    {
        a[index--] = b[n--];
    }
}

int main()
{
    int a[10] = {1,4,8,9};
    int b[6] = {2,3,6,20,90,200};

    mergeSortArray(a , 4 , b , 6);

    for(int i = 0 ; i < 10 ; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}

