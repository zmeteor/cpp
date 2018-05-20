/*************************************************************************
	> File Name: swapStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月20日 星期日 16时33分14秒
 ************************************************************************/

//若一个字符串中只有数字和*号，交换字符位置，保证*在前，字符在后

#include <iostream>

using namespace std;

/*字符相对位置可以改变*/
//法一：partition
void swapStr1(string& str)
{
    if(str.size() == 0)
    {
        return;
    }

    int i = 0 ;
    int j = str.size() - 1;

    while(i < j)
    {
        while(i < j && str[i] == '*')
        {
            i++;
        }
        while(j > i && str[j] != '*')
        {
            j--;
        }

        if(i < j)
        {
            swap(str[i++],str[j--]);
        }

    }
}

//法二：partition

void swapStr2(string& str)
{
    if(str.size() == 0)
    {
        return;
    }

    int i = 0;
    for(int j = 0 ; j < (int)str.size() ; j++)
    {
        if(str[j] == '*')
        {
            swap(str[i++] , str[j]);
        }
    }

}

/*不改变其他字符的顺序*/
//逆向复制，将字符从后往前复制，再用*填充前面的空位

void swapStr3(string& str)
{
    int n = str.size();
    if(n == 0)
    {
        return;
    }

    int tail = n - 1;
    for(int j = n - 1 ; j >= 0 ; j --)
    {
        if(str[j] != '*')
        {
            str[tail--] = str[j];
        }
    }

    while(tail >= 0)
    {
        str[tail--] = '*';
    }

}


int main()
{
    string str = "a*asd*zxc**";
    //swapStr1(str);
    //swapStr2(str);
    swapStr3(str);

    cout<<str<<endl;
    return 0;
}
