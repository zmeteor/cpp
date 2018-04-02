//��һ������ת��Ϊ��ά����

#include <iostream>

using namespace std;
class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r,double i):real(r),imag(i){}
    friend class Vector;
};
class Vector{
private:
    double x,y;
public:
    void Change(Complex c);
    void Print(Complex c);

};

int main()
{
    Complex c(1,2);
    Vector v;
    v.Change(c);
    v.Print(c);
    return 0;
}
void Vector::Change(Complex c)
{
    x=c.real;
    y=c.imag;
}
void Vector::Print(Complex c)
{
    cout<<"������ :";
    cout<<c.real;
    if(c.imag>0)
        cout<<"+";
    if(c.imag!=0)
        cout<<c.imag<<endl;
    cout<<"��ά������ ";
    cout<<"("<<x<<","<<y<<")"<<endl;

}
