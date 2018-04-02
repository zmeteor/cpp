#include <iostream>

using namespace std;

class base
{
    int i;
public:
    base(int I=0):i(I){}
    virtual int sum() const
    {
        return i;
    }
};

class der:public base
{
    int j;
public:
    der(int I=0,int J=0):base(I),j(J){}
    int sum() const
    {
        return base::sum()+j;
    }
};

void call(base b)
{
    cout<<"sum = "<<b.sum()<<endl;
}
int main()
{
    base b(10);
    der d(10,47);
    call(b);
    call(d);
    return 0;
}
