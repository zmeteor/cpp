#include <iostream>

using namespace std;

class Sample
{
private:
    int n;
    static int s;
public:
    Sample(int m):n(m){}
    void addvalue(int m);
    void disp();
};

int Sample::s=5;
void Sample::addvalue(int m)
{
    s*=n+m;
}
void Sample::disp()
{
    cout<<"s="<<s<<endl;
}
int main()
{
    Sample ob(10);
    ob.addvalue(5);
    ob.disp();
    return 0;
}
