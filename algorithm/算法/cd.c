#include <stdio.h>
#include <stdlib.h>

void swap(double *a,double *b);
void sort(double s[],int n);
void min_avg(double s[],int n);

int main()
{
    int i = 0;
    int n = 5;
    double  t= 0;
    int l[] = {71,46,9,73,35};
    int p[] = {872,452,265,120,85};

    double s[n];

    for(i = 0;i < n;i++)
    {
        t += p[i];
    }
    for(i = 0;i < n;i++)
    {

        s[i] =l[i]*p[i]/t;
    }

    sort(s,n);
    min_avg(s,n);

    return 0;
}

void swap(double *a,double *b)
{
    double temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort(double s[],int n)
{
    int i = 0;
    int j = 0;

    for(i = 0;i < n-1;i++)
    {
        for(j = i+1;j < n;j++)
        {
            if(s[i] > s[j])
            {
                swap(&s[i],&s[j]);

            }
        }
    }
}
void min_avg(double s[],int n)
{
    int i = 0;
    int j = 0;
    double avg = 0;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j <= i;j++)
        {
            avg += s[j];
        }
    }

    printf("最小平均时间为:%.2lf",avg);
}

