/*************************************************************************
	> File Name: hash_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时43分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"hash_list.h"

int main()
{
    //创建空头结点
    node *head[HashSize] = {NULL};
    int i = 0;
    for(i = 0;i < HashSize;i++)
    {
        head[i] = createlist();
    }

    //创建hash表
    node *arr[HashSize] = {NULL};
    for(i = 0;i < HashSize;i++)
    {
        arr[i] = head[i];
    }

    insert(arr,12);
    insert(arr,22);
    insert(arr,32);
    insert(arr,2);
    insert(arr,1);

    node* ret = search(arr,42);
    if(ret == NULL)
    {
        printf("Not find!\n");
    }
    else
    {
        printf("exsit! add:%p\n",ret);
        printf("%d\n",*ret);
    }

    return 0;
}


//创建空链表
node *createlist()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));

    head->next = NULL;

    return head;

}
//插入节点
void insert_node(node *head,int insertdata)
{
    node *crl = NULL;
    crl = (node *)malloc(sizeof(node));
    crl->data = insertdata;

    crl->next = head->next;
    head->next = crl;
}

//链表查找
node *finddata(node *head,int finddata)
{
    node *crl = head->next;
    while(crl)
    {
        if(crl->data == finddata)
        {
            break;
        }
        crl = crl->next;
    }

    return crl;
}

//计算hash值
int hash(int data)
{
    return data%HashSize;
}

//插入hash表
void insert(node *arr[],int data)
{
    int index = hash(data);
    node *head = arr[index];
    insert_node(head,data); //链地址法解决冲突
}

//hash表中查找
node * search(node *arr[],int data)
{
    int index = hash(data);
    node* crl = arr[index]->next;

    node* ret = finddata(crl,data);

    return ret;
}
