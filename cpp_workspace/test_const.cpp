/*************************************************************************
	> File Name: test_const.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 20时00分01秒
 ************************************************************************/
#include <iostream>

using namespace std;

class test_const
{
public:
    //const int a;
   // int b;
   static int b;
    test_const();
    ~test_const();
protected:
private:
};

int test_const::b = 10;



//const int a = 10 ; //a存入符号表中,不可改变真正实现了将变量变成了常量
int main1()
{
    const int a = 10;   // 常变量，不可改变值，存入符号表（key-value）
    int *p = (int *)&a;  //取地址时，为a分配空间
    *p = 11;

    cout<<"a = "<<a<<endl;    //a = 10,C++编译器虽然可能为const常量分配空间，但不会使用其存储空间中的值。
    cout<<"*p = "<<*p<<endl;   // *p = 11;

    //cout << sizeof(test_const)<< endl;
    return 0;
}

//const 分配内存时间 ， 编译期间

int main()
{
    int a;
    const int b = 10;
    int *p = (int* )&b;
    int c;
//    static int d = 10;
    cout<<"&a : "<<&a<<"\n&c = "<<&c<<endl;   //没有为b分配内存


    cout<<sizeof(test_const)<<endl;
    //cout<<"&a : "<<&a<<"\n&b = "<<&b<<"\n&c = "<<&c<<endl;   //因为对b取地址了，所以会分配内存

    return 0;
}
/*
结论：
C语言中的const变量
C语言中const变量是只读变量，有自己的存储空间
C++中的const常量
可能分配存储空间,也可能不分配存储空间
    不分配空间：编译过程中若发现使用常量则直接以符号表中的值替换
    分配空间：1、当const常量为全局，并且需要在其它文件中使用 extern
              2、当使用&操作符取const常量的地址   &
*/

