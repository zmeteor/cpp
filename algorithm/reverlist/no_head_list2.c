/*************************************************************************
	> File Name: H_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 16时53分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct node
{
    ElementType data;
    struct node *next;
}Node;
typedef Node* list;

list MakeList(int data); //创建链表
list reverselist(list head); //递归版链表逆置
void PrintList(list head);  //打印链表
void InsertList(list head,ElementType data); //尾插;


int main()
{
    list head = NULL;
    head = MakeList(0);
    InsertList(head,1);
    InsertList(head,2);
    InsertList(head,3);
    PrintList(head);

    putchar(10);
    list newnode = reverselist(head);
    PrintList(newnode);
    putchar(10);
    
    return 0;
}

//创建链表
list MakeList(int data)
{
    list head = NULL;
    head = (list)malloc(sizeof(Node));
    head->data = data;

    head->next = NULL;
    return head;
}

//非递归版
list reverselist(list head)
{
    list temp = NULL;
    list newhead = NULL;

    while(head)
    {
        temp = head->next;
        head->next = newhead;
        newhead = head;
        head = temp;
    }

    return newhead;
}
//打印链表
void PrintList(list head)
{
    list temp = head;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

//尾插法
void InsertList(list head,ElementType data)
{
    list temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    list i_num = NULL;
    i_num = (list)malloc(sizeof(Node));
    i_num->data = data;
    i_num->next = NULL;

    temp->next = i_num;

}

