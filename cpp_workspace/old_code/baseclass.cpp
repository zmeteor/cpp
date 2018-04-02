/*  ����һ������BaseClass��������������DerivedClass��BaseClass
  �г�Ա����fn1()��fn2()��fn1()���麯����DerivedClassҲ�г�Ա
  ����fn1()��fn2()�����������ж���һ��DerivedClass�Ķ��󣬷ֱ�
  ��BaseClass��DerivedClass��ָ��������fn1()��fn2()*/
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
