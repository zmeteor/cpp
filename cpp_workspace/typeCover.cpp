/*************************************************************************
	> File Name: typeCover.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月26日 星期六 21时09分39秒
 ************************************************************************/
#include <iostream>

using namespace std;

//静态类型转换，c++编译器在编译的时候进行类型检查
//c语言中 隐式类型转换的地方 均可使用 static_cast<>() 进行类型转换
int main1()
{
    double b=10.25;

    int a = static_cast<int>(b);  //static_cast
    char c = 'a';
    int d = static_cast<int>(c);

    cout<<a<<endl;
    cout<<d<<endl;

    return 0;
}

//reinterpret_cast<>()  重新解释类型，进行强行类型转换
int main2()
{
    int a = 0;
    int *p = &a;
    //char*q = static_cast<char *>(p);   //error: static_cast, 编译器编译时,会做类型检查 若有错误 提示错误

    char* q = reinterpret_cast<char *>(p); //reinterpret_cast<>() 强制类型转换

    cout<<p<<endl;
    cout<<q<<endl;
}


//dynamic_cast		命名上理解是动态类型转换。如子类和父类之间的多态类型转换。
//运行时类型识别
class Human
{
public:
    virtual void print() = 0;
protected:
private:
};


class Teacher:public Human
{
public:
    virtual void print()
    {
        cout<<"i am a teacher"<<endl;
    }

    void job()
    {
        cout<<"teach student"<<endl;
    }

protected:
private:
};

class Student: public Human
{
public:
    virtual void print()
    {
        cout<<"i am a student"<<endl;
    }

    void dothing()
    {
        cout<<"study"<<endl;
    }

protected:
private:
};

void playobj(Human *p)
{
    p->print();

    Teacher *q = dynamic_cast<Teacher *>(p);  //dynamic_cast<>() 执行失败返回 NULL
    if(q != NULL)
    {
        q->job();
    }

    Student *s = dynamic_cast<Student *>(p);
    if(s != NULL)
    {
        s->dothing();
    }
}

int main3()
{
    //Human *h =NULL;

    Teacher t1;
    Student s1;
    playobj(&t1);
    playobj(&s1);


    Teacher *p = &t1;
    Student *q = &s1;

    /*OK*/
    //Human *h = static_cast<Human *>(p);
   // Human *h = reinterpret_cast<Human *>(p);
   //Human *h = dynamic_cast<Human *>(p);

   //Teacher *temp = static_cast<Teacher *>(q);  //error
   //Teacher *temp = reinterpret_cast<Teacher *>(q);
   //Teacher * temp = dynamic_cast<Teacher *>(q);

    return 0;
}


//const_cast()  去const属性

void printBuf(const char *  p)
{
	char *p1 = NULL;
	p1 = const_cast<char *>(p);     //把只读属性 去掉

	p1[0] = 'Z' ;
	cout << p << endl;
}

int  main()
{
	const char buf[] = "aaaaaaaaaaa";

	//char *myp = "aaaaaaaaaa";

	//要确保 p所指向的内存空间 确实能修改 ,如果不能修改会带来灾难性后果
	printBuf (buf);

	//printBuf (myp); //error

	return 0;
}




