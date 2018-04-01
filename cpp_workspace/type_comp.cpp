/*************************************************************************
	> File Name: type_comp.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 10时37分08秒
 ************************************************************************/

/*
兼容规则中所指的替代包括以下情况：
	子类对象可以当作父类对象使用
	子类对象可以直接赋值给父类对象
	子类对象可以直接初始化父类对象
	父类指针可以直接指向子类对象
	父类引用可以直接引用子类对象

*/



#include <iostream>
using namespace std;

class Parent
{
public:
	void printP()
	{
		cout<<"Parent"<<endl;
	}

	Parent()
	{
		cout<<"parent()"<<endl;
	}

	Parent(const Parent &obj)
	{
		cout<<"copy()"<<endl;
	}

private:
	int a;
};

class child : public Parent
{
public:
	void printC()
	{
		cout<<"child"<<endl;
	}
protected:
private:
	int c;
};

void howToPrint(Parent *base)
{
	base->printP(); 

}

void howToPrint2(Parent &base)
{
	base.printP(); 
}

int main()
{
	Parent p1;
	p1.printP();

	child c1;
	c1.printC();
	c1.printP();


	//赋值兼容性原则
	// 基类指针 (引用) 指向 子类对象
	Parent *p = NULL;
	p = &c1;
	p->printP();

	// 指针做函数参数

	howToPrint(&p1);
	howToPrint(&c1);

	//引用做函数参数
	howToPrint2(p1);
	howToPrint2(c1);


	Parent p3 = c1;  //子类对象可以直接初始化父类对象


	return 0 ;
}

