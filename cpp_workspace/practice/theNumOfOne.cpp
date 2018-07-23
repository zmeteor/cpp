/*************************************************************************
	> File Name: theNumOfOne.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 20时18分16秒
 ************************************************************************/
//题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。

//例如输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <iostream>

using namespace std;


int NumberOf1(unsigned int n)
{
      int number = 0;
      while(n)
      {
            if(n % 10 == 1)
                  number ++;

            n = n / 10;
      }

      return number;
}

int solution1(unsigned int n)
{
      int number = 0;

      for(unsigned int i = 1; i <= n; ++ i)
            number += NumberOf1(i);

      return number;
}



int main()
{
    int result = solution1(15);

    cout<<result<<endl;

    return 0;
}

