/*************************************************************************
	> File Name: testvect.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月12日 星期一 21时40分52秒
 ************************************************************************/

//测试vector容器的功能

#include<iostream>
#include<vector>

using namespace std;

typedef vector <int> INTVECTOR;

int main()
{
    cout<<"****test make vector****"<<endl<<endl;
    INTVECTOR vec1;  //初始化vec1对象为空
    INTVECTOR vec2(10,6); //初始化vec2对象为10个6
    INTVECTOR vec3(vec2.begin() ,vec2.begin() + 3);   //拷贝构造

    INTVECTOR::iterator i;  //声明一个名为i的双向迭代器
    
    /*显示vec1中的数据*/
    cout<<"vec1.begin to vec1.end:"<<endl;
    for(i = vec1.begin() ;i != vec1.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    /*显示vec2中的数据*/
    cout<<"vec2.begin to vec2.end:"<<endl;
    for(i = vec2.begin() ;i != vec2.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    /*显示vec3中的数据*/
    cout<<"vec3.begin to vec3.end:"<<endl;
    for(i = vec3.begin() ;i != vec3.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    cout<<endl<<"****test add and del****"<<endl<<endl;

    /*添加和插入*/
    vec1.push_back(1); //只能尾部添加
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.insert(vec1.begin(),9);  //向vec1的第一个位置插入9
    vec1.insert(vec1.begin()+1,vec2.begin(),vec2.end());//向vec1的第一个位置之后插入vec2

    /*显示vec1中的数据*/
    cout<<"vec1 after add and insert:"<<endl;
    for(i = vec1.begin() ;i != vec1.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    cout<<endl<<"****test assign****"<<endl<<endl;
    /*测试赋值成员函数*/
    vec2.assign(5,1);  //将vec2的前五个数值赋值为1

    /*显示vec2中的数据*/
    cout<<"vec2 after assign:"<<endl;
    for(i = vec2.begin() ;i != vec2.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    cout<<endl<<"****test function****"<<endl<<endl;
    /*测试引用类函数*/
    cout<<"vec1.front = "<<vec1.front()<<endl; //vec1的第0个元素
    cout<<"vec1.back = "<<vec1.back()<<endl; //vec1的最后一个元素
    cout<<"vec1.at(4) = "<<vec1.at(4)<<"  "<<"vec1[4] = "<<vec1[4]<<endl; //vec1的第五个元素

    cout<<endl<<"****test pop and del****"<<endl<<endl;
    /*测试移出和删除*/
    vec1.pop_back(); //将vec1的最后一个元素移出
    vec1.erase(vec1.begin()+1,vec1.end()-2);  //删除vec1[1]~end-2

    /*显示vec1中的数据*/
    cout<<"vec1 after pop last and del 1~end-2:"<<endl;
    for(i = vec1.begin() ;i != vec1.end() ;++i)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;

    cout<<endl<<"****test size and emempty****"<<endl<<endl;
    cout<<"vec1 size ="<<vec1.size()<<endl;  //打印vec1的成员个数
    if(vec1.empty()) //测试vec1是否为空
    {
        cout<<"empty"<<endl;
    }
    vec1.clear();  //清空vec1
    cout<<"vec1 after clear"<<endl;

    if(vec1.empty()) //测试vec1是否为空
    {
        cout<<"vec1 is empty"<<endl;
    }




    return 0;
}
