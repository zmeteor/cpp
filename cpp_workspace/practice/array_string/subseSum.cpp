/*************************************************************************
	> File Name: subseSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月17日 星期二 23时30分15秒
 ************************************************************************/
//给你由n个非负的整数a1, a2, …, an组成的数组，以及另外一个整数S，
//你可以在每个整数前面添上+或者-得到一个算数表达式。
//请问总共有多少中方法使得表达式的计算结果是S。


#include <iostream>

using namespace std;

int subsetSum(int* nums , int len , int target)
{
    int* dp = new int[target + 1];
    for(int i = 0 ; i < target + 1 ; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 0 ; i < len ; i++)
    {
        for(int j = target ; j >= nums[i] ; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[target];
}
int main()
{

    int result = 0;
    int a[5] = {1,1,1,1,1};

    result = subsetSum(a , 5 , 3);

    cout<<result<<endl;

    return 0;
}


