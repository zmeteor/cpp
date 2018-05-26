/*************************************************************************
	> File Name: sameStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月26日 星期六 13时41分37秒
 ************************************************************************/
//给你两个单词word1和word2，请问至少需要几次删除操作使得word1和word2变得一样？
//每一步你都可以从word1或者word2里删除一个字符。

#include <iostream>
#include "vector"
using namespace std;

class Solution
{
public:
    //递归版，效率太低
    int fun(int i , int j ,string str1 , string str2)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        int ret;
        if(str1[i] == str2[j])
        {
            ret = fun(i-1,j-1,str1,str2) + 1;
        }
        else
        {
            ret = max(fun(i-1,j,str1,str2) , fun(i,j-1,str1,str2));
        }

        return ret;
    }


    //动态规划，求LCS，借助二维数组存之前的结果，时间复杂度O(mn),空间O(mn)
    int fun1(string str1 , string str2)
    {
        if(str1.size() == 0)
        {
            return str2.size();
        }
        if(str2.size() == 0)
        {
            return str1.size();
        }

        int** p = new int*[str1.size()+1];
        for(int i = 0 ; i < str1.size()+1 ; i++)
        {
            p[i] = new int[str2.size()+1];
        }

        for(int i = 0 ; i < str1.size()+1 ; i++)
        {
            for(int j = 0 ; j < str2.size()+1 ; j++)
            {
                p[i][j] = 0;
            }
        }

        for(int i = 1 ; i <= str1.size() ; i++)
        {
            for(int j = 1 ; j <= str2.size() ; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    p[i][j] = p[i-1][j-1] + 1;
                }
                else
                {
                    p[i][j] = max(p[i - 1][j] , p[i][j - 1]);
                }
            }
        }
       int ret = p[str1.size()][str2.size()];
       delete[] p;

       return ret;

    }

    //进一步优化，空间复杂度为O（n）
    int fun2(string str1 , string str2)
    {
        int* p = new int[str2.size() + 1];
        for(int i = 0 ; i < str2.size() + 1 ; i++)
        {
            p[i] = 0;
        }

        for(int i = 1 ; i <= str1.size() ; i++)
        {
            int prev = 0;
            int j = 1;
            for( ; j <= str2.size() ; j++)
            {
                int cur = 0;
                if(str1[i-1] == str2[j-1])
                {
                   cur =  p[j-1] + 1;

                }
                else
                {
                  cur =  max(p[j],prev);
                }
                p[j -1] = prev;
                prev = cur;
            }
            p[j - 1] = prev;
        }

        delete[] p;

        int ret = p[str2.size()];

        return ret;
    }

protected:
private:
};


int main()
{
    string str1 = "hellasfasfaczxcasf2esdasdasgafasasdqeadasfaa";
    string str2 = "hecasasg13rasdasdasdasdasdasd;alskd;asfafasfasfasasdasdasdasdafasfafaf";

    Solution s;
    int ret = 0;

    //cout<< s.fun(str1.size() - 1 , str2.size() - 1 , str1 , str2);

    ret = s.fun1(str1,str2);
    cout<<str1.size() + str2.size() - 2*ret<<endl;

    ret = s.fun2(str1,str2);
    cout<<str1.size() + str2.size() - 2*ret<<endl;


    return 0;
}

