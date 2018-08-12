/*************************************************************************
	> File Name: traverseGraph.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 19时43分04秒
 ************************************************************************/
//图的邻接矩阵,BFS,DFS

#include <iostream>
#include <iomanip>
#include "stack"
#include "queue"

using namespace std;
#define MAX_VERTS 20  //定义节点的数量

//定义节点
class Vertex
{
public:
    Vertex(char Label)
    {
        this->Label = Label;
        isvisited = false;
    }

    char Label;
    bool isvisited;
};

//定义图
class Graph
{
public:
    Graph();
    ~Graph();
    void addVertex(char lab);           //增加一个节点
    void addEdge(int start , int end);  //增加一条边
    void printMatrix();                 //打印邻接矩阵
    void showVertex(int v);             //打印节点
    int getAdjUvisitVert(int v);        //下一个相邻的节点
    void DFS();   //使用堆栈实现图的深度优先遍历
    void BFS();   //使用队列实现图的广度优先遍历
protected:
private:
    Vertex* verList[MAX_VERTS];  //存放节点的数组
    int nVerts;   //实际的节点数
    int adjMat[MAX_VERTS][MAX_VERTS];  //邻接矩阵
};

void Graph::showVertex(int v)
{
    cout<<verList[v]->Label<<" ";
}

int Graph::getAdjUvisitVert(int v)
{
    for(int i = 0 ; i < nVerts ; i++)
    {
        if((adjMat[v][i] == 1) && verList[i]->isvisited == false)
        {
            return i;
        }
    }
    return -1;
}

void Graph::DFS()
{
    stack<int> s;
    verList[0]->isvisited = true;
    showVertex(0);
    s.push(0);

    while(!s.empty())
    {
        int v = getAdjUvisitVert(s.top());
        if(v == -1)
        {
            s.pop();
        }
        else
        {
            verList[v]->isvisited = true;
            showVertex(v);
            s.push(v);
        }
    }

    cout<<endl;
    for(int i = 0 ; i < nVerts ; i++)
    {
        verList[i]->isvisited = false;
    }
}

void Graph::BFS()
{
    queue<int> q;
    verList[0]->isvisited = true;
    showVertex(0);
    q.push(0);

    while(!q.empty())
    {
        int v1 = q.front();
        q.pop();

        int v2 = getAdjUvisitVert(v1);
        while(v2 != -1)
        {
            verList[v2]->isvisited = true;
            showVertex(v2);
            q.push(v2);

            v2 = getAdjUvisitVert(v1);
        }
    }

    cout<<endl;

    for(int i = 0 ; i < nVerts ; i++)
    {
        verList[i]->isvisited = false;
    }
}
Graph::Graph()
{
    nVerts = 0;
    for(int i = 0 ; i < MAX_VERTS ;i++)
    {
        for(int j = 0 ; j < MAX_VERTS ; j++)
        {
            adjMat[i][j] = 0;
        }
    }
}

void Graph::addVertex(char lab)
{
    verList[nVerts++] = new Vertex(lab);
}

void Graph::addEdge(int start , int end)
{
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
}

void Graph::printMatrix()
{
    for(int i = 0; i < nVerts ; i++)
    {
        for(int j = 0 ; j < nVerts ; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

Graph::~Graph()
{
    for(int i = 0 ; i < MAX_VERTS ; i++)
    {
        delete verList[i];
    }
}


int main()
{
    Graph gp;
    gp.addVertex('A');
    gp.addVertex('B');
    gp.addVertex('C');
    gp.addVertex('D');
    gp.addVertex('E');

    gp.addEdge(0,1);
    gp.addEdge(0,3);
    gp.addEdge(1,4);
    gp.addEdge(2,4);
    gp.addEdge(3,0);
    gp.addEdge(3,4);
    gp.addEdge(4,1);
    gp.addEdge(4,2);
    gp.addEdge(4,3);

    gp.printMatrix();

    cout<<"DFS:"<<endl;
    gp.DFS();

    cout<<"BFS:"<<endl;
    gp.BFS();


    return 0;
}

