#include <iostream>

using namespace std;

template<class T>
T result(T *a,int n=0)
{
    T b=1;
    int i;
    for(i=0;i<n;i++)
    {
        b*=a[i];
    }
    return b;
}
int main()
{
    int a[]={2,3,4,5};
    cout<<result(a,sizeof(a)/sizeof(int));
    return 0;
}
