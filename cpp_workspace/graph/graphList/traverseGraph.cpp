/*************************************************************************
	> File Name: traverseGraph.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 18时39分23秒
 ************************************************************************/
//邻接链表存储图，BFS，DFS

#include <iostream>
#include "list"
#include "queue"
#include "stack"

using namespace std;

class Vertex
{
public:
    char label;
    bool isvisited;
    Vertex(const char lab)
    {
        label = lab;
        isvisited = false;
    }


};

ostream& operator<<(ostream&out ,const Vertex& v)
{
    cout<<v.label<<"->";
    return out;
}

template<class T>
class Graph
{
public:
    Graph(const int ver):n(ver)
    {
        VertexList = new T*[n];
        HeadNodes = new list<int>[n];   //创建n个链表
        nVerts  = 0;
    }
    ~Graph()
    {
        delete [] VertexList;
        delete [] HeadNodes;
    }

    void addVertex(T* v);
    void addEdge(int start , int end);
    void showList();
    void showVer(int v);
    int getAdjUnvisitVer(int v);
    void BFS();
    void DFS();

protected:
private:
    T** VertexList;
    list<int>* HeadNodes;
    int n;
    int nVerts; //实际节点个数
};

template <class T>
int Graph<T>::getAdjUnvisitVer(int v)
{
    list<int> l = HeadNodes[v];
    if(!l.empty())
    {
        list<int>::iterator it = l.begin();
        for( ; it!= l.end() ; it++)
        {
            if(!VertexList[*it]->isvisited)
            {
                return *it;
            }
        }
    }

    return -1;
}

template <class T>
void Graph<T>::addVertex(T* v)
{
    VertexList[nVerts++]  = v;
}


template <class T>
void Graph<T>::addEdge(int start , int end)
{
    HeadNodes[start].push_back(end);
}

template <class T>
void Graph<T>::showList()
{
    for(int i = 0 ; i < nVerts ; i++)
    {
        cout<<i<<"->";
        for(list<int>::iterator it = HeadNodes[i].begin() ; it != HeadNodes[i].end() ; it++)
        {
            cout<<*it<<"->";
        }
        cout<<"end"<<endl;
    }
}
template <class T>
void Graph<T>::showVer(int v)
{
    cout<<*VertexList[v]<<" ";
}

template <class T>
void Graph<T>::BFS()
{
    queue<int> q;
    VertexList[0]->isvisited = true;
    showVer(0);
    q.push(0);

    while(!q.empty())
    {
        int i = 0;
        int v1 = q.front();
        q.pop();

        list<int> l = HeadNodes[v1];
        list<int>::iterator it = l.begin();
        for( ; it != l.end() ; it++)
        {
            if(!VertexList[*it]->isvisited)
            {
                showVer(*it);
                VertexList[*it]->isvisited = true;
                q.push(*it);
            }
        }
    }
    cout<<endl;

    for(int i = 0 ; i < nVerts ; i++)
    {
        VertexList[i]->isvisited = false;
    }
}

template<class T>
void Graph<T>::DFS()
{
    stack<int> s;
    VertexList[0]->isvisited = true;
    showVer(0);
    s.push(0);

    while(!s.empty())
    {
        int v = getAdjUnvisitVer(s.top());

        if(v != -1)
        {
            VertexList[v]->isvisited = true;
            showVer(v);
            s.push(v);
        }
        else
        {
            s.pop();
        }
    }

    cout<<endl;
}
int main()
{
    Vertex a('A');
    Vertex b('B');
    Vertex c('C');
    Vertex d('D');
    Vertex e('E');

    Graph<Vertex> gp(5);
    gp.addVertex(&a);
    gp.addVertex(&b);
    gp.addVertex(&c);
    gp.addVertex(&d);
    gp.addVertex(&e);

    gp.addEdge(0,1);
    gp.addEdge(0,3);
    gp.addEdge(1,0);
    gp.addEdge(1,4);
    gp.addEdge(2,4);
    gp.addEdge(3,0);
    gp.addEdge(3,4);
    gp.addEdge(4,1);
    gp.addEdge(4,2);
    gp.addEdge(4,3);


    gp.showList();

    cout<<"BFS: ";
    gp.BFS();

    cout<<endl;

    cout<<"DFS: ";
    gp.DFS();
    return 0;
}

