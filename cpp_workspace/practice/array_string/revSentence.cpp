/*************************************************************************
	> File Name: revSentence.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月05日 星期六 11时42分58秒
 ************************************************************************/

//翻转句子，以空格或符号隔开，纯数字不需要翻转

#include <iostream>
#include <string.h>

#define MAX 1024

using namespace std;

bool ispunctorspace(char* str)
{
    return (*str == ' ' || *str == ',' || *str == '.');
}

bool needReverse(char* str , int* offset)
{
    int len = strlen(str);
    bool need = false;
    *offset = 0;

    while(!ispunctorspace(str + (*offset)) && *offset < len)
    {
        if(!isdigit(*(str + (*offset))))
        {
            need = true;
        }

        (*offset)++;
    }

    return need;
}

void reverseStr(char* str, int offset)
{
    int i = 0;
    int j = offset - 1;
    if(i < j)
    {
        swap(*(str + i) , *(str + j));
        i++;
        j--;
    }

}

int main()
{
    char str[MAX] = "I have 30 books,40 pen2.";

    int len = strlen(str);
    int offset;  //传入传出参数

    for(int i = 0 ; i < len;)
    {
        if(needReverse(str + i,&offset))
        {
            reverseStr(str + i,offset);
        }

        i += (offset + 1);
        cout<<i<<endl;
    }

    cout<<str<<endl;

    return 0;
}



