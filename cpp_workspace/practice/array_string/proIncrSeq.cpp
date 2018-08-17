/*************************************************************************
	> File Name: proIncrSeq.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月17日 星期五 21时49分30秒
 ************************************************************************/
/* 给定两个长度相同的数组A和B，交换两个数组中下标相同的两个数字A[i]和B[i]。
 * 假设输入的两个数组在交换若干次之后，一定能变成严格递增的数组。
 * 输入两个数组，请问至少需要交换多少次使得两个数组都变成严格递增的？
 *
 * 例如，输入数组A = [1, 3, 5, 4]，B = [1, 2, 3, 7]。
 * 如果交换A[3]和B[3]，得到A = [1, 3, 5, 7]，B = [1, 2, 3, 4]，此时两个数组都是严格递增的。
 * 因此输出是1。
 *
 */
#include <iostream>

using namespace std;

int Solution(int a[] , int b[] , int lena , int lenb)
{
    int count1 = 0;
    int count2 = 0;


    for(int i = 1 ; i < lena ; i++)
    {
        if(a[i] <= a[i - 1] || b[i] <= b[i - 1])
        {
            int temp1 = count2;
            int temp2 = count1 + 1;
            count1 = temp1;
            count2 = temp2;
        }
        else if(a[i] <= b[i - 1] || b[i] <= a[i - 1])
        {
            count2 += 1;
        }
        else
        {
            int temp1 = min(count1 , count2);
            int temp2 = min(count1 , count2) + 1;
            count1 = temp1;
            count2 = temp2;
        }
    }


    return min(count1 , count2);
}

int main()
{
    int a[4] = {1,3,5,4};
    int b[4] = {1,2,3,7};


    int lena = sizeof(a) / sizeof(a[0]);
    int lenb = sizeof(b) / sizeof(b[0]);

    int result = Solution(a,b,lena,lenb);

    cout<<result<<endl;

    return 0;
}

