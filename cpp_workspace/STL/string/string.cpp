/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 17时14分09秒
 ************************************************************************/

//string 简单应用

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//1、string的初始化
int main1()
{
    string str;  //构建空串
    string str2  = "aaaaa";
    string str3("aaaaa");   //用字符串初始化
    string str4(str2);   //拷贝构造
    string str5(5, 'a'); //用5个a初始化
    cout << str.length() << endl;

    return 0;
}


//2、string 的遍历

int main2()
{
    string str = "helloworld";

    cout<<"数组方式："<<endl;
    //一般方式
    for(int i = 0 ; i < str.length(); i++)
    {
        cout << str[i];
        //cout<<str.at(i);
    }
    cout<<endl;

    cout<<"迭代器："<<endl;
    //迭代器
    for(string::iterator it = str.begin() ; it != str.end() ; it++)
    {
        cout<<*it;
    }
    cout<<endl;

    //[]和at()的区别：
    //[]出错不会抛出异常，直接down掉
    //at()会抛出异常

    cout<<"[]"<<endl;
    try
    {
        for(int i = 0 ; i <= str.length() + 10; i++)
        {
            cout << str[i];
        }
    }
    catch(...)
    {
        cout << "异常" << endl;
    }

    cout << endl;

    cout<<"at()"<<endl;
    try
    {
        for(int i = 0 ; i <= str.length() + 10; i++)
        {
            cout << str.at(i);
        }
    }
    catch(...)
    {
        cout << "异常" << endl;
    }

    cout << endl;

    return 0;
}

//3、string 和 char* 的转换

int main3()
{
    //string ---> char *
    string str = "aaaaaaaa";
    str.at(0) = 'A';
    char * s = (char *)str.c_str();
    s[1] = 'A';
    cout<<s<<endl;

    //char * ----> string
    char* s1 = "hello";
    string s11 = s1;
    cout<<s11<<endl;

    //s1的内容 copy buf中
	char buf1[128] = {0};
	s11.copy(buf1, 3, 0);  //注意 只给你copy3个字符 不会变成C风格的字符串,结尾没有'\0'
	cout << "buf1:" << buf1 << endl;


}

//4、string的连接: "+" 和 "append()"

int main4()
{
    string s1 = "hello";
    string s2 = " world";
    string s3 = " !";

    s1 = s1 + s2;
    cout<<s1<<endl;
    s1.append(s3);
    cout<<s1<<endl;

    return 0;
}

//5、字符串的查找与替换
int main5()
{
    string str = "hi hello hi nihao hi";

    //查找第一次出现的“hi”
    int index = str.find("hi" , 1); //从下标1开始查找,返回查找到的字符串首地址
    if(index == string::npos)
    {
        cout<<"index: "<<index<<endl;
    }
    else
    {
        cout<<"not exsit"<<endl;
    }

    //查找所有“hi”,并将“hi”改成“Hi”
    int all_index = str.find("hi",0);
    while(all_index != string::npos)
    {
        cout<<"index: "<<all_index<<endl;
        str.replace(all_index,1,"H");
        all_index++;
        all_index = str.find("hi",all_index);
    }

    cout<<"after replace: "<<str<<endl;


    return 0;
}

//6、区间删除和插入
int main()
{
    //删除
    string str = "hii hii hii";

    string::iterator it = find(str.begin(),str.end(),'i');

    if(it != str.end())
    {
        str.erase(it);
    }

    cout<<str<<endl;

    str.erase(0,3);
    cout<<str<<endl;

    str.erase(str.begin(),str.end());
    bool ret = str.empty();
    if(ret == true)
    {
        cout<<"str is empty"<<endl;
    }

    //插入
    str.insert(0,"hi");
    cout<<str<<endl;
    str.insert(str.length()," world");
    cout<<str<<endl;

    //1函数的入口地址 2函数对象 3预定义的函数对象
	transform(str.begin(), str.end(),str.begin(), ::toupper);
	cout << "str" << str << endl;



    return 0;
}

