//矩阵连乘

#include <stdio.h>
#include <stdlib.h>

int MatrixChain(int *p,int n,int **m,int **s);
void Traceback(int i,int j,int **s);

int main()
{

    int i;
    int **m,**s;
    int n = 6;
    int a[7] = {30,35,15,5,10,20,25};
    int *p = a;
    int c;

    m = (int**)malloc(n * sizeof(int *));
    s = (int**)malloc(n * sizeof(int *));

    for(i = 0;i < n;i++)
    {

        m[i] = (int*)malloc(n * sizeof(int ));
        s[i] = (int*)malloc(n * sizeof(int ));
    }

    c =MatrixChain(p,n,m,s);
    printf("Minest time:%d\n",c);
    Traceback(0,n-1,s);

    free(m);
    free(s);

    return 0;
}

int MatrixChain(int *p,int n,int **m,int **s)
{
    int i,j,r,k;

    //将对角线初始化为0
    for(i = 0;i < n;i++)
    {
        m[i][i] = 0;

    }
    //沿对角线填充
    for(r = 2;r <= n;r++)//填充层数
    {
        for(i = 0;i <= n-r;i++)
        {
            j = i + r - 1;
            m[i][j] = 99999;//初始化为最大
            s[i][j] = i;// 保存断点信息
            for(k = i;k <= j-1;k++)// 计算最优值，比较j-1次
            {

                int t = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }

    }

    return m[0][n-1];
}

void Traceback(int i,int j,int **s)
{
    if(i == j)
    {
        printf("A%d",i+1);
    }
    else
    {
        printf("(");
        Traceback(i,s[i][j],s);
        Traceback(s[i][j]+1,j,s);
        printf(")");
    }

}
