//给定n及待排列的n个元素。计算出这n个元素的所有不同排列。

#include <stdio.h>
#include <stdlib.h>

void Perm(char *a,int n,int k);
int Comp(char *a,int i,int j);
void Swap(char *a,char *b);

int total=0;
int main()
{
    int n,i=0;

    printf("请输入需要排序的总数：");
    scanf("%d",&n);

    char *a=(char *)malloc(sizeof(char)*(n+1));

    printf("请输入需要排序的数据：");
    for(i=0;i<n;i++)
    {
        scanf("%s",&a[i]);

    }
    Perm(a,n-1,0);
    free(a);
    printf("%d",total);
    return 0;
}
void Perm(char *a,int n,int k)
{
    int i=0;
    if(k == n)
    {
        for(i=0;i<=n;i++)
        {
            printf("%c",a[i]);
        }
        putchar(10);
        total+=1;
    }
    else
    {
        for(i=k;i<=n;i++)
        {
            if(Comp(a,k,i))
            {
                Swap(&a[k],&a[i]);
                Perm(a,n,k+1);
                Swap(&a[k],&a[i]);
            }
        }
    }

}

int Comp(char *a,int k,int i)
{
    if(i>k)
    {
        int j=k;
        for (;j<i;j++)
        {
            if(a[j]==a[i])
                return 0;
        }
    }
    return 1;
}
void Swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
