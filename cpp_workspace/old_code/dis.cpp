#include <iostream>
#include <math.h>
using namespace std;
class Point
{
private:
    double x,y;
public:
    Point(double x1=0,double y2=0):x(x1),y(y2){}
    double Distance(Point p);
};
double Point:: Distance(Point p)
{
    double d;
    d=sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    return d;
}
int main()
{
    Point p1(1,1),p2;
    cout << "the distance is: " <<p1.Distance(p2) <<endl;
    return 0;
}
