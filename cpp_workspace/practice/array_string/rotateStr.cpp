/*************************************************************************
	> File Name: rotateStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 21时46分51秒
 ***********************************************************************/

//旋转字符串，给定offset，从左往右旋转offset个字符

#include <iostream>

using namespace std;

void reve(string& str , int begin , int end)
{
    while(begin < end)
    {
        swap(str[begin] , str[end]);
        end--;
        begin++;
    }

}

void reverseStr(string& str , int offset)
{
    int len = str.size();
    if(offset < 0 || len == 0)
    {
        return;
    }

    offset = offset % len;

    //以offset为分割点，左边逆转，右边逆转，最后逆转整个字符串
    reve(str , 0 , len - offset - 1);
    reve(str , len - offset,len - 1);
    reve(str , 0 ,len - 1);
}

int main()
{
    string str = "abcdefg";
    int offset = 3;

    reverseStr(str,offset);

    cout<<str<<endl;;
    return 0;
}

