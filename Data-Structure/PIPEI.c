/************************************************
 Created by David Song in 2016-4-26

 Note:
   1. Sequencial implementation of stack
*************************************************/
//ºÏ≤‚¿®∫≈ «∑Ò∆•≈‰£¨ΩË÷˙’ª

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef char ElemType;
typedef struct stack {
  ElemType a[MAX];
  int top;
} Stack;

// ≥ı ºªØ
void InitStack(Stack **p) {
    *p = (Stack *)malloc(sizeof(Stack));
    (*p)->top = -1;
}

//≈–’ªø’
int StackEmpty(Stack *p) {
    return (p->top == -1);

}

//≈–’ª¬˙
int StackFull(Stack *p) {
    return (p->top == MAX-1);

}

//—π’ª
void Push(Stack *p, ElemType x) {
    if(!StackFull(p))
        p->a[++p->top] = x;

}

//≥ˆ’ª
void Pop(Stack *p, ElemType *q) {
    if(!StackEmpty(p))
        *q = p->a[p->top--];

}

//»°’æ∂®‘™Àÿ
void StackTop(Stack *p, ElemType *q){

    if(!StackEmpty(p))
        *q = p->a[p->top];
}
//«Âø’’ª
void StackClear(Stack *p) {
    p->top = -1;

}

//≈–∂œ «∑Ò∆•≈‰
int Match(char a, char b) {
    if ((a=='(' && b==')')||
        (a=='[' && b==']')||
        (a=='{' && b=='}'))
            return 1;
    else
        return 0;

}


int main() {
  char str[100] = "()[]{}";
  //char str[100] = "{[()][(()())]}";
  //char str[100] = "([)]{}";
  //char str[100] = "{[)(]{}}";
  int i,len;
  Stack *p;
  ElemType tmp,tmp2;
  InitStack(&p);
  len = strlen(str);

  for(i=0;i<len;i++){
    if(str[i] == '(' || str[i] == '[' || str[i]=='{')
        Push(p,str[i]);
    if(str[i] == ')' || str[i] == ']' || str[i]=='}'){
        if(StackEmpty(p)){
            break;
        }
        StackTop(p,&tmp);
        if (Match(tmp,str[i]))
            Pop(p,&tmp2);
        else
            break;

    }

  }
  if(StackEmpty(p) && i==len)
    {
        printf("   MATCH!\n");
    }
  else
    {
        printf("   NOT MATCH!\n");
    }

  return 0;
}
