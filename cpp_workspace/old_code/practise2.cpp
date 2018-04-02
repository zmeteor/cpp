#include <iostream>

using namespace std;

class CStatic
{
public:
    CStatic()
    {
        val++;
    }
    static int val;
};

int CStatic::val=0;
int main()
{
    CStatic c[10];
    cout<<"CStatic::val="<<CStatic::val<<endl;
    return 0;
}
