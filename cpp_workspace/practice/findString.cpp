/*************************************************************************
	> File Name: findString.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月30日 星期三 12时35分38秒
 ************************************************************************/

//一个数组，所有元素都出现了两次，只有两个数只出现了一次，求这两个数。
#include <iostream>

using namespace std;

void findOnceExisitNum(int a[] , int n)
{

    int xXory = 0;

    //利用异或的运算性质，最终的xXor是两个不同的数的异或值
    for(int i = 0 ; i < n ; i++)
    {
        xXory ^= a[i];
    }

    //找到二进制表示中某一个为1的位，把所有的数按这位为1和为0分开。
    int mask = 1;
    while((mask & xXory) == 0)
    {
        mask <<= 1;
    }
    // for (; (xXory & mask) == 0; mask <<= 1);

    int x = 0;
    int y = 0;

    //划分之后的两个子数组中各有一个出现一次的数字，再次利用异或的性质即可
    for (int i = 0; i < n; ++i)
    {
        if(a[i] & mask)
        {
            x ^= a[i];
        }
		else
        {
            y ^= a[i];
		}
    }

    cout<<x<<" "<<y<<endl;
}


int main()
{
    int a[6] = {1,1,2,3,4,4};

    findOnceExisitNum(a , 6);

    return 0;
}

