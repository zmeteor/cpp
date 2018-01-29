#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int tile = 0;
int Board[MAX][MAX];
void Printf(int Board[MAX][MAX],int n);
void ChessBoard(int tr,int tc,int dr,int dc,int size);

int main()
{
    int r,c,s;

    printf("请输入尺寸，特殊位置的行及列:\n");
    scanf("%d %d %d",&s,&r,&c);
    putchar(10);

    ChessBoard(0,0,r,c,s);

    Printf(Board,s);

    return 0;
}

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    int s,t;

    if (1 == size)
    return;

    s = size/2;
    t = ++ tile;

    if (dr < tr + s && dc < tc +s)
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else
    {
        Board[tr+s-1][tc+s-1] = t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    if (dr < tr + s && dc >= tc + s )
    {
        ChessBoard(tr,tc+s,dr,dc,s);
    }
    else
    {
        Board[tr+s-1][tc+s] = t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if (dr >= tr + s && dc < tc + s)
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        Board[tr+s][tc+s-1] = t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    if (dr >= tr + s && dc >= tc + s)
    {
        ChessBoard(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        Board[tr+s][tc+s] = t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }

}
void Printf(int Board[MAX][MAX],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            printf("%d\t",Board[i][j]);
        }
        putchar(10);
    }
}
