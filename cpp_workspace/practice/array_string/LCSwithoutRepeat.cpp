/*************************************************************************
	> File Name: LCSwithoutRepeat.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月17日 星期四 13时22分59秒
 ************************************************************************/

//求字符串中的最长不重复子串

#include <iostream>
#include <memory.h>

using namespace std;

int fun(string str)
{
    int n = str.size();
    if(n == 0)
    {
        return 0;
    }

    int maxlen = 0;
    int tempmaxlen = 1;
    int i = 0;
    int j = 0;

    int hashtable[256] = {0};
    hashtable[(int)str[0]] = 1;
    for(j = 1 ; j < n ; j++)
    {
        if(!hashtable[(int)str[j]])
        {
            ++hashtable[(int)str[j]];
            tempmaxlen++;
        }
        else
        {
            memset(hashtable,256,0);
            tempmaxlen = 0;
        }

        if(tempmaxlen > maxlen)
        {
            maxlen = tempmaxlen;
        }
    }

    return maxlen;

}

int main()
{
    string str = "abcabcbb";

    int ret = fun(str);
    cout<<ret<<endl;

    return 0;
}

