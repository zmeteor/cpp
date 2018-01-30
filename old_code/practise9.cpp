#include <iostream>

using namespace std;
class base
{
public:
    int n;
    base(int x):n(x){}
    virtual void set(int m)
    {
        n=m;
        cout<<n<<" ";
    }
};
class der1:public base{
public:
    der1(int x):base(x){}
    void set(int m)
    {
        n+=m;
        cout<<n<<" ";

    }
};
class der2:public base{
public:
    der2 (int x):base(x){}
    void set(int m)
    {
        n+=m;
        cout<<n<<" ";

    }

};
int main()
{
    der1 d1(1);
    der2 d2(2);
    base* pbase;
    pbase=&d1;
    pbase->set(1);
    pbase=&d2;
    pbase->set(3);

    return 0;

}
