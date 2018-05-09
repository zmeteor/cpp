/*************************************************************************
	> File Name: patition.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 11时42分15秒
 ************************************************************************/

//给定一个数组和一个k，比k大的都放在k的右边，比k小的都放在k的左边
//返回k的下标

#include <iostream>

using namespace std;

int patition(int a[4] , int n , int k)
{
    int l = 0 ;
    int r = n - 1;

    while(l <= r)
    {
        while(l <= r && a[r] >= k)
        {
            r--;
        }

        while(l <= r && a[l] < k)
        {
            l++;
        }

        if(l <= r)
        {
            swap(a[l++],a[r--]);
        }
    }



    return l;
}

int main()
{
    int a[8] = {1,2,2,4,0,1,9,8};
    int k = 2;

    cout<<patition(a,8,k)<<endl;;

    return 0;
}

