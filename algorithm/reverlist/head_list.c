/*************************************************************************
	> File Name: create_h_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月03日 星期日 22时01分07秒
 ************************************************************************/
/*带头节点的链表逆置*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *createlist();  //创建
void print(); //打印
void reverselist(node *head); //链表逆置

int main()
{
    node *head = NULL;

    head = createlist();
    print(head);
    reverselist(head);

    putchar(10);
    print(head);
    return 0;
}

//创建链表
node *createlist()
{
    int data;
    node *head = NULL;
    node *crl = NULL;
    node *pt = NULL; //记录尾节点
    head = (node *)malloc(sizeof(node));

    pt = head;
    head->next = NULL;

    printf("please input data(0 means end):");

    scanf("%d",&data);
    while(data)
    {
        crl = (node *)malloc(sizeof(node));
        crl->data = data;

        pt->next = crl;
        crl->next = NULL;
        pt = crl;
        scanf("%d",&data);
    }

    return head;

}

//打印
void print(node *head)
{
    node *crl = head->next;
    while(crl != NULL)
    {
        printf("%d\n",crl->data);
        crl = crl->next;
    }
}

//头插法，链表逆置
void reverselist(node *head)
{
    node *p = NULL;
    node *q = NULL;

    p = head->next;
    head->next = NULL;

    while(p!= NULL)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;

        p = q;
    }
}









