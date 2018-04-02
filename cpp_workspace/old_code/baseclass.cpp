/*  定义一个基类BaseClass，从它派生出类DerivedClass，BaseClass
  有成员函数fn1()、fn2()，fn1()是虚函数，DerivedClass也有成员
  函数fn1()、fn2()，在主程序中定义一个DerivedClass的对象，分别
  用BaseClass和DerivedClass的指针来调用fn1()、fn2()*/
#include <iostream>

using namespace std;

class BaseClass
{
public:
    BaseClass()
    {
        cout<<"BaseClass"<<endl;
    }
    virtual void f1()
    {
        cout<<"virtual f1"<<endl;
    }
    void f2()
    {
        cout<<"f2()"<<endl;
    }
};

class DerivedClass:public BaseClass
{
public:
    DerivedClass()
    {
        cout<<"~DerivedClass"<<endl;
    }
    void f1()
    {
        cout<<"~DerivedClass f1"<<endl;
    }
    void f2()
    {
        cout<<"~DerivedClass f2"<<endl;
    }
};
int main()
{
    DerivedClass *pd,obj;
    BaseClass *p = &obj;
    p->f1();
    p->f2();
    pd = &obj;
    pd->f1();
    pd->f2();
    return 0;
}
