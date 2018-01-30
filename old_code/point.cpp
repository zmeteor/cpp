#include <iostream>

using namespace std;
class Point
{
private:
    int x,y;
public:
    Point(int a,int b):x(a),y(b){}
    ~Point();
};
int main()
{
    Point *p=new Point(2,3);
    delete p;
    return 0;
}
Point::~Point()
{
    cout<<"destructor...."<<endl;
}
