/*************************************************************************
	> File Name: prime.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月22日 星期二 12时57分38秒
 ************************************************************************/
//输出质数

#include <iostream>
#include "vector"

using namespace std;

void comPrime(int n)
{
    if(n < 1)
    {
        return;
    }
    vector<int> v1(1,2);  //存储质数
    int c = 3;

    vector<int>::iterator it;
    while(c <= n)
    {

        bool isprime = true;
        for(it = v1.begin() ; it != v1.end() ; it++)  //利用之前的质数，减少计算
        {
            if(c % (*it) == 0)
            {
                isprime = false;
            }
        }

        if(isprime)
        {
            v1.push_back(c);
        }

        c += 2;
    }

    for(it = v1.begin() ; it != v1.end() ; it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl<<"total: "<<v1.size()<<endl;;


}

int main()
{
    comPrime(72);
    return 0;
}

