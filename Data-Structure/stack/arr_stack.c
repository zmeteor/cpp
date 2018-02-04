/*************************************************************************
	> File Name: arr_stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 20时48分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 50

typedef struct stack
{
    int *data;
    int top;
    int stacksize;
}Stack;

//初始化栈
Stack *init_stack(Stack *stack,int size)
{
    stack = (Stack *)malloc(sizeof(Stack));
    if(size <= MAXSIZE)
    {
        stack->data = (int *)malloc(sizeof(int) * size);
    }
    else
    {
        printf("可用空间不足,申请大小不能超过50\n");
        exit(1);
    }
    stack->top = -1;
    stack->stacksize = size;

    return stack;
}

//判断栈空
int is_empty(Stack *stack)
{
    if(stack->top == -1)
    {
        printf("栈空\n");
        return 1;
    }

    return 0;
}

//判断栈满
int is_full(Stack *stack)
{
    if(stack->top == stack->stacksize - 1)
    {
        printf("栈满\n");
        return 1;
    }

    return 0;
}

//压栈
void push(Stack *stack,int data)
{
    if(is_full(stack))
    {
        printf("栈满\n");
        exit(0);
    }
    stack->data[++stack->top] = data;

}

//出栈
int pop(Stack *stack)
{
    int temp;
    if(is_empty(stack))
    {
        printf("栈空\n");
        return 0;
    }

    temp = stack->data[stack->top];
    stack->top--;

    return temp;

}

//读栈顶
int peek(Stack *stack)
{
    int temp;
    if(is_empty(stack))
    {
        printf("栈空\n");
        return 0;
    }

    temp = stack->data[stack->top];

    return temp;

}

//释放
void destory(Stack *stack)
{
    if(stack->data != NULL)
    {
        free(stack->data);
    }
    if(stack != NULL)
    {
        free(stack);
    }
}



int main()
{
    Stack *stack;
    stack = init_stack(stack,40);

    push(stack,30);
    push(stack,10);

    int data = pop(stack);
    printf("%d\n",data);

    printf("top is: %d\n",peek(stack));
    
    data = pop(stack);
    printf("%d\n",data);
    
    
    return 0;
}
