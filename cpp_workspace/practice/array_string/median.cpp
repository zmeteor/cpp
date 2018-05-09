/*************************************************************************
	> File Name: median.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 20时39分32秒
 ************************************************************************/

//求数组的中位数

#include <iostream>
#include "vector"

using namespace std;

class Solution
{
public:
    int median(vector<int> &nums)
    {
        if (nums.empty()) 
        {
            return 0;
        }

        int len = nums.size();
        return helper(nums, 0, len - 1, (len + 1) / 2);
    }

private:
    int helper(vector<int> &nums, int l, int u, int size)   //利用快排的思想
    {
        int m = l;
        for (int i = l + 1; i <= u; ++i)
        {
            if (nums[i] < nums[l])
            {
                ++m;
                int temp = nums[i];
                nums[i] = nums[m];
                nums[m] = temp;
            }
        }

        //交换分割点
        int temp = nums[m];
        nums[m] = nums[l];
        nums[l] = temp;

        if (m - l + 1 == size)
        {
            return nums[m];
        }
        else if (m - l + 1 > size)
        {
            return helper(nums, l, m - 1, size);
        }
        else
        {
            return helper(nums, m + 1, u, size - (m - l + 1));
        }
    }
};

int main()
{
    Solution s;
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    cout << s.median(v1);

    return 0;
}

