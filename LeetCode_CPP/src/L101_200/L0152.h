
#pragma once

#include "../Head.h"

namespace L0152
{


/// https://leetcode.com/problems/maximum-product-subarray/
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        const int Length = nums.size();

        int ret = nums[0];
        for (int i = 1, imax = ret, imin = ret; i < Length; ++i)
        {
            int max = imax, min = imin;
            imax = (std::max)((std::max)(nums[i], max*nums[i]), min*nums[i]);
            imin = (std::min)((std::min)(nums[i], max*nums[i]), min*nums[i]);
            ret = (std::max)(ret, imax);
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 3, -2, 4};
        Print(maxProduct(test));
    }
#endif /// DEBUG
};


}