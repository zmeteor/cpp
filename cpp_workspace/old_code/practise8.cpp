#include <iostream>

using namespace std;
class Basic
{
public:
    Basic(){
        cout<<"Basic"<<endl;
    }
};
class child1:virtual public Basic
{
public:
    child1()
    {
        cout<<"child1"<<endl;
    }
};

class child2:virtual public Basic
{
public:
    child2()
    {
        cout<<"child2"<<endl;
    }
};
class child3:public Basic
{
public:
    child3()
    {
        cout<<"child3"<<endl;
    }
};
class grachild:public child1,public child2,public child3
{
public:
    grachild()
    {
        cout<<"grachild"<<endl;
    }
};
int main()
{
    grachild test;
    return 0;
}
