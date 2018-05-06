/*************************************************************************
	> File Name: swapArray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 20时35分25秒
 ************************************************************************/

//将数组中的奇数放到偶数的前面，奇数与奇数的相对位置，偶数与偶数的相对位置不变

#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int len = array.size();
        if(len <= 0)
        {
            return;
        }

        //找到第一个偶数
        int first_even_num = 0;
        while(first_even_num < len && (array[first_even_num] & 0x1) == 1)
        {
            first_even_num++;
        }

        if(first_even_num == len)
        {
            return;
        }

        //将第一个偶数后的奇数依次插入到第一个偶数后面
        int odd_num = first_even_num + 1;
        while(odd_num < len)
        {
            while(odd_num < len && ((array[odd_num] & 0x1) == 0))   //注意：：：==优先级高于＆
            {
                odd_num++;
            }

            if(odd_num == len)
            {
                return;
            }

            if(odd_num > first_even_num)
            {
                int tmp = array[odd_num];
                for(int i = odd_num ; i > first_even_num ; i--)
                {
                    array[i] = array[i - 1];
                }
                array[first_even_num] = tmp;
                first_even_num++;

            }
            odd_num++;

        }

        return;

    }
};

int main()
{
    Solution a;
    vector<int> v1;
    for(int i = 0 ; i < 10 ; i++)
    {
        v1.push_back(i + 1);
    }

    a.reOrderArray(v1);

    for(int i = 0 ; i < 10 ; i++)
    {
        cout << v1[i] << " ";
    }

    cout << endl;

    return 0;
}

