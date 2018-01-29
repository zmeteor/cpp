#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void LCSLength(int m,int n,char *x,char *y,int c[][MAX],int b[][MAX]);
void LCS(int i,int j,char *x,int b[][MAX]);

int main()
{

    char *x = "hello";
    char *y = "kelods";
    int m = strlen(x);
    int n = strlen(y);
    int c[MAX][MAX]; //存储X，Y最长公共子序列的长度
    int b[MAX][MAX];// 记录c[i][j] 的解是由那个子问题的解得到的

    LCSLength(m,n,x,y,c,b);
    printf("最长公共子串为：");
    LCS(m,n,x,b);

    return 0;
}

void LCSLength(int m,int n,char *x,char *y,int c[][MAX],int b[][MAX])
{

    int i,j;
    for(i = 1;i <= m;i++)
    {
        c[i][0] = 0;
    }
    for(i = 1;i <= n;i++)
    {
        c[0][i] = 0;
        for(i = 1;i <= m;i++)
        {
            for(j = 1;j <= n;j++)
            {
                if(x[i] == y[j])
                {
                    c[i][j] = c[i-1][j-1]+1;
                    b[i][j] = 1;
                }
                else if(c[i-1][j] >= c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 2;
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 3;
                }
            }
        }
    }
}

void LCS(int i,int j,char *x,int b[][MAX])
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(b[i][j] == 1)
    {
        LCS(i-1,j-1,x,b);
        printf("%c",x[i]);
    }
    else if(b[i][j] == 2)
    {
        LCS(i-1,j,x,b);
    }
    else
    {
        LCS(i,j-1,x,b);
    }
}
