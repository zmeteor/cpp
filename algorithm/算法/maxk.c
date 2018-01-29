#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}



int Partation(int a[],int lo,int hi)
{
    int i,j,temp;
    if(lo<hi)
    {
        i=lo-1;
        temp=a[hi];
        for(j=lo;j<hi;j++)
        {
            if(a[j]<temp)
            {
                swap(&a[i+1],&a[j]);
                i++;
            }
        }
        swap(&a[i+1],&a[hi]);
    }
    return i+1;

}
int RPartation(int a[],int lo,int hi)
{
    int r;
    if(lo<hi){
        r=rand()%(hi-lo+1)+lo;
    }
    swap(&a[hi],&a[r]);
    return Partation(a,lo,hi);
}
int RSelect(int a[],int lo,int hi,int k)
{
    int i,j;
    if(lo == hi)
        return a[lo];
    i = RPartation(a,lo,hi);
    j = i - lo + 1;
    if(k <= j)
        return RSelect(a,lo,i,k);
    else
        return RSelect(a,i+1,hi,k-j);
}





int main()
{
    int i,s;
    int a[MAX];
    int k;

    printf("请输入要查找的第k小元素：\n");
    scanf("%d",&k);

    FILE *fp = fopen("e:\\算法设计\\date\\1000.doc","rw");
    if(fp == NULL)
    {
        printf("文件读取无效!");
        return -1;
    }
    for(i = 0;!feof(fp);i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    fclose(fp);

    s = RSelect(a,0,MAX-1,k);

    printf("第k小元素为：%d",s);

    return 0;
}
