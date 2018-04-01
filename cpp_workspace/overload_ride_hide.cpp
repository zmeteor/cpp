/*************************************************************************
	> File Name: overload_ride_hide.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 12时20分41秒
 ************************************************************************/
//重载、重写（覆盖）、重定义（隐藏）


#include <iostream>

using namespace std;

/*
class Parent
{
public:
    //重载，发生在同一个类中
    // 函数名相同，参数列表不同（参数个数不同，类型不同，或两者均不同）
    void fun()
    {
        cout<<"parent"<<endl;
    }
    void fun(int i)
    {
        cout<<"Parent i"<<endl;
    }
    void fun(char ch);
    void fun(int i , int j);
    void test()
    {
        cout<<"test"<<endl;
    }
protected:
private:
};

class Child:public Parent
{
public:
    void fun()
    {
        cout<<"child"<<endl;
    }
    int fun(int i,int j)
    {
        cout<<"重定义：返回值不同，函数名相同"<<endl;
        return i;
    }
protected:
private:
};



int main()
{
    Child c1;
    c1.fun(); //child 重定义，隐藏
    //c1.fun(1);  //error 派生类不会继承基类的同名函数，基类同名函数被重定义fun，隐藏
    c1.fun(1,2);
    c1.Parent::fun(1);  //可以通过指定作用域来访问
    return 0;
}

*/

class Parent
{
public:
    virtual void fun()
    {
        cout<<"virtual void fun()"<<endl;
    }
    virtual void fun(int i)
    {
        cout<<"virtual void fun(int i)"<<endl;
    }
    virtual void fun(char ch)
    {
        cout<<"virtual void fun(char ch))"<<endl;
    }
    virtual void fun(int i , int j)
    {
        cout<<"virtual void fun(int i , int j)"<<endl;
    }
protected:
private:
};

class Child:public Parent
{
public:
    virtual void fun()
    {
        cout<<"child"<<endl;
    }
//    virtual int fun(int i,int j)  //error 重写（覆盖），必须返回值相同
//    {
//        return i;
//    }
protected:
private:
};



int main()
{
    /*重载 */
    //根据函数参数的不同，调用不同的函数
    Parent p1;
    p1.fun();
    p1.fun(1);
    p1.fun('a');
    p1.fun(1,20);



    Child c1;
    c1.fun(); //child  重写

    //C++编译器 看到fun名字 ,因子类中func名字已经存在了(名称覆盖).所以c++编译器不会去找父类
    //c1.fun(1);  //error 派生类不会继承基类的同名函数，基类同名函数被重写
    c1.Parent::fun(1);  //可以通过指定作用域来访问

    return 0;
}

/*重写（覆盖） 和重定义（隐藏）的区别与联系*/
/*
联系：发生在两个类（基类和派生类）
      函数名相同

区别：重写：函数返回值必须相同（或协变），而且有virtual关键字
    重定义：返回值可以不同，无virtual关键字
*/

