/*************************************************************************
	> File Name: polymorphism.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 10时25分08秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void print()
    {
        cout<<"parent"<<endl;
    }
protected:
private:
};

class Child:public Parent
{
public:
    void print()   //父类加virtual关键字后，派生类可加可不加都默认virtual
    {
        cout<<"child"<<endl;
    }
    void test()
    {
        cout<<"test"<<endl;
    }
protected:
private:
};

void test_print(Parent &p)
{
    p.print();
}


int main()
{
    //指针和引用都会调用基类的函数而不会调用派生类的函数
//    Parent *p = NULL;
//    Child c;
//    p = &c;
//    c.print();
//    p->print();
//
//    Parent &p1 = c;
//    p1.print();

    //多态
    Parent pa;
    Child ch;

    test_print(pa);
    test_print(ch);

    return 0;
}

