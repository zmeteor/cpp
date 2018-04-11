/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月16日 星期五 17时32分58秒
 ************************************************************************/


//map的基本操作

#include <iostream>
#include <map>
#include <string>

using namespace std;

//map的基本操作
int main1()
{

    map<int ,string> m1;

    /*插入*/
    //1、pair
    m1.insert(pair<int , string>(1,"test1"));
    m1.insert(pair<int , string>(2,"test2"));

    //2、make_pair
    m1.insert(make_pair(3,"test3"));
    m1.insert(make_pair(4,"test4"));

    //3、value_type
    m1.insert(map<int , string>::value_type(5,"test5"));
    m1.insert(map<int , string>::value_type(6,"test6"));

    //4、[]
    m1[7] = "test7";
    m1[8] = "test8";


    /*遍历*/
    for(map<int ,string>::iterator it = m1.begin() ; it != m1.end(); it++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }

    /*删除*/

    //删除容器中key为8的对组。
    m1.erase(8);
    //m1.erase(m1.begin() + 5,m1.end()); //error

    //范围删除
    map<int ,string>::iterator it = m1.begin() ;
    it++;
    it++;
    m1.erase(it,m1.end());

    cout<<endl<<"after erase"<<endl;
    for(map<int ,string>::iterator it = m1.begin() ; it != m1.end(); it++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }

    return 0;
}

//插入的四种方法 异同
//前三种方法 返回值为pair<iterator,bool>	若key已经存在 则报错
//方法四									若key已经存在,则修改
int  main2()
{
     map<int ,string> m1;

    /*插入*/
    //1、pair
    pair<map<int , string>::iterator , bool> ret1 = m1.insert(pair<int , string>(1,"test1"));
    pair<map<int , string>::iterator , bool> ret11 = m1.insert(pair<int , string>(1,"test1"));

    if(ret11.second == true)
    {
        cout<<"insert 2 success"<<ret11.first->first<<"\t"<<ret11.first->second<<endl;
    }
    else
    {
        cout<<"insert 2 fail"<<endl;
    }

    //2、make_pair
     pair<map<int , string>::iterator , bool > ret2 = m1.insert(make_pair(3,"test3"));

    //3、value_type
     pair<map<int , string>::iterator , bool > ret3 = m1.insert(map<int , string>::value_type(5,"test5"));

    //4、[]
    m1[7] = "test7";
    m1[7] = "tttt";
    m1[7] = "xxxx";  //会将之前的覆盖掉


    /*遍历*/
    for(map<int ,string>::iterator it = m1.begin() ; it != m1.end(); it++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }

    return 0;

}

//3、find的异常处理
int main()
{
    map<int ,string> m1;

    /*插入*/
    m1.insert(pair<int , string>(1,"test1"));
    m1.insert(pair<int , string>(2,"test2"));
//    m1.insert(pair<int , string>(3,"test3"));
//    m1.insert(pair<int , string>(4,"test3"));

    map<int , string>::iterator it = m1.find(3);
    if(it == m1.end())
    {
        cout<<"not find"<<endl;
    }
    else
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }

    //equal_range 返回两个迭代器，第一个指向>=2的第一个元素 ， 第二个指向>2的第一个元素
    pair<map<int ,string>::iterator , map<int ,string>::iterator> p = m1.equal_range(2);
    //第一个指向>=2的第一个元素
    if(p.first == m1.end())
    {
        cout<<"not find"<<endl;
    }
    else
    {
        cout<<p.first->first<<"\t"<<p.first->second<<endl;
    }

    //第二个指向>2的第一个元素
    if(p.second == m1.end())
    {
        cout<<"not find"<<endl;
    }
    else
    {
        cout<<p.second->first<<"\t"<<p.second->second<<endl;
    }
    return 0;
}

