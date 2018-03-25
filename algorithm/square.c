/*************************************************************************
	> File Name: square.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月23日 星期五 11时24分42秒
 ************************************************************************/

//给定四个点，判断是否能组成正方形

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
}point;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(point t[][4],int len,int n);
void is_quare(point a[][4],int len,int n);

int main()
{
    int i;
    int n;
    int j;
    point a[10][4];

    printf("请输入组数:\n");
    scanf("%d",&n);

    for(j = 0;j < n;j++)
    {
        printf("请输入第%d组的x:\n",j+1);
        for(i = 0;i < 4;i++)
        {
            scanf("%d",&a[j][i].x);
        }
        printf("请输入第%d组的y:\n",j+1);
        for(i = 0;i < 4;i++)
        {
            scanf("%d",&a[j][i].y);
        }
    }
    printf("\n结果为：\n");


    sort(a,4,n);

    is_quare(a,4,n);

    return 0;
}

//方便找到对角线
void sort(point t[][4],int len,int n)
{
    int i = 0;
    int j = 0;
    int s = 0;

   for(s = 0; s < n; s++ )
   {
        int flag = 0;
        for(i = 0;i < len-1;i++)
        {
            flag = 1;
            for(j = 1;j < len-1-i;j++)
            {
                if(t[s][j].x > t[s][j+1].x)
                {
                    swap(&t[s][j].x,&t[s][j+1].x);
                    swap(&t[s][j].y,&t[s][j+1].y);
                }
                if(t[s][j].x == t[s][j+1].x && t[s][j].y < t[s][j+1].y)  //若横坐标相等，纵坐标小的距离远
                {
                      swap(&t[s][j].x,&t[s][j+1].x);
                      swap(&t[s][j].y,&t[s][j+1].y);
                }

                flag = 0;
            }

            if(1 == flag)
            {
                break;
            }
        }
   }

}

//判断是否能组成正方形：对角线相等且垂直
void is_quare(point a[][4],int len,int n)
{
    int t;
    for(t = 0;t < n;t++)
    {
        int d1 = sqrt(((a[t][0].x - a[t][3].x)*(a[t][0].x - a[t][3].x)) + ((a[t][0].y - a[t][3].y)*(a[t][0].y - a[t][3].y)));  //对角线
        int d2 = sqrt(((a[t][1].x - a[t][2].x)*(a[t][1].x - a[t][2].x)) + ((a[t][1].y - a[t][2].y)*(a[t][1].y - a[t][2].y)));  //对角线

        if(d1 == d2)
        {
            int temp =(a[t][0].x - a[t][3].x) * (a[t][1].x - a[t][2].x) +  (a[t][0].y - a[t][3].y) * (a[t][1].y - a[t][2].y);

            if(0 == temp)
            {
                printf("第%d组：OK\n",t+1);
            }
            else
            {
                printf("第%d组：NO\n",t+1);
            }
        }
        else
        {
            printf("第%d组：NO\n",t+1);
        }
    }

}
