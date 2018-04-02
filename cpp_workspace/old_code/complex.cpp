#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r=0.0,double i=0.0);
    friend int operator ==(Complex a,Complex b);
};
int operator ==(Complex a,Complex b)
{
    if(a.real==b.real && a.imag==b.imag)
        return 1;
    else
        return 0;
}
Complex::Complex(double r,double i)
{
    real = r;
    imag = i;
}
int main()
{
    Complex com1(3.3,4.4),com2(3.3,4.4);
    if(com1 == com2)
       cout << "y!" << endl;
    else
       cout << "n!" << endl;
    return 0;
}
