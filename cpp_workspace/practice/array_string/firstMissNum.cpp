/*************************************************************************
	> File Name: firstMissNum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月24日 星期四 23时05分14秒
 ************************************************************************/
//给一个数组，找到从1开始,第一个不在里面的正整数。
//例如［3,4,-1,1]输出2。

#include <iostream>

using namespace std;

//让a[i] == i + 1
//每次循环，要么i + 1 ， 要么 n - 1 ； 要么有一个数被放到正确的位置
int firstMissingPosistive(int a[] , int n)
{
    for(int i = 0 ; i < n ; )
    {
        if(a[i] == i+1 )
        {
            ++i;
        }
        else if((a[i] <= i) || (a[i] > n) || (a[a[i] - 1] == a[i]) )  //被处理过||超出处理的范围||重复出现
        {
            a[i] = a[--n];  //简单删除一个数
        }
        else
        {
            swap(a[i] , a[a[i] - 1]);
        }

    }

    return n+1;
}


int main()
{
    int a[6] = {-1 , 6  , 5, 4  ,3 , 2};
    int ret = firstMissingPosistive(a , 6);

    cout<<ret<<endl;

    return 0;
}

