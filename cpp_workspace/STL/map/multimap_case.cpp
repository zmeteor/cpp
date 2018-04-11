/*************************************************************************
	> File Name: multimap_case.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月16日 星期五 18时35分37秒
 ************************************************************************/

//Multimap 案例:
//公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人）
//人员信息有：姓名，年龄，电话、工资等组成
//通过 multimap进行 信息的插入、保存、显示
//分部门显示员工信息


#include <iostream>
#include <map>
#include <string>

using namespace std;

class Employee
{
public:
    Employee(string name = "xiaoming" , int age = 0 , string tel_num = "123456",double sal= 0.0);
    void change_info(string name = "xiaoming" , int age = 0 , string tel_num = "123456",double sal= 0.0);
    string getname()
    {
        return name;
    }
    void print()
    {
        cout<<name<<"  "<<age<<"  "<<tel_num<<endl;
    }
protected:
private:
    string name;
    int age;
    string tel_num;
    double sal;
};

Employee::Employee(string name , int age , string tel_num,double sal)
{
    this->name = name;
    this->age = age;
    this->tel_num = tel_num;
    this->sal = sal;
}
void Employee::change_info(string name  , int age  , string tel_num ,double sal)
{
    this->name = name;
    this->age = age;
    this->tel_num = tel_num;
    this->sal = sal;
}
void print_employee_info();

int main()
{
    print_employee_info();
    return 0;
}

void print_employee_info( )
{
    Employee e1("tom",19,"1123123",4000);
    Employee e2("jim",25);
    Employee e3("rose",22);
    Employee e4("jack",28);
    Employee e5("yoyo",30);

    //sale （员工2名）、技术研发部 development （1人）、财务部 Financial
    multimap<string , Employee> m1;
    m1.insert(make_pair("sale",e1));
    m1.insert(make_pair("sale",e2));
    m1.insert(make_pair("development",e3));
    m1.insert(make_pair("Financial",e4));
    m1.insert(make_pair("Financial",e5));

    //遍历
    for(map<string , Employee>::iterator it = m1.begin() ; it != m1.end() ; it++)
    {
        cout<<it->first<<"\t"<<endl;
        it->second.print();
    }

    //打印部门员工信息 sale
    int num = m1.count("sale");
    cout<<endl<<"sale employee num is "<<num<<endl;

    cout<<"employee info: "<<endl;
    map<string,Employee>::iterator it = m1.find("sale");
    while(it != m1.end() && num--)
    {
        cout<<it->first<<"\t"<<endl;
        it->second.print();
        it++;
    }

    cout<<endl<<endl<<"change tom's age"<<endl<<endl;
    //修改员工信息
    for(map<string , Employee>::iterator it = m1.begin() ; it != m1.end() ; it++)
    {
        if(it->second.getname() == "tom")
        {
            it->second.change_info("tom",99);
        }
    }

    for(map<string , Employee>::iterator it = m1.begin() ; it != m1.end() ; it++)
    {
        cout<<it->first<<"\t"<<endl;
        it->second.print();
    }
}

