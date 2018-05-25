/*************************************************************************
	> File Name: traverseTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月25日 星期五 21时39分43秒
 ************************************************************************/
#include <iostream>
#include <iomanip>
#include "stack"

using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node;

Node* root = NULL;

class BST
{
public:
    void insert(int data);    //插入元素
    Node* search(int e);        //查找
    Node* deleteNode(Node *root,int key);   //删除
    void preorder_tree(Node *root);  //先序遍历，递归
    void pre_tree(Node*root);       //先序遍历，非递归
    void inorder_tree(Node* root);      //中序遍历，递归
    void in_tree(Node* root);           //中序遍历，非递归
    void postorder_tree(Node* root);    //后序遍历，递归
    void post_tree(Node* root);         //后序遍历，非递归

protected:
private:
};



//搜索
Node* BST::search(int e)
{
    Node *temp = root;
    if(temp == NULL)
    {
        cout<<"the tree is empty\n"<<endl;
        return NULL;
    }

    cout<<"\n查找的顺序："<<endl;
    while(temp != NULL && temp->data != e)
    {
        cout<<temp->data;
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
void BST::insert(int data)
{
    Node *temp = new Node;
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
//T的左<根<右的性质，使得我们可以快速定位到要删除的节点，
//我们对于当前节点值不等于key的情况，根据大小关系对其左右子节点分别调用递归函数。
//若当前节点就是要删除的节点，我们首先判断是否有一个子节点不存在，那么我们就将root指向另一个节点，
//如果左右子节点都不存在，那么root就赋值为空了，也正确。
//难点就在于处理左右子节点都存在的情况，我们需要在右子树找到最小值，即右子树中最左下方的节点，
//然后将该最小值赋值给root，然后再在右子树中调用递归函数来删除这个值最小的节点


//删除节点
Node* BST::deleteNode(Node *root,int key)
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
//先序遍历 : 递归版
void BST::preorder_tree(Node *root)
{

    if(root != NULL )
    {
        cout<<root->data<<setw(4);
        preorder_tree(root->lchild);
        preorder_tree(root->rchild);
    }
}
void BST::pre_tree(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<Node* >s;
    Node* p = root;

    while(!s.empty() || p)
    {
        //打印根节点并压栈，进入左子树
        while(p)
        {
            cout<<p->data<<setw(4);
            s.push(p);
            p = p->lchild;
        }

        //左子树处理完毕，进入右子树
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}



//中序遍历： 递归版
void BST::inorder_tree(Node* root)
{
    if(root != NULL )
    {
        inorder_tree(root->lchild);
        cout<<root->data<<setw(4);
        inorder_tree(root->rchild);
    }
}

//中序遍历 ： 非递归版
void  BST::in_tree(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<Node* > s;
    Node* p = root;

    while(!s.empty() || p)
    {
        //先遍历到左叶子,途中的所有根节点压栈
        while(p)
        {
            s.push(p);
            p = p->lchild;
        }

        if(!s.empty())
        {
            p = s.top();
            s.pop();
            cout<<p->data<<setw(4);
            p = p->rchild;
        }
    }
}
//后序遍历: 递归版
void BST::postorder_tree(Node* root)
{
    if(root != NULL )
    {
        postorder_tree(root->lchild);
        postorder_tree(root->rchild);
        cout<<root->data<<setw(4);
    }
}

//后序遍历： 非递归版
void BST::post_tree(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<Node* > s;
    Node* cur = root; //当前访问的节点
    Node* last_visit = NULL; //上次访问的节点

    //遍历到左叶子，压栈
    while(cur)
    {
        s.push(cur);
        cur = cur->lchild;
    }

    while(!s.empty())
    {
        //出栈顶
        cur = s.top();
        s.pop();

        //判断是否打印该节点
        if(cur->rchild == NULL || cur->rchild == last_visit)
        {
            cout<<cur->data<<setw(4);
            last_visit = cur;
        }
        else //进入右子树
        {
            s.push(cur);
            cur = cur->rchild;
            while(cur)
            {
                s.push(cur);
                cur = cur->lchild;
            }
        }

    }
}

int main()
{
    BST btree;
    Node *temp;

    //插入
    for(int i = 1 ; i <= 10 ; i++)
    {
        btree.insert(i);
    }

    //遍历
    cout<<"先序遍历为："<<endl;
    btree.preorder_tree(root);
    cout<<endl;
    btree.pre_tree(root);

    cout<<"\n中序遍历为："<<endl;
    btree.inorder_tree(root);
    cout<<endl;
    btree.in_tree(root);

    cout<<"\n后序遍历为："<<endl;
    btree.postorder_tree(root);
    cout<<endl;
    btree.post_tree(root);

    cout<<"\nafter delete\n";
    root = btree.deleteNode(root,9);
    cout<<"\n先序遍历为："<<endl;
    btree.preorder_tree(root);

    cout<<"\n中序遍历为："<<endl;
    btree.inorder_tree(root);

    cout<<"\n后序遍历为："<<endl;
    btree.postorder_tree(root);



    temp = btree.search(9);
    if(temp == NULL)
    {
        cout<<"not search\n";
    }
    else
    {
        cout<<"\nthe data in this tree\n";
    }

    return 0;
}

