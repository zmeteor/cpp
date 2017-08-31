/*************************************************************************
	> File Name: BinarySort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月31日 星期一 13时53分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N    1000000
#define STEP 3
#define LOOP 1000000

void BinarySort(int min,int max,int n);
int main()
{
    float cost = 0;
    int n = 0;
    int i = 0;
    int a[N] = {0};
    int g_nmax = 0;

    time_t t = 0;
    clock_t begin = 0,end = 0;

    //利用当前时间建立随机数种子；
    time(&t);
    srand(t);    
    
    //构造随机数数组
    for(i = 0;i < N;i++)
    {
        a[i] = g_nmax + 1 + (rand() % STEP);
        g_nmax = a[i];
    }

    n = (rand() % g_nmax) + 1; //使所要查找的数字位于1～g_nmax

    begin = clock();

    for(i = 0;i < LOOP;i++)
    {
        BinarySort(0,N-1,n);
    }
    end = clock();

    cost = (end - begin)/1000;
    printf("cost = %.3fclock \n",cost);


    return 0;
}

void BinarySort(int min,int max,int n)
{
    int mid = 0;

    if(min > max)
    {
  //      printf("NO! \n");
        return;
    }

    mid = min + (max - min)/2; //防止数字过大，超过整数范围；

    if(n == mid)
    {
//        printf("YES! \n");
        return;
    }
    else if(n < mid)
    {
        max = mid - 1;
        BinarySort(min,max,n);
    }
    else if(n > mid)
    {
        min = mid + 1;
        BinarySort(min,max,n);
    }
}

