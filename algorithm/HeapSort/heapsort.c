/*************************************************************************
	> File Name: heapsort.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月29日 星期四 20时01分59秒
 ************************************************************************/

//堆排

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

void heap_sort(int a[]);
void print(int a[]);
void heap_adjust(int a[] , int start , int end);
void swap(int a[] , int i , int j);

int main()
{
    int a[SIZE] = {1,2,0,9,34,5,4,7};
    printf("排序前:  ");
    print(a);
    putchar(10);

    heap_sort(a);
    printf("排序后:  ");
    print(a);
    putchar(10);


    return 0;
}

void heap_sort(int a[])
{
    
    int i;
    int len = SIZE;

    //构建大顶堆
    for(i = (len - 1)/2 ; i >= 0 ; i--)  //从最后一个双亲节点开始
    {
        heap_adjust(a , i , len);   //调整大顶堆
    }

    //堆排  交换堆顶到尾部，重新自上而下调整大顶堆
    for(i = (len - 1) ; i > 0 ; i--)
    {
        swap(a , 0 , i);       
        heap_adjust(a , 0 , i); //每次调整最后一个元素已处在合适位置
    }
}

void swap(int a[] , int i , int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heap_adjust(int a[] , int start , int end)
{
    int temp = a[start]; //保存双亲节点
    int i;

    for(i = (2*start + 1) ; i < end ; i = i*2+1) //从左孩子开始
    {
        if((i < end - 1) && (a[i] < a[i+1]))  //左孩子小于右孩子
        {
            i++;
        }

        if(temp > a[i])
        { 
            break;  //双亲节点大于子节点，则无需调整
        }

        a[start] = a[i];
        start = i;  //使双亲节点处于合适位置
    }

    a[start] = temp;

}

void print(int a[])
{
    int i;

    for(i = 0; i < SIZE ; i++)
    {
        printf("%d\t",a[i]);
    }
}
