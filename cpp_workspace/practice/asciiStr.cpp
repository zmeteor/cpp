/*************************************************************************
	> File Name: asciiStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月26日 星期六 20时46分07秒
 ************************************************************************/
//给我们两个字符串s1和s2，请问如何删除字符使得两个字符串相同，并且被删除的字符的ASCII值的和最小？
//求被删除的字符的ASCII值的和的最小值。

#include <iostream>

using namespace std;

class Solution
{
public:
    int minDelSum(string str1 , string str2)
    {
        int sum1 = 0;
        int sum2 = 0;

        for(int i = 0 ; i < str1.size() ; i++)
        {
            sum1 += str1[i];
        }

        for(int i = 0 ; i < str2.size() ; i++)
        {
            sum2 += str2[i];
        }

        int maxCommon = maxComSub(str1 , str2);

        return sum1+sum2-2*maxCommon;
    }

    //找出ASCCI码最大的公共序列
    int maxComSub(string str1 , string str2)
    {
        int* p = new int[str2.size() + 1];

        for(int i = 0 ; i <= str2.size() ; i++)
        {
            p[i] = 0;
        }


        for(int i = 1 ; i <= str1.size() ; i++ )
        {
            int prev = 0;
            int j = 1;
            for(; j <= str2.size() ; j++)
            {
                int cur = 0;
                if(str1[i - 1] == str2[j - 1])
                {
                    cur = p[i - 1] + str1[i - 1];
                }
                else
                {
                    cur = max(p[j] , prev);
                }

                p[j - 1] = prev;
                prev = cur;
            }

            p[j - 1] = prev;
        }

        int ret = p[str2.size()];
        delete[] p;
        cout<<ret<<endl;

        return ret;
    }

protected:
private:
};


int main()
{
    string str1 = "ABEDF";
    string str2 = "EFABG";

    Solution s;
    cout<<s.minDelSum(str1 , str2)<<endl;



    return 0;
}

