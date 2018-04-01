/*************************************************************************
	> File Name: abstract_class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 13时33分25秒
 ************************************************************************/


//抽象类在多继承中的应用

#include <iostream>
using namespace std;

class Interface_add
{
public:
    virtual void add(int a,int b) = 0;
    virtual void print() = 0;
protected:
private:
};

class Interface_mult
{
public:
    virtual void mult(int a,int b) = 0;
    virtual void print() = 0;
protected:
private:
};

class Base
{
public:
    int getA()
    {
        this->a = 0;
        return a;
    }
protected:
private:
    int a;
};

class Numop:public Base,public Interface_add,public Interface_mult
{
public:
    virtual void add(int a,int b)
    {
        cout<<"add()"<<endl;
        this->result = a+b;
    }
    virtual void mult(int a,int b)
    {
        cout<<"mult()"<<endl;
        this->result =  a*b;
    }
    virtual void print()
    {
        cout<<"result = "<<result<<endl;
    }
protected:
private:
    int result;
};


int main()
{
    Numop op;
//    op.add(1,2);
//    op.print();
//
//    op.mult(1,2);
//    op.print();

    /*利用纯虚函数实现接口，通过接口操作对象*/

    Interface_add *it = NULL; //抽象类不能实例化
    it = &op;
    it->add(1,2);
    it->print();

    Interface_mult *it1 = NULL;
    it1 = &op;
    it1->mult(1,2);
    it1->print();

    return 0;
}

