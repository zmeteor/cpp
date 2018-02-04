
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

typedef struct student
{
	char name[20];
	int  score;
}STU;



typedef STU ElemType;

typedef struct list {
  ElemType a[MAXSIZE + 1];
  int len;
} SeqList;


SeqList * InitList() {
  SeqList *pList;
  pList = (SeqList *)malloc(sizeof(SeqList));
  pList->len = 0;
  return pList;
}
void InitList2(SeqList **ppList) {
  *ppList = malloc(sizeof(SeqList));
  (*ppList)->len = 0;
}
int ListFull(SeqList *pList) {
  if (pList->len == MAXSIZE)
    return 1;
  else
    return 0;
}
int ListEmpty(SeqList *pList) {
  return (pList->len == 0) ? 1 : 0;
}
int ListLen(SeqList *pList) {
  return pList->len;
}
void Error(char *msg) {
  printf("error: %s\n", msg);
}
int GetElem(SeqList *pList, int i, ElemType *pElm) {
  if (ListEmpty(pList)) {
    Error("Get element from empty list");
    return 0;
  }
  if (i < 1 || i > MAXSIZE) {
    Error("Get element from illegal position!");
    return 0;
  }
  *pElm = pList->a[i];
  return 1;
}

int InsertElem(SeqList * pList, int i, ElemType elm) {
  int k;
  if (ListFull(pList)) {
    Error("Insert element to a full list!");
    return 0;
  }
  if (i < 1 || i > pList->len + 1) {
    Error("insert element out of range!");
    return 0;
  }
  for (k = pList->len; k >= i; k--) pList->a[k + 1] = pList->a[k];
  // assert(i == k + 1);
  pList->a[i] = elm;
  pList->len += 1;
  return 1;
}

int DelElem(SeqList *pList, int i, ElemType *pElm) {
  int k;
  if (ListEmpty(pList)) {
    Error("delete element from an empty list");
    return 0;
  }
  if (i < 1 || i > pList->len) {
    Error("delete element out of range");
    return 0;
  }
  *pElm = pList->a[i];
  for (k = pList->len; k >i; k--)
    pList->a[k-1] = pList->a[k];
  pList->len -= 1;
  return 1;
}

void PrintList(SeqList *pList) {

  int i;
  for (i =pList->len; i >=1; i--)
    printf("name: %-10s score:%-5d\n",
           ((pList->a[i])).name,
           ((pList->a[i])).score);
  putchar('\n');

}


void menu()
{

	printf("1 add student\n");
	printf("2 delet student(按序号删除：6  按姓名删除：7)\n");
	printf("3 print student\n");
	printf("4 search student\n");
	printf("5 exit\n");
}


// 用户输入学生个数n，然后利用循环把学生逐个加入到学生线形表中
void AddStu(SeqList *pList)
{
	int n, i;
	STU tmp;
	puts("Please input the number of students: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%s%d", tmp.name, &tmp.score);
		InsertElem(pList, 1, tmp);
	}
}

void DelStu(SeqList *pList)
{
    int l;
	STU tmp;
	puts("Please input the number of DelStu: ");
	scanf("%d", &l);

	DelElem(pList, l, &tmp);
	printf("删除学生的信息:  name:%s, score: %d",pList->a[l].name,pList->a[l].score );
    printf("\n");


}
void DelByName(SeqList *pList)
{
    int i=1;
    STU m, tmp;
    puts("Please input the name of DelStu: ");
    scanf("%s",m.name);
    while(i<=pList->len)
    {

        if(strcmp(m.name, pList->a[i].name)==0)
        {
            DelElem(pList, i, &tmp);
            printf("删除学生的信息:  name:%s, score: %d",pList->a[i].name,pList->a[i].score );
            printf("\n");
            break;
        }
        i++;

    }

}
void SearchByName(SeqList *pList){
    int i=1;
    STU m, tmp;
    puts("Please input the name of Student: ");
    scanf("%s",m.name);
   while(i<=pList->len)
    {

        if(strcmp(m.name, pList->a[i].name)==0)
        {
            printf("学生的信息:  name:%s, score: %d",pList->a[i].name,pList->a[i].score );
            printf("\n");
            break;

        }
        i++;
    }
}


void PrintStu(SeqList *pList)
{
	PrintList(pList);
}


int main()
{
	int choice;


	SeqList *pList;
	InitList2(&pList);


	printf("This is a simple student management system!\n");
	while (1) {
        printf("*******************************************\n");
		menu();
		printf("*******************************************\n\n");

		printf("please choice:");

		scanf("%d", &choice);
		switch (choice) {
		case 1: AddStu(pList); break;
		case 7: DelByName(pList); break;
		case 3: PrintStu(pList); break;
		case 4: SearchByName(pList); break;
		case 5: puts("Bye!"); exit(0); break;
		case 6:  DelStu(pList);break;

		}; // end of switch
	} // end of while

	return 0;
}
