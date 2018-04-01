/*************************************************************************
	> File Name: test_fun.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31 星期六 20时31分47秒
 ************************************************************************/

/*
    在c++中，更强调类型，任何程序的元素都必须指明类型     f () ; //error
    int f(); 和 int f(void)都表示返回值为int的无参函数
*/
#include <stdio.h>
#include <stdlib.h>


f(i)   //默认返回值为int，默认形参为int,数量不限
{
    printf("%f\n", i);
    return i;
}

int g()   //任意参数类型
{
    return 5;
}

int main()
{
    printf("%d\n",20.5); //0
    float ret = f(20.5, 30); //输出0  
    //float ret =f('a','b');  //默认第一个参数
    //float ret = f("asd");  //参数类型不限

    printf("%f\n", ret);

    printf("g() = %d\n", g("ads"));

    return 0;
}
