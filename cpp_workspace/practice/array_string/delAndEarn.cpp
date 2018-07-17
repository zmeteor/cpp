/*************************************************************************
	> File Name: delAndEarn.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月17日 星期二 22时42分02秒
 ************************************************************************/
//给你一个整数数组nums，你可以在数组上做如下操作：
//你可以选择任意一个数字nums[i]把它删掉并赚到nums[i]个点。
//此后，你必须删除数组中所有值为nums[i]-1和nums[i]+1的数字。
//你最开始有0个点。请问你如此执行操作最多能从数组上赚到多少个点？
//假设数组中的数字在[1, 10000]的范围之内。
#include <iostream>

using namespace std;

int delAndEarn(int* nums, int len)
{
    int* vals = new int[10001];

    for(int i = 0 ; i < len ;i++)
    {
        vals[nums[i]] += nums[i];
    }
    
    int val1 = 0;
    int val2 = vals[1];
    int maxn = val2;

    for(int i = 2 ; i < 10001 ; i++)
    {
        maxn = max(val2 , vals[i] + val1);
        val1 = val2;
        val2 = maxn;
    }

    return maxn;
}

int main()
{
    int a[6] = {2,2,3,3,3,4};

    int result = delAndEarn(a , 6);

    cout<<result<<endl;

    return 0;
}

