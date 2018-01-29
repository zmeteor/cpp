#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int main()
{
    int i = 0;
    int n = 7;
    int k = 7;
    int sum = 0;
    int t = 0;
    int a[8] = {1,2,3,4,5,1,6,6};

    for(i = 0;i <= k+1;i++)
    {
        if(a[i] > n)
        {
            printf("No Solution!");
            return 0;
        }

    }

    for(i = 0;i < k+1;i++)
    {
        sum += a[i];
        if(sum > n)
        {
            t++;
            i--;
            sum = 0;
        }
    }
    printf("最少加油次数为：%d",t);
    return 0;
}
