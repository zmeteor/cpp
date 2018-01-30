#include <iostream>

using namespace std;

class A
{
    static int a;
    int b;

public:
    A()
    {
        a++;
        cout<<a<<endl;
    }
    void f()
    {
        b++;
        cout<<b<<endl;
    }
};

int A::a=0;



int main()
{
    A a1,a2,a3;
    return 0;
}
