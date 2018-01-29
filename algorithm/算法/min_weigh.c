//  最小重量机器设计问题。

#include<stdio.h>

#define max 30

int w[max][max];
int c[max][max];
int bestx[max];
int x[max];
int cw=0,cc=0;
int bestw=10000;
int cost;
int n;
int m;

void Backtrack(int t);

int main()
{
    int i,j;
    printf("请输入部件数,供应商数,限定价格：\n");
    scanf("%d%d%d",&n,&m,&cost);

    printf("请输入各部件的在不同供应商的重量：\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&w[i][j]);

        }

    }
    printf("请输入各部件的在不同供应商的价格：\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&c[i][j]);
        }

    }

    Backtrack(1);

    printf("\n最小重量为：%d\n",bestw);
    printf("每个部件的供应商：\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",bestx[i]);

    }

    return 0;
}

void Backtrack(int t)
{
    int j;
    if( t > n)
    {
        bestw=cw;
        for(j=1;j<=n;j++)
        {

            bestx[j]=x[j];
        }
    }
    else
    {
        for(j=1;j<=m;j++)
        {
            if(cc+c[t][j]<=cost && cw+w[t][j]<bestw)
            {
                x[t]=j;
                cc+=c[t][j];
                cw+=w[t][j];
                Backtrack(t+1);
                cc-=c[t][j];
                cw-=w[t][j];
            }
        }
    }
}
