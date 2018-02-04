/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时51分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define Hashsize 10 //hash表长

int hash(int data); //求hash地址
void insert(int a[],int data); //插入
int search(int a[],int data); //查找

int main()
{
    int i = 0;
    int arr[100] = {0};
    insert(arr,2);
    insert(arr,3);
    for(i = 0;i < 5;i++)
    {
        printf("%d\n",arr[i]);
    }

    int temp = search(arr,2);
    if(temp == -1)
    {
        printf("not find!\n");
    }
    else
    {
        printf("exsit! index = %d\n",temp);
    }


    return 0;
}

//除留取余
int hash(int data)
{
    return data%10;
}

//插入
void insert(int a[],int data)
{
    int index = hash(data);
    
    //开放地址法解决冲突
    while(a[index] != 0)
    {
        index = hash(index+1);
    }

    a[index] = data;
}

//查找
int search(int a[],int data)
{
    int size = Hashsize;
    int index = hash(data);
    while(a[index] != data && size != -1)
    {
        index = hash(index +1);
        size--;
    }

    return (size == -1)?-1:index;
}

