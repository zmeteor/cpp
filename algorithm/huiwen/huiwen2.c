/*************************************************************************
	> File Name: huiwen2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月29日 星期四 11时12分52秒
 ************************************************************************/

/*
    字符串中添加K个字符是否可以形成回文串
*/

/*思路*/
/*
    string:原字符串
    recvstring：翻转后的字符串
    计算原字符串和翻转后的字符串的最长公共子串，其长度为：maxlen
    diff = strlen（string） - maxlen; diff即为最少删去的字符串个数
 */



#include<stdio.h>
#include<string.h>

#define MAX 100
#define k 1   //允许添加k个字母



int Max(int m,int n,int i,int j,int b[][MAX]);
void LCS(char x[],char y[],int x_len,int y_len,int c[][MAX],int b[][MAX]);

int main()
{
    char *x = "cocob";
    char rex[MAX];
    int m = strlen(x);
    char *p = x+m-1;

    int i,j;

    //逆序
    for(i = 0;i < m;i++,p--)
    {
        rex[i] = *p;
    }

    putchar(10);
    int c[MAX][MAX] ; //存储X，Y最长公共子序列的长度
    int b[MAX][MAX] ;// 记录c[i][j] 的解是由那个子问题的解得到的

    LCS(x,rex,m,m,c,b);

    if(m-c[m][m] <= k)
    {
        printf("OK!\n");
    }
    else
    {
        printf("NO!\n");
    }


        return 0;

}

//取c[i-1][j]和c[i][j-1]的最大值,并记录c[i][j]是通过哪一个子问题的值求得的，以决定搜索的方向
int Max(int m,int n,int i,int j,int b[][MAX])
{
    if(m > n)
    {
        b[i][j] = -1;
        return m;
    }
    else
    {
        b[i][j] = 1;
        return n;
    }
}

//将最长公共子序列的长度存入c[][]
void LCS(char x[],char y[],int x_len,int y_len,int c[][MAX],int b[][MAX])
{
    int i,j;
    for(i = 1;i <= x_len;i++)
    {
        for(j = 1;j <= y_len;j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = 0;
            }
            else
            {
                c[i][j] = Max(c[i-1][j],c[i][j-1],i,j,b);
            }
        }
    }
}

