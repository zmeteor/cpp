/* 虚基类为Shape，从Shape派生出矩形类(左上角点、宽、高)、
 椭圆类(横轴、纵轴)。给出各个类的构造函数，成员初始化，在
 基类中定义虚函数GetArea()(计算面积)，在派生类中改写,写出
 该程序的实现。*/
#include <iostream>

using namespace std;
class Shape
{
public:
    virtual double GetArea()=0;
};
class Rectangle:public Shape
{
private:
    double left_p,width,height;
public:
    Rectangle(double x,double y,double z):left_p(x),width(y),height(z){}
    double GetArea()
    {
        return width * height;
    }

};
class Eli:virtual public Shape
{
private:
    double a,b;
public:
    Eli(double x,double y):a(x),b(y){}
    double GetArea()
    {
        return 3.14*a*b;
    }

};

int main()
{
    Shape *p;
    Rectangle r1(3,4,3);
    Eli e1(4,5);
    p = &r1;
    cout<<p->GetArea()<<endl;
    p = &e1;
    cout<<p->GetArea()<<endl;
    return 0;
}
