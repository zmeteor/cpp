/*************************************************************************
	> File Name: BST.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 15时51分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node;

Node* root = NULL;

//搜索
Node* search(int e)
{
    Node *temp = root;
    if(temp == NULL)
    {
        printf("the tree is empty\n");
        return NULL;
    }

    printf("查找的顺序：");
    while(temp != NULL && temp->data != e)
    {
        printf("%d\t",temp->data);
        if(temp->data > e)
        {
            temp = temp->lchild;
        }
        else
        {
            temp =temp->rchild;
        }
    }

    return temp;
}

//插入
void insert(int data)
{
    Node *temp = (Node* )malloc(sizeof(Node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if(root == NULL) //若还没有创建树
    {
        root = temp;
    }
    else
    {
        Node* current = root;
        Node* parent = current;

        while(1)
        {
            parent = current;
            if(current->data > temp->data)
            {
                current = current->lchild;
                if(current == NULL)
                {
                    parent->lchild = temp;
                    return;
                }
            }
            else
            {
                current = current->rchild;
                if(current == NULL)
                {
                    parent->rchild = temp;
                    return;
                }
            }
        }

    }
}
//T的左<根<右的性质，使得我们可以快速定位到要删除的节点，我们对于当前节点值不等于key的情况，根据大小关系对其左右子节点分别调用递归函数。若当前节点就是要删除的节点，我们首先判断是否有一个子节点不存在，那么我们就将root指向另一个节点，如果左右子节点都不存在，那么root就赋值为空了，也正确。难点就在于处理左右子节点都存在的情况，我们需要在右子树找到最小值，即右子树中最左下方的节点，然后将该最小值赋值给root，然后再在右子树中调用递归函数来删除这个值最小的节点


//删除节点
Node* deleteNode(Node *root,int key)
{
    if(!root) 
    {
        return NULL;
    }
    if (root->data > key) 
    {
        root->lchild = deleteNode(root->lchild, key);
    } 
    else if (root->data < key) 
    {
        root->rchild = deleteNode(root->rchild, key);
    } 
    else 
    {
        if (!root->lchild || !root->rchild) 
        {
            root = (root->lchild) ? root->lchild : root->rchild;  
        } 
        else 
        {
            Node *cur = root->rchild;
            while (cur->lchild) cur = cur->lchild;
            root->data = cur->data;
            root->rchild = deleteNode(root->rchild, cur->data);
                        
        }
                
    }
    return root;
}
//先序遍历
void preorder_tree(Node *root)
{
    
    if(root != NULL )
    {
        printf("%d ",root->data);
        preorder_tree(root->lchild);
        preorder_tree(root->rchild);
    }
}

//中序遍历
void inorder_tree(Node* root)
{
    if(root != NULL )
    {
        inorder_tree(root->lchild);
        printf("%d ",root->data);
        inorder_tree(root->rchild);
    }
}

//后序遍历
void postorder_tree(Node* root)
{
    if(root != NULL )
    {
        postorder_tree(root->lchild);
        postorder_tree(root->rchild);
        printf("%d ",root->data);
    }
}

int main()
{
    Node *temp;

    insert(3);
    insert(1);
    insert(2);
    insert(5);
    insert(4);
    insert(6);

    printf("先序遍历为：");
    preorder_tree(root);
    putchar(10);
    printf("中序遍历为：");
    inorder_tree(root);
    putchar(10);
    printf("后序遍历为：");
    postorder_tree(root);
    putchar(10);

    printf("after delete\n");
    root = deleteNode(root,5);
    printf("先序遍历为：");
    preorder_tree(root);
    putchar(10);
    printf("中序遍历为：");
    inorder_tree(root);
    putchar(10);
    printf("后序遍历为：");
    postorder_tree(root);
    putchar(10);


    temp = search(8);
    if(temp == NULL)
    {
        printf("not search\n");
    }
    else
    {
        printf("\nthe data in this tree\n");
    }

    return 0;
}
