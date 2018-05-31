/*************************************************************************
	> File Name: findString2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月31日 星期四 23时06分34秒
 ************************************************************************/

//除一个外，所有数出现了3次，求那个数

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    //法一：对每个整数以32位表示，分别统计每一位上1的个数，最后该位数上的和对3取余数；
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0; i<32; ++i){
            int sum = 0;
            for(int j=0; j<nums.size(); ++j){
                sum += (nums[j]>>i) & 1;
            }

            ret |= (sum % 3)<<i;
        }

        return ret;
    }

    //法二：
    int singleNumber2(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0; i<nums.size(); ++i){
            ones = (ones^nums[i]) & ~twos;
            twos = (twos^nums[i]) & ~ones;
        }
        return ones;
    }
};


int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(12);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);

    Solution s;
    cout<<s.singleNumber(v1)<<endl;
    cout<<s.singleNumber2(v1)<<endl;

    return 0;
}

