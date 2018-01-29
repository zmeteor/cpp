#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void swap(int *a,int *b);
void sort(int s[],int f[],int n);
void fun(int s[],int f[],int k);

int main()
{
    int i = 0;
    int k = 0;
    int s[MAX] = {0};
    int f[MAX] = {0};

    printf("请输入需要安排的活动数：");
    scanf("%d",&k);

    printf("请输入活动的起始时间：\n");
    for(i = 0;i < k;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }

    sort(s,f,k);
    fun(s,f,k);

    return 0;
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int s[],int f[],int n)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < n-1;i++)
    {
        for(j = i+1;j < n;j++)
        {

            if(f[i] > f[j])
            {
                swap(&f[i],&f[j]);
                swap(&s[i],&s[j]);
            }
        }
    }
}

void fun(int s[],int f[],int k)
{
    int i = 0;
    int j = 0;
    int count = 1;

    for(i = 1;i < k;i++)
    {
        if(s[i] > f[j])
        {
            j = i;
            count++;
        }
    }

    printf("最少需要的会场数为：%d",count);
}
