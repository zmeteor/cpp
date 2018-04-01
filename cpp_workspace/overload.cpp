/*************************************************************************
	> File Name: overload.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 13时14分33秒
 ************************************************************************/

//函数重载的两种实现：成员函数、全局函数

#include <iostream>
using namespace std;

class Complex
{
private:
	int a;
	int b;
    /*全局函数法*/
	friend Complex operator+(Complex &c1, Complex &c2); //重载+
	friend Complex& operator++(Complex &c1);  //重载++i
	friend Complex operator++(Complex &c1, int);  //重载i++

public:
	Complex(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<" + " << b << "i" <<endl;
	}
	
	/*成员函数法*/
	Complex operator-(Complex &c2) //重载-
	{
		Complex tmp(this->a - c2.a, this->b - c2.b);
		return tmp;
	}

	Complex& operator--() //重载--i
	{
		this->a--;
		this->b--;
		return *this;
	}

	Complex operator--(int) //重载i--
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;
	}
};

/*全局函数法*/

//实现 + 运算符重载
Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

//前置++
Complex& operator++(Complex &c1)
{
	c1.a++;
	c1.b++;
	return c1;
}

//后置++
Complex operator++(Complex &c1, int)
{
	Complex tmp = c1;
	c1.a ++;
	c1.b ++;
	return tmp;
}

int main()
{
	Complex c1(1, 2), c2(3, 4);

	
	Complex c3 = c1 + c2;
	c3.printCom();

	Complex c4 = c1 - c2;
	c4.printCom();

	++c1;
	c1.printCom();

	--c1;
	c1.printCom();

	c1++;
	c1.printCom();

	c1--;
	c1.printCom();
	
	return 0;
}
