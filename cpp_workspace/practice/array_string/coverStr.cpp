/*************************************************************************
	> File Name: coverStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月19日 星期六 20时26分21秒
 ************************************************************************/

//翻转句子中全部的单词，单词内容不变
//例如I’m a student.  变为student. a I’m

#include <iostream>

using namespace std;

void coverStr(int start , int ed , string& str)
{
    while(start < ed)
    {
        swap(str[start++],str[ed--]);
    }
}

//先翻转整个句子，再反转单个单词
void fun(string& str)
{
    int n = str.size();
    if(n == 0)
    {
        return;
    }

    coverStr(0 , n-1 , str);

    cout<<str<<endl;

    int i = 0;
    int j = 0;

    for(j = 0 ; j < n ; j++)
    {
        if(str[j] == ' ')
        {
            coverStr(i,j-1,str);
            i = j+1;
        }
    }
}


int main()
{
    string str = "I am a student.";
    fun(str);

    cout<<str<<endl;

    return 0;
}

