#include <stdio.h>
#include <stdlib.h>

int Backtrack(int i,int w[],int cw,int r,int n,int bestw);
int main()
{
    //int c = 50;
    int w[3] = {10,40,40};
    int n = 3;
    int bestw = 0;
    int cw = 0;
    int r = 0;
    int i = 0;

    for(i = 0;i < n;i++)
    {
        r += w[i];
    }

    bestw = Backtrack(0,w,cw,r,n,bestw);

    printf("%d",bestw);

    return 0;
}

int Backtrack(int i,int w[],int cw,int r,int n,int bestw)
{
    int c = 50;
    if(i > n-1)
    {
        bestw = cw;
        return bestw;
    }

    r -= w[i];
    if(cw + w[i] <= c)
    {
        cw += w[i];
        Backtrack(i + 1,w,cw,r,n,bestw);
        cw -= w[i];
    }
    if(cw + r > bestw)
    {
        Backtrack(i + 1,w,cw,r,n,bestw);
    }
    r += w[i];

    return 0;
}
