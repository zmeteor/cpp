/*************************************************************************
	> File Name: construct_order.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月30日 星期五 20时44分52秒
 ************************************************************************/

//先构造父类的构造函数，若父类还有父类，则先构造祖类的构造函数
//然后调用组合类的构造函数
//最后调用自己的构造函数


//析构时，顺序相反

#include <iostream>
using namespace std;

class Object
{
public:
	Object(int a, int b)
	{
		this->a = a;
		this->b = b;
        cout<<"object(): "<<"a: "<<a<<" b:"<<b<<endl;
	}
	~Object()
	{
		cout<<"~Object()"<<endl;
	}
protected:
	int a;
	int b;
};


class Parent : public Object
{
public:
	Parent(string str) : Object(1, 2)
	{
		this->str = str;
		cout<<"Parent()"<<endl;
	}
	~Parent()
	{
        cout<<"~Parent(): "<<str<<endl;
	}

	void printP(int a, int b)
	{
		cout<<"parent"<<endl;
	}

protected:
	string str;

};


class child : public Parent
{
public:
	child(string str) : Parent(str) , obj1(3, 4), obj2(5, 6)
	{
		this->myp = str;
		cout<<"child()"<<endl;
	}
	~child()
	{
		cout<<"~child()"<<myp<<endl;
	}
	void printC()
	{
		cout<<"child"<<endl;
	}
protected:
	string myp;
	Object obj1;
	Object obj2;
};


int  main()
{
    cout<<"开始构造："<<endl;

	child c1("test");

    cout<<endl<<"开始析构:"<<endl;

	return 0;
}


