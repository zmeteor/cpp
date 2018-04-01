/*************************************************************************
	> File Name: cal_wage.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 14时56分05秒
 ************************************************************************/



//面向抽象类编程

/*
编写一个C++程序, 计算程序员( programmer )工资
	1 要求能计算出初级程序员( junior_programmer ) 中级程序员 ( mid_programmer )高级程序员( adv_programmer)的工资
	2 要求利用抽象类统一界面,方便程序的扩展, 比如:新增, 计算 架构师 (architect ) 的工资
*/


#include <iostream>

using namespace std;

//定义接口
class Programmer
{
public:
    virtual void get_wage() = 0;
protected:
private:
};

//初级程序员
class junior_programer: public Programmer
{
public:
    junior_programer(string name , string type , int wage)
    {
        this->name = name;
        this->type = type;
        this->wage = wage;
    }

    virtual void get_wage()
    {
        cout<<"name: "<<name<<"\ttype: "<<type<<"\twage: "<<wage<<endl;
    }
protected:
private:
    string name;
    string type;
    int wage;
};

//中级程序员
class mid_programer: public Programmer
{
public:
    mid_programer(string name , string type , int wage)
    {
        this->name = name;
        this->type = type;
        this->wage = wage;
    }

    virtual void get_wage()
    {
        cout<<"name: "<<name<<"\ttype: "<<type<<"\twage: "<<wage<<endl;
    }
protected:
private:
    string name;
    string type;
    int wage;
};

//高级程序员
class adv_programer: public Programmer
{
public:
    adv_programer(string name , string type , int wage)
    {
        this->name = name;
        this->type = type;
        this->wage = wage;
    }

    virtual void get_wage()
    {
        cout<<"name: "<<name<<"\ttype: "<<type<<"\twage: "<<wage<<endl;
    }
protected:
private:
    string name;
    string type;
    int wage;
};

//架构师
class architect: public Programmer
{
public:
    architect(string name , string type , int wage)
    {
        this->name = name;
        this->type = type;
        this->wage = wage;
    }

    virtual void get_wage()
    {
        cout<<"name: "<<name<<"\ttype: "<<type<<"\twage: "<<wage<<endl;
    }
protected:
private:
    string name;
    string type;
    int wage;
};


void cal_wage(Programmer &p)
{
    p.get_wage();
}


int main()
{
    //实例化对象
    junior_programer jp("tom","junior",5000);
    mid_programer mp("rose","mid",10000);
    adv_programer ap("jim","adv",15000);

    //计算工资
    cal_wage(jp);
    cal_wage(mp);
    cal_wage(ap);

    //新增
    architect act("ryan","architect",20000);
    cal_wage(act);


    return 0;
}

