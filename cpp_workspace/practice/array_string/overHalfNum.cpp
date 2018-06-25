/*************************************************************************
	> File Name: overHalfNum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月25日 星期一 20时09分22秒
 ************************************************************************/

//找出数组中超过一半的数字
//实现思路：每次扔掉两个不同的数，众数不变
//如果扔掉一个众数，和一个非众数如果扔掉两个非众数


#include<iostream>
using namespace std;
#include <iostream>

int findNum(int a[] , int size)
{
    int count = 0;  //记录当前数字出现的次数
    int num = -9999;   //记录当前数字

    for(int i = 0 ; i < size ; i++)
    {
        if(count == 0)
        {
            num = a[i];
            count = 1;
        }
        else if(num == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return num;
}
int main()
{
    int a[8] = {1 , 2 ,1 , 2 , 3 , 1 , 1 , 9};

    int result = findNum(a , sizeof(a) / sizeof(a[0]));

    cout<<"the result num  is: "<<result<<endl;

    return 0;
}

