#include <iostream>

using namespace std;

int main()
{
   int i=100;
   cout.setf(ios::hex);
   cout<<i<<"\t";
   cout<<i<<"\t";
   cout.setf(ios::dec);
   cout<<i<<endl;
    return 0;
}
