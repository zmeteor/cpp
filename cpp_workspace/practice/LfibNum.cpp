/*************************************************************************
	> File Name: LfibNum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月20日 星期一 21时19分30秒
 ************************************************************************/
/*严格单调递增的数组，请问数组里最长的斐波那契序列的长度是多少？
 * 例如，如果输入的数组是[1, 2, 3, 4, 5, 6, 7, 8]，
 * 由于其中最长的斐波那契序列是1, 2, 3, 5, 8，因此输出应该是5。
 * */
#include <iostream>
#include "unordered_map"

using namespace std;

int longestFibNum(int a[] , const int len)
{
    cout<<len<<endl;
    if(len == 0)
    {
        return 0;
    }

    unordered_map<int ,int> hmap;

    for(int i = 0 ; i < len ; i++)
    {
        hmap.insert(make_pair(a[i] , i));
    }

    int** lengths = new int*[len];
    lengths[0] = new int[len*len];
    for(int i = 1 ; i < len ; i++)
    {
        lengths[i] = lengths[i - 1] + len;
    }

    int maxLength = 1;

    for(int i = 1 ; i < len ; i++)
    {
        int num = a[i];
        int lengths1 = 2;
        
        for(int j = i - 1 ; j >= 0 ; j--)
        {
            int prev1 = a[j];
            int prev2 = num - prev1;

            int len1 = 2;
            unordered_map<int , int>::iterator it = hmap.find(prev2);
            if(prev2 < prev1 && it != hmap.end())
            {
                len1 = lengths[j][hmap[prev2]] + 1;
            }

            lengths[i][j] = len1;
            lengths1 = max(lengths1 , len1);
        }

        maxLength = max(maxLength , lengths1);
    }

    return maxLength > 2 ? maxLength : 0;
    
}

int main()
{
    int a[8] = {1,2,3,4,5,6,7,8};

    int result = longestFibNum(a , sizeof(a) / sizeof(a[0]));

    cout<<result<<endl;


    return 0;
}

