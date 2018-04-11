/*************************************************************************
	> File Name: set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月16日 星期五 13时30分30秒
 ************************************************************************/
#include <iostream>
#include "set"
using namespace std;

//set的基本操作
int main1()
{
    set<int> s1;   //==set<int , less<int>> s1  默认从小到大
    set<int , greater <int> > s2;  //从大到小

    for(int i = 0; i < 10 ; i++)
    {
        s2.insert(i+1);
    }

    for(set<int , greater<int> >::iterator it = s2.begin() ; it != s2.end() ; it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}

//自定义类型的排序

class Student
{
public:
    Student(string name , int age)
    {
        this->name = name;
        this->age = age;
    }

    int getage () const
    {
        return age;
    }
    string getname() const
    {
        return name;
    }
protected:
private:
    string name;
    int age;
};

//仿函数
struct fun
{
    bool operator()(const Student &s1,const Student &s2)
    {
        return ( s1.getage() < s2.getage() );  //从小到大排序
    }
};

int main2()
{
    Student s1("tom",19);
    Student s2("jim",9);
    Student s3("rose",29);
    Student s4("jack",20);
    Student s5("yoyo",20);

    set<Student , fun> set1;
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
    set1.insert(s5); //error 插入失败，不允许重复的元素

    for(set<Student , fun>::iterator it = set1.begin() ; it != set1.end() ; it++)
    {
        cout<<"name: "<<it->getname()<<"\tage: "<<it->getage()<<endl;
    }

    //typedef pair<iterator, bool> _Pairib;  判断insert的返回值
    pair<set<Student , fun>::iterator , bool> p = set1.insert(s5);
   // set<Student , fun>::iterator it = p.first;
    if(p.second == true)
    {
        cout<<"insert success!"<<endl;
    }
    else
    {
        cout<<"insert fail!"<<endl;
    }

    return 0;
}

//find查找  equal_range
//返回结果是一个pair:对组
int main3()
{
	set<int> set1;

	for (int i=0; i<10; i++)
	{
		set1.insert(i+1);
	}

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++  )
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 =  set1.find(5);
	cout << "it0:" << *it0 << endl;

	int num1 = set1.count(5);
	cout << "num1:" << num1 << endl;

	set<int>::iterator it1 =   set1.lower_bound(5); // 大于等于5的元素 的 迭代器的位置
	cout << "it1:" << *it1 << endl;

	set<int>::iterator it2 =   set1.lower_bound(5); // 大于5的元素 的 迭代器的位置
	cout << "it2:" << *it2 << endl;

	//
	//typedef pair<iterator, bool> _Pairib;
	//typedef pair<iterator, iterator> _Pairii;
	//typedef pair<const_iterator, const_iterator> _Paircc;

	set1.erase(5);  //把5元素删除掉
	pair<set<int>::iterator, set<int>::iterator>  mypair = set1.equal_range(5);
	set<int>::iterator it3 = mypair.first;
	cout << "it3:" << *it3 << endl;  //5  //6

	set<int>::iterator it4 =  mypair.second;
	cout << "it4:" << *it4 << endl;  //6  //6

}

//multiset
int main()
{
	multiset<int> set1;
	int tmp = 0;

	cin>>tmp;
	while (tmp != 0)
	{
		set1.insert(tmp);
		cin>>tmp;
	}

	//遍历
	for (multiset<int>::iterator it=set1.begin(); it!=set1.end(); it++ )
	{
		cout << *it << " ";
	}
	cout << endl;

	while (!set1.empty())
	{
		multiset<int>::iterator it = set1.begin();
		cout << *it << " ";
		set1.erase(it);
	}

	return 0;
}
