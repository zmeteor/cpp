/*  ��дһ���������һ�������࣬���ݳ�Ա�����Ӹ��������ء�
 С�������������˽�������࣬�����ؿ��������������������˽
 �������࣬�����ؿ�������������ÿ���඼�����ݵ����������*/
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
