/*************************************************************************
	> File Name: swap01.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月20日 星期日 23时35分46秒
 ************************************************************************/

//将字符串0在前，1在后，返回交换的最小次数

#include <iostream>

using namespace std;

int sortStr(string& str)
{
    int n = str.size();
    if(n == 0)
    {
        return 0;
    }

    int i = 0;
    int j = n - 1;
    int sum = 0;

    while(i < j)
    {
        while(i < j && str[i] == '0')
        {
            i++;
        }

        while(j > i && str[j] == '1')
        {
            j--;
        }

        if(i < j)
        {
            swap(str[i++] , str[j++]);
            sum++;
        }


    }

    cout<<str<<endl;
    return sum;

}

int main()
{
    string str = "100000001";

    cout<<sortStr(str)<<endl;

    cout<<str<<endl;

    return 0;
}

