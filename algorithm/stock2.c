/*************************************************************************
	> File Name: stock2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月25日 星期日 13时21分24秒
 ************************************************************************/


//最多交易两次


/*
在股市的交易日中，假设最多可进行两次买卖(即买和卖的次数均小于等于2)，
规则是必须一笔成交后进行另一笔(即买-卖-买-卖的顺序进行)。给出一天中的股票变化序列，
请写一个程序计算一天可以获得的最大收益。请采用实践复杂度低的方法实现。
*/

//给定价格序列prices及它的长度n，请返回最大收益。保证长度小于等于500。



//测试样例：
//[10,22,5,75,65,80],6
//返回：87


//在遍历价格差找最大获益时，可以首位同时进行。可以用双向动态规划的思想来做。


#include <stdio.h>
#include <stdlib.h>

#define N 6

int max(int a,int b)
{
    return (a > b)?a:b;
}

int min(int a,int b)
{
    return (a < b)?a:b;
}

int max_profit(int price[N],int len);

int main()
{
    int result = 0;
    int price[N] = {10,22,5,75,65,80};

    result = max_profit(price,N);

    printf("The max profit is %d\n",result);

    return 0;
}

int max_profit(int price[N],int len)
{

    if(len <= 0)
    {
        return 0;
    }

    int i;
    int result = 0;

    int pre_profit[N] = {0};  //顺序存储0~i之间的最大收益
    int post_profit[N] = {0}; //逆序存储N~i之间的最大收益

    int min_buy = price[0];

    for(i = 1 ; i < len ; i++)
    {
        min_buy = min(min_buy , price[i]);
        pre_profit[i] = max(pre_profit[i-1] , price[i] - min_buy);
    }

    for(i = 0 ; i < len ; i++)
    {
        printf("%d\t",pre_profit[i]);
    }
    putchar(10);

    int max_sell = price[len - 1];


    for(i = len - 2 ; i >= 0 ; i--)
    {
        max_sell = max(max_sell , price[i]);
        post_profit[i] = max(post_profit[i + 1] , max_sell - price[i]);
    }

    for(i = 0 ; i < len ; i++)
    {
        printf("%d\t",post_profit[i]);
    }
    putchar(10);



    //两者相加的最大值就是最大收益
    for(i = 0 ; i < len ; i++)
    {
        result = max(result , pre_profit[i] + post_profit[i]);
    }

    return result;
}

