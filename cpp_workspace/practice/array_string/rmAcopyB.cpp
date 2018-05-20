/*************************************************************************
	> File Name: rmAcopyB.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月20日 星期日 13时28分25秒
 ************************************************************************/

//删除一个数组中的'a'，复制'b'

#include <iostream>

using namespace std;

#define len 20

void fun(char a[len])
{
    int i = 0;
    int realLen = 0;
    int numb = 0;
    int n = 0;

    //删除所有的'a'，并统计'b'的个数
    while(a[i] != '\0')
    {
        if(a[i] != 'a')
        {
            a[n++] = a[i];
        }

        if(a[i] == 'b')
        {
            numb++;
        }
        i++;
    }
    realLen = i;
    a[n] = '\0'; //将字符串截断

    //避免覆盖，逆向复制
    int tail = realLen + numb - 1;
    for(i = realLen - 1 ; i >= 0 ;i--)
    {
        if(a[i] == 'b')
        {
            a[tail--] = 'b';
            a[tail--] = 'b';
        }
        else
        {
            a[tail--] = a[i];
        }
    }


}

int main()
{
    char a[20] = {'a','b','c','c','b','c'};

    fun(a);

    for(int i = 0 ; i < 20 ; i++)
    {
        cout<<a[i];
    }
    cout<<endl;


    return 0;
}

