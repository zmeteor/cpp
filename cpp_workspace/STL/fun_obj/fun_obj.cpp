/*************************************************************************
	> File Name: fun_obj.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月16日 星期五 21时38分57秒
 ************************************************************************/

#include <iostream>
#include "string"
#include "vector"
#include "algorithm"
#include "map"
#include "list"

using namespace std;

//函数对象，重载函数调用操作符的类
template <typename T>
class showdata
{
public:
    showdata()
    {
        n = 0;
    }

    void operator()(T &t)
    {
        n++;
        cout<<t<<" ";
    }

    void print()
    {
        cout<<"调用次数："<<n<<endl;
    }
protected:
private:
    int n;
};

//函数模板
template <typename T>
void funshow(T &t)
{
    cout<<t<<" ";
}

//普通函数
void funshow2(int t)
{
    cout<<t<<" ";
}

//函数对象和普通函数的异同
void show1()
{
    /*相似：调用方式相似*/
    showdata<int> s1;
//    int a = 1;
//    s1(a);  //函数对象的调用
//    funshow<int>(a); //模板函数的调用
//    funshow2(a); //普通函数的调用

    /*不同：*/
    //函数对象是属于类对象,能突破函数的概念,能保持调用状态信息
    //函数对象的好处
    //for_each算法中, 函数对象做函数参数
    //for_each算法中, 函数对象当返回值
    vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//for_each(v1.begin(), v1.end(), showdata<int>()); //匿名函数对象 匿名仿函数
	cout << endl;
	for_each(v1.begin(), v1.end(), funshow2); //通过回调函数  谁使用for_each 谁去填写回调函数的入口地址

    cout<<endl;
	//函数对象 做函数参数
	/*
		template<class _InIt,
		class _Fn1> inline
			_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
		{	// perform function for each element
			_DEBUG_RANGE(_First, _Last);
			_DEBUG_POINTER(_Func);
			return (_For_each(_Unchecked(_First), _Unchecked(_Last), _Func));
		}
	*/
	//1 for_each算法的 函数对象的传递 是元素值传递 ,不是引用传递
	for_each(v1.begin(), v1.end(), s1);
	s1.print();

	cout << "通过for_each算法的返回值看调用的次数" << endl;
	s1 = for_each(v1.begin(), v1.end(), s1);
	s1.print();

	//结论 要点: 分清楚 stl算法返回的值是迭代器 还是 谓词（函数对象） 是stl算法入门的重要点
}

//一元谓词
class IsDiv
{
public:
    IsDiv(int div)
    {
        this->div = div;
    }
    bool operator()(int x)
    {
        return(x%div == 0);
    }
protected:
private:
    int div;
};

 /*
	template<class _InIt,
	class _Pr> inline
		_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
		_DEBUG_RANGE(_First, _Last);
		_DEBUG_POINTER(_Pred);
		return (_Rechecked(_First,
			_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
*/
void operate()
{
    IsDiv d(3);
    vector<int> v1;
    for(int i = 0 ; i < 30 ; i++)
    {
        v1.push_back(i+1);
    }

    //find_if返回值是一个迭代器
	//要点: 分清楚 stl算法返回的值是迭代器 还是 谓词（函数对象） 是stl算法入门的重要点
    vector<int>::iterator it;
    it = find_if(v1.begin() , v1.end() , d);
    if(it == v1.end())
    {
        cout<<"not find"<<endl;
    }
    while(it != v1.end())
    {
        cout<<*it<<endl;
        it = find_if(++it , v1.end() , d);
    }

}

//二元函数对象
template<typename T>
class tobj
{
public:
    T operator()(T t1 , T t2)
    {
        return t1+t2;
    }
protected:
private:
};
//二元函数对象
	/*
	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
		_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
		_DEBUG_RANGE(_First1, _Last1);
		_DEBUG_POINTER(_Dest);
		_DEBUG_POINTER(_Func);
		if (_First1 != _Last1)
			return (_Transform2(_Unchecked(_First1), _Unchecked(_Last1),
			_First2, _Dest, _Func,
			_Is_checked(_Dest)));
		return (_Dest);
	}

	//transform 把运算结果的 迭代器的开始位置 返回出来
	*/


void fun3()
{
    vector<int> v1(10,1);
    vector<int> v2(10,2);
    vector<int> v3(10);

    transform(v1.begin(),v1.end(),v2.begin(),v3.begin(), tobj<int>() );
    for_each(v3.begin(),v3.end(),funshow2);
}


//二元谓词
bool compare_num(int a,int b)
{
    return a > b;  //从大到小
}

//字符串比较函数
struct CompareNoCase
{
	bool operator()(const string &str1, const string &str2)
	{
		string str1_ ;
		str1_.resize(str1.size() );
		transform(str1.begin(), str1.end(), str1_.begin(), ::tolower ); //预定义函数对象

		string str2_ ;
		str2_.resize(str2.size() );
		transform(str2.begin(), str2.end(), str2_.begin(), ::tolower ); //预定义函数对象

		return (str1_ < str2_); // 从小到大进行排序
	}
};
void fun4()
{
    //数值排序
    vector<int> v1;
    for(int i = 0 ; i < 10 ; i++)
    {
        int temp = rand()%100;
        v1.push_back(temp);
    }

    cout<<"before sort"<<endl;
    for_each(v1.begin(),v1.end(),funshow2);
    cout<<endl;
    sort(v1.begin(),v1.end(),compare_num);

    cout<<"after sort"<<endl;
    for_each(v1.begin(),v1.end(),funshow2);
    cout<<endl;


    //字符串排序
    vector<string> v2;
    v2.push_back("safag");
    v2.push_back("sogdofd");
    v2.push_back("ghdofd");
    v2.push_back("agdofd");

    cout<<"before sort"<<endl;
    //for_each(v2.begin(),v2.end(),funshow2);

    for(vector<string>::iterator it = v2.begin() ; it != v2.end();it++)
    {
        cout<<*it<<endl;
    }
    cout<<endl;
    sort(v2.begin(),v2.end(),CompareNoCase());
    for(vector<string>::iterator it = v2.begin() ; it != v2.end();it++)
    {
        cout<<*it<<endl;
    }
}
int main()
{
    //show1(); //一元函数对象

    //operate(); //一元谓词

    //fun3(); //二元函数对象

    fun4(); //二元谓词


    return 0;
}

