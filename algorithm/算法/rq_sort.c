#include <stdio.h>
#include <stdlib.h>

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
void RQsort(int a[],int lo,int hi)
{
    int p;
    if(lo<hi)
    {
        p=RPartation( a,lo,hi);
        RQsort(a,lo,p-1);
        RQsort(a,p+1,hi);
    }
}


int main()
{
    int i,N;
    int *a=NULL;

    printf("please input N:\n");
    scanf("%d",&N);

    a=(int *)malloc(N*sizeof(int));

    printf("please input number:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    //int a[6]={1,5,2,3,6,4};
    RQsort(a,0,N-1);
    for(i=0;i<N;i++)
    {
        printf("%d\t",a[i]);

    }

    return 0;
}
