/*  编写一个程序：设计一个汽车类，数据成员有轮子个数、车重。
 小车类是汽车类的私有派生类，包含载客量。卡车类是汽车类的私
 有派生类，包含载客数和载重量。每个类都有数据的输出方法。*/
#include <iostream>

using namespace std;

class Vehicle
{
private:
    int wheels;
    float weight;
public:
    Vehicle(int wh,float we):wheels(wh),weight(we){}
    void print()
    {
        cout<<"   wheels: "<<wheels<<endl;
        cout<<"   weight: "<<weight<<endl;
    }
};

class car:private Vehicle
{
private:
    int passengers;
public:
    car(int a,float b,int c):Vehicle(a,b),passengers(c){}
    void print()
    {
    Vehicle::print();
    cout<<"   passengers: "<<passengers<<endl;
    }

};
class Truck:private Vehicle
{
    int passengers;
    int payload;
public:
    Truck(int a,float b,int pa,int pay):Vehicle(a,b),passengers(pa),payload(pay){}
    void print()
    {
       cout<<"Truck: "<<endl;
       Vehicle::print();
       cout<<"   passengers: "<<passengers<<endl;
       cout<<"   payload: "<<payload<<endl;
    }
};
int main()
{
    Truck obj(3,4,5,6);
    obj.print();


    return 0;
}
