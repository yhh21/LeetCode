
#pragma once

#include "../Head.h"

namespace L0137
{


/// https://leetcode.com/problems/single-number-ii/
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;

        const int Length = nums.size();

        for (int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for (int j = 0; j < Length; ++j)
            {
                if ((nums[j] >> i) & 1)
                {
                    ++sum;
                }
            }

            if (sum % 3 == 1)
            {
                ret |= 1 << i;
            }
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {0, 1, 0, 1, 0, 1, 99};
        Print(singleNumber(test));
    }
#endif /// DEBUG
};


}