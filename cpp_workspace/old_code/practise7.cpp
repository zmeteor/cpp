#include <iostream>

using namespace std;

class A
{
    int a,b;
public:
    A(int i,int j){
        a=i;
        b=j;
    }
    void move(int x,int y)
    {
        a+=x;
        b+=y;
    }
    void print()
    {
        cout<<"a= "<<a<<"   b="<<b<<endl;
    }
};
class B:private A{
    int c,d;
public:
    B(int x,int y,int z,int w):A(x,y){
        c=z;
        d=w;
        }
    void fun(){
        move (10,20);
    }
    void aprint()
    {
        A::print();
    }
};
int main()
{
    A a(20,30);
    a.print();
    B b(1,2,3,4);
    b.fun();
   // b.print();
    b.aprint();

    return 0;
}
