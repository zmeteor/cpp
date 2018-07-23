/*************************************************************************
	> File Name: theNumOfOne2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 20时55分44秒
 ************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);
int solution2(int n);



int main()
{
    int result = solution2(15);

    cout<<result<<endl;

    return 0;
}

int solution2(int n)
{
      if(n <= 0)
      {
          return 0;
      }

      char strN[50];
      sprintf(strN, "%d", n);

      return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
      if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
      {
          return 0;
      }

      int firstDigit = *strN - '0';
      unsigned int length = static_cast<unsigned int>(strlen(strN));

      if(length == 1 && firstDigit == 0)
            return 0;

      if(length == 1 && firstDigit > 0)
            return 1;

      int numFirstDigit = 0;
      int numOtherDigits = firstDigit * (length - 1) * PowerBase10(length - 2);
      int numRecursive = NumberOf1(strN + 1);

      if(firstDigit > 1)
      {
            numFirstDigit = PowerBase10(length - 1);
      }
      else if(firstDigit == 1)
      {
            numFirstDigit = atoi(strN + 1) + 1;
      }

      return numFirstDigit + numOtherDigits + numRecursive;
}

// 计算 10^n
int PowerBase10(unsigned int n)
{
      int result = 1;
      for(unsigned int i = 0; i < n; ++ i)
      {
            result *= 10;
      }

      return result;
}
