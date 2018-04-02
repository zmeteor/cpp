//将一个复数转换为二维向量

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
    cout<<"复数： :";
    cout<<c.real;
    if(c.imag>0)
        cout<<"+";
    if(c.imag!=0)
        cout<<c.imag<<endl;
    cout<<"二维向量： ";
    cout<<"("<<x<<","<<y<<")"<<endl;

}
