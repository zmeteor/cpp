//子集合问题

#include<stdio.h>
#include<stdio.h>

int MaxSum(int a[], int sum, int n);
int main()
{
    int n = 5;
    int sum = 10;
    int a[] = {0,2,2,6,5,4};
    MaxSum(a,sum,n);
    return 0;

}

int MaxSum(int a[], int sum, int n)
{
    int i = 1;
    int j = 0;
    int x[n + 1];
    int bestx[n + 1];
    int bests = 0;
    int Curr_Arr = 0;
    int r = 0;
    for (j = 1; j <= n; j++)
    {
        r += a[j];
    }

    while (1)
    {
        while ( i <= n && Curr_Arr + a[i] <= sum )
        {
            r -= a[i];
            Curr_Arr += a[i];
            x[i] = 1;
            i++;
        }
        if( i  > n )
        {
            for (j = 1; j <= n; j++ )
            {
                bestx[j] = x[j];
            }
            bests = Curr_Arr;
        }
        else
        {
            r -= a[i];
            x[i] = 0;
            i++;
        }
        while(Curr_Arr + r <= bests)
        {
            i--;
            while( i > 0 && !x[i] )
            {
                r += a[i];
                i--;
            }
            if( i == 0 )
            {
                printf("选择的数为：");
                for(i = 0; i  < n + 1; i++ )
                {
                    if( bestx[i] == 1)
                    {
                        printf("%3d",a[i]);
                    }

                }
                return bests;
            }
            x[i] = 0;
            Curr_Arr -= a[i];
            i++;
        }

    }
}
