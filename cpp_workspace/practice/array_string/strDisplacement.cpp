/*************************************************************************
	> File Name: strDisplacement.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月20日 星期日 15时30分43秒
 ************************************************************************/

//给定两个字符串，判断第二个字符串是不是第一个字符串的变位词

//思路：滑动窗口

#include <iostream>

using namespace std;

bool isStrDisplace(string str1 , string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    if(len1 < len2)
    {
        return false;
    }


    int nonZero = 0;  //统计非0次出现的字符的个数
    int hashtable[26] = {0};

    //利用hash统计str2中字符出现的频率
    for(int i = 0 ; i < len2 ; i++)
    {
        int c = str2[i] - 'a';
        if(++hashtable[c] == 1)
        {
            nonZero++;
        }
    }

    //判断第一个滑动窗口是否是子串的变位词
    for(int i = 0 ; i < len2 ; i++)
    {
        int c = str1[i] - 'a';
        --hashtable[c];

        //维护nonZero
        if(hashtable[c] == 0)
        {
            nonZero--;
        }
//        else if(hashtable[c] == -1) //说明
  //      {
    //        nonZero++;
      //  }
    }

    if(nonZero == 0)
    {
        return true;
    }

    //窗口滑动
    //新窗口a[i － lenb + 1..i]  旧窗口a[i – lenb.. i – 1]
    //扔掉a[i – lenb] 加入a[i]

    for(int i = len2 ; i < len1 ; i++)
    {
        //扔掉 a[i-lenb]
        int c = str1[i - len2] - 'a';
        ++hashtable[c];

        if(hashtable[c] == 1)
        {
            nonZero++;
        }
        else if(hashtable[c] == 0)
        {
            nonZero--;
        }

        //加入a[i]
        c = str1[i];
        --hashtable[c];

        if(hashtable[c] == 0)
        {
            --nonZero;
        }
        else if(hashtable[c] == -1)
        {
            ++nonZero;
        }

        if(nonZero == 0)
        {
            return true;
        }
    }


    return false;
}

int main()
{
    string str1 = "hello";
    string str2 = "lel";

    if(isStrDisplace(str1 , str2))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }

    return 0;
}

