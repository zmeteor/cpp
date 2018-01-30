#include <iostream>

using namespace std;

class Basic
{
    int a,b;
public:
    Basic(int i,int j){
       a=i;
       b=j;
    }
    void add(int x,int y)
    {
        a+=x;
        b+=y;
    }
    void print()
    {
        cout<<"a= "<<a<<"    b= "<<b<<endl;
    }
};
class Child:public Basic
{
    int c,d;
public:
    Child(int x,int y,int z,int w):Basic(x,y)
    {
        c=z;
        d=w;
    }
    void cadd(int i,int j)
    {
        c+=j;
        d+=j;
        add(-i,-j);
    }
    void cprint()
    {
        Basic::print();
    }
    void print()
    {
        cout<<"c="<<c<<"     d="<<d<<endl;
    }
};
int main()
{
    Basic b1(10,20);
    b1.print();
    Child c1(10,20,30,40);
    c1.cadd(100,200);
    c1.Basic::print();
    c1.print();
    c1.cprint();
    return 0;
}
