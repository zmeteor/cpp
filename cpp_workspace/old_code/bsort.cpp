#include <iostream>

using namespace std;
template<class T>
void bubble_sort(T *Array,int n);
template<class T>
void show_array(T *Array,int n);
template<class T>
void bublle_sort(T *Array,int n)
{
    int i,j,flag;
    T temp;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=1;j<n;j++)
        {
            if(Array[j-1]>Array[j])
            {
                temp=Array[j];
                Array[j]=Array[j-1];
                Array[j-1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
template<class T>
void show_array(T *Array,int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<Array[i]<<" ";
    cout<<endl;
}
int main()
{
    int a[7]={56,2,8,4,5,79,7};
    double b[5]={17.1,72.2,38.3,4.94,58.5};
    bublle_sort(a,7);
    show_array(a,7);
    bublle_sort(b,5);
    show_array(b,5);
    return 0;
}
