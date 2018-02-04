/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时30分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int cap;
    int front;
    int rear;
    int *arr;
    int size;
}Que;

//初始化队列
Que *init_queue(Que *q,int cap)
{
    q = (Que *)malloc(sizeof(Que));
    q->arr = (int *)malloc(sizeof(int) * cap);
    q->cap = cap;
    q->front = 0;
    q->rear = -1;
    q->size = 0;

    return q;
}
//判空
int is_empty(Que *q)
{
    return (q->size == 0)?1:0;
}
//判满
int is_full(Que *q)
{
    return (q->size == q->cap)?1:0;
}
//入队
void en_queue(Que *q,int data)
{
    if(is_full(q))
    {
        printf("队满\n");
        exit(1);
    }

    q->size++;
    if(q->rear == q->cap-1)
    {
        q->rear = -1;
    }
    q->arr[++q->rear] = data;
}

//出队
int de_queue(Que *q)
{
    int temp = 0;
    if(is_empty(q))
    {
        printf("队空\n");
        exit(1);
    }

    if(q->front == q->cap-1)
    {
        q->front = 0;
    }

    q->size--;
    temp = q->arr[q->front++];

    return temp;

}

//销毁
void destory_queue(Que *q)
{
    if(q->arr != NULL)
    {
        free(q->arr);
    }

    if(q != NULL)
    {
        free(q);
    }
}



int main()
{
    Que *q;
    q = init_queue(q,5);
    en_queue(q,12);
    en_queue(q,11);
    en_queue(q,10);
    en_queue(q,9);
    en_queue(q,8);

    printf("front = %d, rear = %d\n",q->front,q->rear);
    printf("%d\n",de_queue(q));
    printf("%d\n",de_queue(q));

    return 0;
}
