/*************************************************************************
	> File Name: stock1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月25日 星期日 12时41分29秒
 ************************************************************************/


/*
 问题：你得到一系列在接下来几天的股票价格，
 现在你被允许只用一次交易（就是买进再卖出）来获取最大利益。
*/
//测试样例：
//[10,22,5,75,65,80],6
//返回：75

//采用动态规划
#include <stdio.h>
#include <stdlib.h>

#define N 6

int max_profit(int price[N] , int len , int index[2]);

int main()
{
    int result = 0;  //最后收益
    int price[N] = {10,22,5,75,1,80};
    int index[2] = {0};  //保存买入和卖出的时间

    result = max_profit(price,N,index);

    printf("buy:%d\t sell:%d\nThe Max profit is %d\n",index[0],index[1],result);

    return 0;
}

int max_profit(int price[N] , int len , int index[2])
{
    if(len <= 0)
    {
        return 0;
    }

    int min_buy = price[0];
    index[0] = 1;
    int i = 0;
    int result = 0;  //收益

    for(i = 1; i < len-1 ; i++)
    {
        if(price[i] > min_buy)
        {
            //判断今日卖出是否收益最大
            if(result < price[i] - min_buy)
            {
                result = price[i] - min_buy;
                index[1] = i+1;
            }
        }
        else
        {
            min_buy = price[i];  //买入最低
            index[0] = i+1;
        }
    }

    return result;
}

