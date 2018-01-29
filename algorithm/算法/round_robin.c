#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void Table(int k)
{
    int n = 1;
    int i = 0;
    int m = 1;
    int s = 0;
    int j = 0;
    int t = 0;
    int a[MAX][MAX];

    for(i = 1;i <= k;i++)
    {
        n *= 2;
    }
    //填第一行
    for(i = 1;i <= n;i++)
    {
        a[1][i] = i;
    }
    for(s = 1;s <= k;s++)//分割次数
    {
        n /= 2;
        for(t = 1;t <= n;t++)
        {
            for(i = m+1;i <= 2*m;i++)
            {
                for(j = m+1;j <= 2*m;j++)
                {
                    a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
                    a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];
                }
            }
        }
        m *= 2;
    }

    for(i = 1;i <= m ;i++)
    {
        for(j = 1;j <= m;j++)
        {
            printf("%5d",a[i][j]);
        }
        putchar(10);
    }

}
int main()
{
    int k;

    printf("请输入比赛人数(2^n):\n");
    scanf("%d",&k);

    Table(k);
    return 0;
}
