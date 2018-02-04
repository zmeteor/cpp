/*************************************************************************
	> File Name: hash_list.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月04日 星期日 18时07分54秒
 ************************************************************************/

#ifndef _HASH_LIST_H
#define _HASH_LIST_H

#define HashSize 5  //Hash表大小

//链表节点定义
typedef struct Node
{
    int data;
    struct Node *next;
}node;

/*链表操作*/
node*createlist(); //创建空链表
void insert_node(node *,int);//往空链表中插入元素
node *finddata(node *head,int finddata); // 链表查找

/*hash表操作*/
int hash(int data); //计算hash值
void insert(node *arr[],int data);//向哈希表中插入元素
node* search(node *arr[],int data);//hash表查找

#endif
