#include <stdlib.h>
#include <stdio.h>
#include <time.h>

# define N 1000


void Merge(int a[],int lo, int p,int hi)
{
    int *c=NULL;
    c=(int *)malloc((hi-lo+1)*sizeof(int));
    int k,i=lo,j=p+1;
    for(k=0;k<hi-lo+1;k++)
    {
        // 若左边排完
        if(i<lo || i>p)
        {
          c[k]=a[j++];
        }
        // 若右边排完
        else if(j<p+1 || j>hi)
        {
            c[k]=a[i++];
        }
        // 比较
       else if(a[i]<a[j])
        {
           c[k]=a[i++];
        }
        else
            c[k]=a[j++];
    }
    // 将排列好的序列拷贝到a数组中
    for(k=0;k<hi-lo+1;k++)
    {
        a[lo+k]=c[k];
    }
    free(c);
}
void Mergesort(int a[],int lo,int hi)
{
    int p=0;
    if(lo<hi)
    {
         p = (lo+hi)/2;
         Mergesort(a,lo,p);
         Mergesort(a,p+1,hi);
         Merge(a,lo,p,hi);
    }
}
int main()
{
    int i=0,j;
    time_t t;
    time(&t);
    srand(t);

    //int *a=NULL;
    //a=(int *)malloc(N*sizeof(int));
    int a[N] = {0} ;
    for(i=0;i<N;i++){
        a[i] = rand()%1000 + 1 ;
    }

    Mergesort(a,0,N-1);
    for(j=0;j<N-1;j++)
    {
        printf("%5d\t",a[j]);

    }
    return 0;
}


