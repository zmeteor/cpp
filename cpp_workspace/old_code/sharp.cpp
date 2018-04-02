/* �����ΪShape����Shape������������(���Ͻǵ㡢����)��
 ��Բ��(���ᡢ����)������������Ĺ��캯������Ա��ʼ������
 �����ж����麯��GetArea()(�������)�����������и�д,д��
 �ó����ʵ�֡�*/
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
