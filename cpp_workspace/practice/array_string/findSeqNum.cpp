/*************************************************************************
	> File Name: findSeqNum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 20时36分45秒
 ************************************************************************/
/*问题*/
//在一个整数数组中任意一组相邻的两个数字都是连续的（两个数字的差的绝对值为1）
//请设计一个算法在数组中查找给定的数字并返回它的下标。如果该数字出现多次，则返回它第一次出现的下标。
//例如，数字9在数组{4, 5, 6, 5, 6, 7, 8, 9, 10, 9}中出现两次，我们需要返回它的第一个下标7。

/*思路*/
//利用数组中任意一组相邻的两个数子是连续的这一特点
//遍历到当前元素时，计算于目标值差的绝对值，作为向右移动的step
//因为，若是递增，则目标在当前位置+step的位置上
//若递减，则目标在当前位置+step之后的位置

#include <iostream>

using namespace std;

int findFirNum(int *num , int len , int target)
{
    if(num == NULL)
    {
        return -1;
    }
    int index = 0;
    while(index < len && num[index] != target)
    {
        int step = target -num[index];
        index += step > 0 ? step : -step;
    }

    if(index < len)
    {
        return index;
    }

    return -1;
}

int main()
{
    int num[9] = {5,4,5,6,7,8,9,8,9};
    int index = findFirNum(num , 9 , 9);

    if(index)
    {
        cout<<"find and index = "<<index<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }

    return 0;
}

