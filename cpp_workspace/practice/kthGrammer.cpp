/*************************************************************************
	> File Name: kthGrammer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月28日 星期一 22时10分19秒
 ************************************************************************/

//第一行为0，接下来每行中将上一行的0换成01，把1换成10
//求第N行第K个字符是什么

#include <iostream>

using namespace std;

//法一：   时间和空间复杂度均为O(n)
int kthGrammar(int n , int k)
{
    if(n == 1)
    {
        return 0;
    }

    return k > (1 << n - 2) ? 1 - kthGrammar(n - 1 ,k - (1 << n - 2)) : kthGrammar(n - 1 , k);
}

//法二
int kthGrammar2(int n , int k)
{
    if(k == 1)
    {
        return 0;
    }

    return ((k & 1) == 0) ? 1-kthGrammar2(n , k >> 1) : kthGrammar2(n , (k + 1) >> 1);
}

int main()
{
    int n = 4;
    int k = 3;

    //int kth = kthGrammar(n , k);
    int kth = kthGrammar2(n , k);

    cout<<"第 "<<n<<" 行"<<" ，第 "<<k<<" 个数是："<<kth<<endl;

    return 0;
}

