/*************************************************************************
	> File Name: huiwen1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月29日 星期四 00时07分49秒
 ************************************************************************/


/*
题目描述

给定一个字符串，问是否能通过添加一个字母将其变为回文串。

输入描述:

一行一个由小写字母构成的字符串，字符串长度小于等于10。

输出描述:

输出答案(YES\NO).

输入例子:

coco

输出例子:

YES
*/

/*思路*/
/*逆向思考：添加一个字符可以构成回文串 ==删除一个字符可以构成回文串*/
/*在判断字符串的过程中，将不符合回文串的部分摘出来，然后删除首部一个或尾部一个再次判断是否是回文串*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_huiwen(char* str,char* pre, char* post);  //判断是否是回文串
int add_huiwen(char* str);   //判断是否可以通过增加一个字母构成回文串
int main()
{
    char* str = "a";

    int ret = add_huiwen(str);
    if(1 == ret)
    {
        printf("ok!\n");
    }
    else
    {
        printf("NO!\n");
    }
    return 0;
}

/*判断是否可以通过增加一个字母构成回文串*/
int add_huiwen(char* str )
{
     int flag = 0;
     char* pre = str;
     char* post = str + strlen(str)-1;

    /*先判断回文串部分*/
     int i;
     for(i = 0 ; i < strlen(str)/2 ; i++)
     {
         if(*pre != *post)
         {
             break;
         }
         pre++;
         post--;
     }

     if(i == strlen(str)/2)
     {
         flag = 1;
     }

     /*再判断不符合回文串的部分是否可以通过删首/尾部的元素组成回文串*/
     else
     {
         //防止第二次判断受影响
         char* fpre = pre;
         char* epost = post;

         flag = (is_huiwen(str,++fpre,epost) || is_huiwen(str,pre,--post));

     }

     return flag;
}

//判断是否是回文串
int is_huiwen(char* str , char* pre , char* post)
{
    while(pre < post)
    {
        if(*pre != *post)
        {
            return 0;
        }
        pre++;
        post--;
    }

    return 1;
}

